#include "SyncDecodeStrategy.h"
#include "Utils.h"
#include "pl_mpeg.h"

namespace mpeg
{

SyncDecodeStrategy::SyncDecodeStrategy()
    : m_fs(nullptr)
    , m_plm(nullptr)
    , m_audioPlayer(nullptr)
    , m_samplerate(0)
    , m_volume(1.0f)
{}

SyncDecodeStrategy::~SyncDecodeStrategy()
{
    AX_SAFE_DELETE(m_audioPlayer);
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

    m_samplerate = plm_get_samplerate(m_plm);

    plm_set_video_decode_callback(m_plm, [](plm_t* plm, plm_frame_t* frame, void* user) -> void {
        auto* self          = static_cast<SyncDecodeStrategy*>(user);
        self->m_frame.frame = frame;
    }, this);
    plm_set_audio_decode_callback(m_plm, [](plm_t* plm, plm_samples_t* samples, void* user) -> void {}, nullptr);
    
	plm_set_audio_stream(m_plm, 0);
    if (plm_get_num_audio_streams(m_plm) > 0)
    {
        // Adjust the audio lead time according to the audio_spec buffer size
        plm_set_audio_lead_time(m_plm, (double)4096 / (double)m_samplerate);
    }

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

void SyncDecodeStrategy::start()
{
    if (m_plm && plm_get_audio_enabled(m_plm))
    {
        assert(!m_audioPlayer);
        m_audioPlayer = new AudioStreamPlayer(m_samplerate, 2);
        m_audioPlayer->setVolume(m_volume);

        plm_set_audio_decode_callback(m_plm, [](plm_t* plm, plm_samples_t* samples, void* user) -> void {
            auto* player = (AudioStreamPlayer*)user;
            player->pushFrame(samples->interleaved, samples->count);
        }, m_audioPlayer);
    }
}

void SyncDecodeStrategy::stop()
{
    if (m_audioPlayer)
    {
        m_audioPlayer->clearBuffers();
    }
}

void SyncDecodeStrategy::pause()
{
    if (m_audioPlayer)
    {
        m_audioPlayer->pause();
    }
}

void SyncDecodeStrategy::resume()
{
    if (m_audioPlayer)
    {
        m_audioPlayer->resume();
    }
}

bool SyncDecodeStrategy::seekTo(double time_sec)
{
    if (m_audioPlayer)
    {
        m_audioPlayer->clearBuffers();
    }
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

void SyncDecodeStrategy::setAudioEnabled(bool enabled)
{
    if (m_plm)
        plm_set_audio_enabled(m_plm, enabled ? 1 : 0);
}

void SyncDecodeStrategy::setVideoEnabled(bool enabled)
{
    if (m_plm)
        plm_set_video_enabled(m_plm, enabled ? 1 : 0);
}

void SyncDecodeStrategy::setVolume(float volume)
{
    if (m_audioPlayer)
        m_audioPlayer->setVolume(volume);
    else
        m_volume = volume;
}

}  // namespace mpeg
