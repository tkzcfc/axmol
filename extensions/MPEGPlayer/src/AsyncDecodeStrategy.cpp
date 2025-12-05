#include "AsyncDecodeStrategy.h"
#include "Utils.h"

namespace mpeg
{
struct AsyncVideoFrame
{
    AsyncVideoFrame(size_t size)
    {
        this->size          = size;
        this->bytes         = new unsigned char[size * 4];
        this->frame.y.data  = this->bytes;
        this->frame.cr.data = this->bytes + size * 2;
        this->frame.cb.data = this->bytes + size * 3;
    }

    ~AsyncVideoFrame()
    {
        delete[] bytes;
        bytes = nullptr;
    }

    unsigned char* bytes;
    size_t size;
    plm_frame_t frame;
};

static void decoder_loop(
    plm_t* plm,
    ax::IFileStream* fs,
    std::shared_ptr<std::atomic_bool> exitFlag,
    std::shared_ptr<std::atomic_bool> isReady,
    std::shared_ptr<std::atomic_bool> isPlayEnd,
    std::shared_ptr<moodycamel::ConcurrentQueue<AsyncVideoFrame*>> freeVideoFrame,
    std::shared_ptr<moodycamel::ConcurrentQueue<AsyncVideoFrame*>> decodedVideoFrame,
    std::shared_ptr<moodycamel::ConcurrentQueue<std::function<void(plm_t*)>>> decodingThreadOperation)
{
    std::function<void(plm_t*)> op;
    AsyncVideoFrame* videoFrame = nullptr;
    plm_frame_t* plmFrame       = nullptr;

    plm_set_audio_enabled(plm, 0);
    plm_set_video_decode_callback(plm, [](plm_t* mpeg, plm_frame_t* frame, void* user) -> void {
        plm_frame_t** plmFramePtr = static_cast<plm_frame_t**>(user);
        *plmFramePtr              = frame;
    }, &plmFrame);

    while (!exitFlag->load())
    {
        while (decodingThreadOperation->try_dequeue(op))
        {
            op(plm);
        }
        auto ended = plm_has_ended(plm);
        isPlayEnd->store(ended);
        if (ended)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            continue;
        }

        if (!freeVideoFrame->try_dequeue(videoFrame))
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            continue;
        }
        auto ready = isReady->load();
        plmFrame   = nullptr;
        plm_decode(plm, 1 / 60.0f);
        if (plmFrame)
        {
            auto curFrame    = &videoFrame->frame;
            curFrame->width  = plmFrame->width;
            curFrame->height = plmFrame->height;
            curFrame->time   = plmFrame->time;
            ::memcpy(curFrame->y.data, plmFrame->y.data, static_cast<size_t>(plmFrame->y.width * plmFrame->y.height));
            curFrame->y.width  = plmFrame->y.width;
            curFrame->y.height = plmFrame->y.height;
            assert(static_cast<size_t>(plmFrame->y.width * plmFrame->y.height) <= videoFrame->size * 2);

            ::memcpy(curFrame->cr.data, plmFrame->cr.data,
                     static_cast<size_t>(plmFrame->cr.width * plmFrame->cr.height));
            curFrame->cr.width  = plmFrame->cr.width;
            curFrame->cr.height = plmFrame->cr.height;
            assert(static_cast<size_t>(plmFrame->cr.width * plmFrame->cr.height) <= videoFrame->size);

            ::memcpy(curFrame->cb.data, plmFrame->cb.data,
                     static_cast<size_t>(plmFrame->cb.width * plmFrame->cb.height));
            curFrame->cb.width  = plmFrame->cb.width;
            curFrame->cb.height = plmFrame->cb.height;
            assert(static_cast<size_t>(plmFrame->cb.width * plmFrame->cb.height) <= videoFrame->size);

            if (isReady->load() == false)
            {
                if (ready)
                {
                    freeVideoFrame->enqueue(videoFrame);
                }
                else
                {
                    decodedVideoFrame->enqueue(videoFrame);
                }
                isReady->store(true);
            }
            else
            {
                decodedVideoFrame->enqueue(videoFrame);
            }
        }
        else
        {
            freeVideoFrame->enqueue(videoFrame);
        }
    }

    while (decodingThreadOperation->try_dequeue(op))
    {
    }
    while (freeVideoFrame->try_dequeue(videoFrame))
    {
        delete videoFrame;
    }
    while (decodedVideoFrame->try_dequeue(videoFrame))
    {
        delete videoFrame;
    }
    plm_destroy(plm);
    AX_SAFE_DELETE(fs);
}

AsyncDecodeStrategy::AsyncDecodeStrategy()
    : m_pause(false)
    , m_videoWidth(0)
    , m_videoHeight(0)
    , m_duration(0.0)
    , m_currentTime(0.0)
    , m_exitFlag(nullptr)
    , m_decodingThread(nullptr)
    , m_looping(false)
    , m_unusedVideoFrame(nullptr)
{}

