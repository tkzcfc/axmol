#include "MPEGPlayer.h"
#include "SyncDecodeStrategy.h"
#include "AsyncDecodeStrategy.h"

namespace ax
{
MPEGPlayer::MPEGPlayer()
    : m_decoder(nullptr)
    , m_texture_y(nullptr)
    , m_texture_cb(nullptr)
    , m_texture_cr(nullptr)
    , m_isPasued(false)
    , m_audioEnabled(false)
    , m_videoEnabled(true)
    , m_useAsyncDecoding(true)
    , m_volume(1.0f)
{}

MPEGPlayer::~MPEGPlayer()
{
    AX_SAFE_RELEASE_NULL(m_texture_y);
    AX_SAFE_RELEASE_NULL(m_texture_cb);
    AX_SAFE_RELEASE_NULL(m_texture_cr);
    m_decoder = nullptr;
}

MPEGPlayer* MPEGPlayer::create()
{
    MPEGPlayer* mpeg = new MPEGPlayer();
    if (mpeg && mpeg->init())
    {
        mpeg->autorelease();
        return mpeg;
    }
    AX_SAFE_DELETE(mpeg);
    return nullptr;
}

bool MPEGPlayer::init()
{
    if (!Sprite::init())
        return false;
    this->setAutoUpdatePS(false);
    return true;
}

void MPEGPlayer::setVideoFile(const std::string& filename)
{
    m_videoFile = filename;
}

const std::string MPEGPlayer::getVideoFile() const
{
    return m_videoFile;
}

void MPEGPlayer::setUseAsyncDecoding(bool useAsyncDecoding)
{
    m_useAsyncDecoding = useAsyncDecoding;
}

bool MPEGPlayer::isUseAsyncDecoding() const
{
    return m_useAsyncDecoding;
}

int MPEGPlayer::getVideoWidth() const
{
    if (m_decoder)
        return m_decoder->getVideoWidth();
    else
        return 0;
}

int MPEGPlayer::getVideoHeight() const
{
    if (m_decoder)
        return m_decoder->getVideoHeight();
    else
        return 0;
}

bool MPEGPlayer::play()
{
    if (m_decoder)
        return true;

    AX_SAFE_RELEASE_NULL(m_texture_y);
    AX_SAFE_RELEASE_NULL(m_texture_cb);
    AX_SAFE_RELEASE_NULL(m_texture_cr);

    if (m_useAsyncDecoding)
        m_decoder = std::make_unique<mpeg::AsyncDecodeStrategy>();
    else
        m_decoder = std::make_unique<mpeg::SyncDecodeStrategy>();

    if (!m_decoder || !m_decoder->initialize(m_videoFile))
    {
        m_decoder = nullptr;
        return false;
    }

    m_decoder->setAudioEnabled(m_audioEnabled);
    m_decoder->setVideoEnabled(m_videoEnabled);
    m_decoder->setVolume(m_volume);
    m_decoder->start();

    this->setContentSize(
        Size(static_cast<float>(m_decoder->getVideoWidth()), static_cast<float>(m_decoder->getVideoHeight())));
    this->scheduleUpdate();

    return false;
}

void MPEGPlayer::stop()
{
    m_decoder = nullptr;
}

void MPEGPlayer::pause()
{
    pausePlayback();
    Sprite::pause();
}

void MPEGPlayer::resume()
{
    resumePlayback();
    Sprite::resume();
}

void MPEGPlayer::pausePlayback()
{
    m_isPasued = true;
}

void MPEGPlayer::resumePlayback()
{
    m_isPasued = false;
}

void MPEGPlayer::seekTo(double sec)
{
    if (m_decoder)
    {
        if (std::abs(m_decoder->getCurrentTime() - sec) < 0.01)
        {
            return;
        }
        m_decoder->seekTo(std::clamp(sec, .0, m_decoder->getDuration()));
    }
}

double MPEGPlayer::getCurrentTime()
{
    if (m_decoder)
        return m_decoder->getCurrentTime();
    else
        return .0;
}

double MPEGPlayer::getDuration()
{
    if (m_decoder)
        return m_decoder->getDuration();
    else
        return .0;
}

bool MPEGPlayer::isPlaying() const
{
    return !m_isPasued;
}

void MPEGPlayer::setLooping(bool looping)
{
    if (m_decoder)
    {
        m_decoder->setLooping(looping);
    }
}

bool MPEGPlayer::isLooping() const
{
    if (m_decoder)
    {
        return m_decoder->isLooping();
    }
    else
    {
        return false;
    }
}

void MPEGPlayer::setAudioEnabled(bool enabled)
{
    if (m_decoder)
    {
        return;
    }
    m_audioEnabled = enabled;
}

bool MPEGPlayer::isAudioEnabled() const
{
    return m_audioEnabled;
}

void MPEGPlayer::setVideoEnabled(bool enabled)
{
    if (m_decoder)
    {
        return;
    }
    m_videoEnabled = enabled;
}

bool MPEGPlayer::isVideoEnabled() const
{
    return m_videoEnabled;
}

void MPEGPlayer::setVolume(float volume)
{
    m_volume = std::clamp(volume, 0.0f, 1.0f);
    if (m_decoder)
        m_decoder->setVolume(m_volume);
}

float MPEGPlayer::getVolume() const
{
    return m_volume;
}

void MPEGPlayer::update(float dt)
{
    Sprite::update(dt);

    if (m_decoder == nullptr || m_isPasued)
        return;

    auto videoFrame = m_decoder->decode(static_cast<double>(dt));
    if (videoFrame == nullptr)
        return;

    auto frame = videoFrame->frame;
    if (frame)
    {
        bool dirty = m_texture_y == nullptr;
        if (dirty)
        {
            m_texture_y = new Texture2D();
            m_texture_y->setAliasTexParameters();

            m_texture_cb = new Texture2D();
            m_texture_cb->setAliasTexParameters();

            m_texture_cr = new Texture2D();
            m_texture_cr->setAliasTexParameters();

            auto program =
                ProgramManager::getInstance()->loadProgram(positionTextureColor_vert, "custom/videoTextureYCRCB_fs");
            auto ps = new ProgramState(program);
            ps->setTexture(ps->getUniformLocation("u_tex1"), 1, m_texture_cb->getBackendTexture());
            ps->setTexture(ps->getUniformLocation("u_tex2"), 2, m_texture_cr->getBackendTexture());

            this->setProgramState(ps, true);
        }

        m_texture_y->updateWithData(frame->y.data, frame->y.width * frame->y.height, backend::PixelFormat::R8,
                                    backend::PixelFormat::R8, frame->y.width, frame->y.height, false, 0);

        m_texture_cb->updateWithData(frame->cb.data, frame->cb.width * frame->cb.height, backend::PixelFormat::R8,
                                     backend::PixelFormat::R8, frame->cb.width, frame->cb.height, false, 0);

        m_texture_cr->updateWithData(frame->cr.data, frame->cr.width * frame->cr.height, backend::PixelFormat::R8,
                                     backend::PixelFormat::R8, frame->cr.width, frame->cr.height, false, 0);

        if (dirty)
        {
            this->setTexture(this->m_texture_y);
            this->setTextureRect(ax::Rect{Vec2::ZERO, Vec2{
                                                          (float)frame->width,
                                                          (float)frame->height,
                                                      }});
        }
    }
}

}  // namespace ax
