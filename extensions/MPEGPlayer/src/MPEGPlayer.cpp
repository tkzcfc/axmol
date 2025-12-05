#include "MPEGPlayer.h"
#include "SyncDecodeStrategy.h"
#include "AsyncDecodeStrategy.h"

namespace ax
{
MPEGPlayer::MPEGPlayer()
    : m_decoder(nullptr), m_texture_y(nullptr), m_texture_cb(nullptr), m_texture_cr(nullptr), m_isPasued(false)
{}

MPEGPlayer::~MPEGPlayer()
{
    AX_SAFE_RELEASE_NULL(m_texture_y);
    AX_SAFE_RELEASE_NULL(m_texture_cb);
    AX_SAFE_RELEASE_NULL(m_texture_cr);
    m_decoder = nullptr;
}

MPEGPlayer* MPEGPlayer::create(const std::string& filename, bool useAsyncDecoding)
{
    MPEGPlayer* mpeg = new MPEGPlayer();
    if (mpeg && mpeg->init() && mpeg->initWithMPEG(filename, useAsyncDecoding))
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

bool MPEGPlayer::initWithMPEG(const std::string& filename, bool useAsyncDecoding)
{
    AX_SAFE_RELEASE_NULL(m_texture_y);
    AX_SAFE_RELEASE_NULL(m_texture_cb);
    AX_SAFE_RELEASE_NULL(m_texture_cr);

    if (useAsyncDecoding)
        m_decoder = std::make_unique<mpeg::AsyncDecodeStrategy>();
    else
        m_decoder = std::make_unique<mpeg::SyncDecodeStrategy>();

    if (!m_decoder || !m_decoder->initialize(filename))
    {
        m_decoder = nullptr;
        return false;
    }

    this->setContentSize(
        Size(static_cast<float>(m_decoder->getVideoWidth()), static_cast<float>(m_decoder->getVideoHeight())));
    this->scheduleUpdate();

    return true;
}

void MPEGPlayer::setLooping(bool looping)
{
    if (m_decoder)
    {
        m_decoder->setLooping(looping);
    }
}

void MPEGPlayer::play()
{
    seekTo(.0);
    resumePlayback();
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

void MPEGPlayer::stop()
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

void MPEGPlayer::update(float dt)
{
    Sprite::update(dt);

    if (m_decoder == nullptr)
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