AsyncDecodeStrategy::~AsyncDecodeStrategy()
{
    if (m_renderVideoFrame)
    {
        AsyncVideoFrame* videoFrame = nullptr;
        while (m_renderVideoFrame->try_dequeue(videoFrame))
        {
            delete videoFrame;
        }
    }
    if (m_unusedVideoFrame)
    {
        AX_SAFE_DELETE(m_unusedVideoFrame);
    }

    if (m_exitFlag)
    {
        m_exitFlag->store(true);
    }
    if (m_decodingThread)
    {
        m_decodingThread->detach();
        m_decodingThread = nullptr;
    }
}

bool AsyncDecodeStrategy::initialize(const std::string& filename)
{
    auto result = new_plm_from_file(filename);
    auto plm    = std::get<0>(result);
    auto fs     = std::get<1>(result);

    if (plm == nullptr)
        return false;

    m_currentTime = 0.0;
    m_duration    = plm_get_duration(plm);
    m_videoWidth  = plm_get_width(plm);
    m_videoHeight = plm_get_height(plm);
    m_looping     = plm_get_loop(plm) != 0;

    m_exitFlag                = std::make_shared<std::atomic_bool>(false);
    m_isReady                 = std::make_shared<std::atomic_bool>(false);
    m_isPlayEnd               = std::make_shared<std::atomic_bool>(false);
    m_freeVideoFrame          = std::make_shared<moodycamel::ConcurrentQueue<AsyncVideoFrame*>>();
    m_decodedVideoFrame       = std::make_shared<moodycamel::ConcurrentQueue<AsyncVideoFrame*>>();
    m_renderVideoFrame        = std::make_shared<moodycamel::ConcurrentQueue<AsyncVideoFrame*>>();
    m_decodingThreadOperation = std::make_shared<moodycamel::ConcurrentQueue<std::function<void(plm_t*)>>>();

    constexpr int MAX_BUFFER = 6;
    for (int i = 0; i < MAX_BUFFER; ++i)
    {
        AsyncVideoFrame* frame = new AsyncVideoFrame(m_videoWidth * m_videoHeight);
        if (!frame->bytes || !m_freeVideoFrame->enqueue(frame))
        {
            delete frame;
            plm_destroy(plm);
            AX_SAFE_DELETE(fs);
            return false;
        }
    }

    m_decodingThread = std::make_unique<std::thread>(decoder_loop, plm, fs, m_exitFlag, m_isReady, m_isPlayEnd,
                                                     m_freeVideoFrame, m_decodedVideoFrame, m_decodingThreadOperation);
    if (!m_decodingThread)
    {
        AsyncVideoFrame* frame = nullptr;
        while (m_freeVideoFrame->try_dequeue(frame))
        {
            delete frame;
        }
        plm_destroy(plm);
        AX_SAFE_DELETE(fs);
        return false;
    }

    return true;
}

VideoFrame* AsyncDecodeStrategy::decode(double dt)
{
    AsyncVideoFrame* videoFrame = nullptr;
    while (m_renderVideoFrame->try_dequeue(videoFrame))
    {
        m_freeVideoFrame->enqueue(videoFrame);
    }

    if (m_isPlayEnd->load() || !m_isReady->load())
        return nullptr;

    m_currentTime += dt;
    m_videoFrame.frame = nullptr;

    if (!m_unusedVideoFrame)
    {
        m_decodedVideoFrame->try_dequeue(m_unusedVideoFrame);
    }

    if (m_unusedVideoFrame)
    {
        if (m_currentTime >= m_unusedVideoFrame->frame.time)
        {
            m_videoFrame.frame = &m_unusedVideoFrame->frame;
            m_renderVideoFrame->enqueue(m_unusedVideoFrame);
            m_unusedVideoFrame = nullptr;
        }
    }

    return &m_videoFrame;
}

bool AsyncDecodeStrategy::seekTo(double time_sec)
{
    if (m_unusedVideoFrame)
    {
        m_freeVideoFrame->enqueue(m_unusedVideoFrame);
        m_unusedVideoFrame = nullptr;
    }

    while (m_decodedVideoFrame->try_dequeue(m_unusedVideoFrame))
    {
        m_freeVideoFrame->enqueue(m_unusedVideoFrame);
        m_unusedVideoFrame = nullptr;
    }

    m_isReady->store(false);
    m_currentTime = time_sec;
    m_decodingThreadOperation->enqueue([time_sec](plm_t* plm) { plm_seek(plm, time_sec, 0); });
    return true;
}

void AsyncDecodeStrategy::setLooping(bool looping)
{
    m_looping = looping;
    m_decodingThreadOperation->enqueue([looping](plm_t* plm) { plm_set_loop(plm, looping ? 1 : 0); });
}

bool AsyncDecodeStrategy::isLooping() const
{
    return m_looping;
}
double AsyncDecodeStrategy::getDuration() const
{
    return m_duration;
}
double AsyncDecodeStrategy::getCurrentTime() const
{
    return m_currentTime;
}
int AsyncDecodeStrategy::getVideoWidth() const
{
    return m_videoWidth;
}
int AsyncDecodeStrategy::getVideoHeight() const
{
    return m_videoHeight;
}

}  // namespace mpeg
