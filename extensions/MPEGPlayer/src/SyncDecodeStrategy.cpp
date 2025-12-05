#include "SyncDecodeStrategy.h"
#include "Utils.h"
#include "pl_mpeg.h"

namespace mpeg
{

SyncDecodeStrategy::SyncDecodeStrategy() : m_fs(nullptr), m_plm(nullptr), m_frame(nullptr) {}

SyncDecodeStrategy::~SyncDecodeStrategy()
{
    if (m_plm)
    {
        plm_destroy(m_plm);
        m_plm = nullptr;
    }
    AX_SAFE_DELETE(m_fs);
}

bool SyncDecodeStrategy::initialize(const std::string& filename)
{
    auto result = new_plm_from_file(filename);
    m_plm       = std::get<0>(result);
    m_fs        = std::get<1>(result);

    if (m_plm == nullptr)
        return false;

    plm_set_audio_enabled(m_plm, 0);
    plm_set_video_decode_callback(m_plm, [](plm_t* mpeg, plm_frame_t* frame, void* user) -> void {
        auto* self          = static_cast<SyncDecodeStrategy*>(user);
        self->m_frame.frame = frame;
    }, this);

    return true;
}

VideoFrame* SyncDecodeStrategy::decode(double dt)
{
    if (m_plm == nullptr)
    {
        return nullptr;
    }
    m_frame.frame = nullptr;
    plm_decode(m_plm, static_cast<double>(dt));
    return &m_frame;
}

bool SyncDecodeStrategy::seekTo(double time_sec)
{
    if (m_plm)
        return !!plm_seek(m_plm, time_sec, 0);
    else
        return false;
}

void SyncDecodeStrategy::setLooping(bool looping)
{
    if (m_plm)
        plm_set_loop(m_plm, looping ? 1 : 0);
}

bool SyncDecodeStrategy::isLooping() const
{
    if (m_plm)
        return plm_get_loop(m_plm) != 0;
    else
        return false;
}

double SyncDecodeStrategy::getDuration() const
{
    if (m_plm)
        return plm_get_duration(m_plm);
    else
        return 0.0;
}
double SyncDecodeStrategy::getCurrentTime() const
{
    if (m_plm)
        return plm_get_time(m_plm);
    else
        return 0.0;
}

int SyncDecodeStrategy::getVideoWidth() const
{
    if (m_plm)
        return plm_get_width(m_plm);
    else
        return 0;
}
int SyncDecodeStrategy::getVideoHeight() const
{
    if (m_plm)
        return plm_get_height(m_plm);
    else
        return 0;
}
}  // namespace mpeg
