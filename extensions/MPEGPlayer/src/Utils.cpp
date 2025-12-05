#define PL_MPEG_IMPLEMENTATION
#define PLM_NO_STDIO
#include "pl_mpeg.h"
#include "Utils.h"

using namespace ax;

namespace mpeg
{
std::tuple<plm_t*, ax::IFileStream*> new_plm_from_file(const std::string& filename)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto fs    = FileUtils::getInstance()->openFileStream(filename, IFileStream::Mode::READ);
    if (!fs)
    {
        AXLOGE("Failed to open file: {}", filename);
        return {nullptr, nullptr};
    }

    const auto size = static_cast<size_t>(fs->size());
    auto fsptr      = fs.release();

    plm_buffer_t* plm_buffer = plm_buffer_create_with_callbacks(
        /*load_callback*/
        [](plm_buffer_t* self, void* user) -> void {
        if (self->discard_read_bytes)
        {
            plm_buffer_discard_read_bytes(self);
        }

        size_t bytes_available = self->capacity - self->length;
        auto stream            = static_cast<IFileStream*>(user);
        auto bytes_read =
            static_cast<size_t>(stream->read(self->bytes + self->length, static_cast<unsigned int>(bytes_available)));
        self->length += bytes_read;

        if (bytes_read == 0)
        {
            self->has_ended = TRUE;
        }
    },
        /*seek_callback*/
        [](plm_buffer_t* self, size_t offset, void* user) -> void {
        IFileStream* stream = static_cast<IFileStream*>(user);
        stream->seek(static_cast<int64_t>(offset), SEEK_SET);
    },
        /*tell_callback*/
        [](plm_buffer_t* self, void* user) -> size_t {
        IFileStream* stream = static_cast<IFileStream*>(user);
        return static_cast<size_t>(stream->tell());
    }, size, fsptr);

    if (!plm_buffer)
    {
        AX_SAFE_DELETE(fsptr);
        return {nullptr, nullptr};
    }

    plm_t* plm = plm_create_with_buffer(plm_buffer, 1);
    if (!plm_probe(plm, 5000 * 1024))
    {
        AXLOGE("No MPEG video or audio streams found in {}", filename);
        AX_SAFE_DELETE(fsptr);
        plm_destroy(plm);
        return {nullptr, nullptr};
    }

    auto end      = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    AXLOGI("Opened {} - framerate: {}, samplerate: {}, duration: {}, time-consuming: {}ms", filename,
           plm_get_framerate(plm), plm_get_samplerate(plm), plm_get_duration(plm), duration.count() / 1000.0);

    return {plm, fsptr};
}

}  // namespace mpeg
