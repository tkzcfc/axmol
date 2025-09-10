#include "Webm.h"
#include "WebmUnpacker.h"

namespace ax
{

static unsigned char cc_2x2_white_image[] = {
    // RGBA8888
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };

#define AX_2x2_WHITE_IMAGE_KEY "/cc_2x2_white_image"

struct WebmFrame
{
    ax::Image* image;
    int index;
};

struct WebmResult
{
    int with;
    int height;
    int frameCount;
    std::vector<WebmFrame> frames;
};

enum class LoadStatus
{
    Waiting, // 等待中
    Loading, // 正在加载
    Cancel, // 取消加载
    Success, // 加载成功
    Failed // 加载失败
};

class WebmLoadTask : public ax::Object
{
public:
    WebmLoadTask() 
    {
        AXLOG("alloc WebmLoadTask  %p", this);
    }
    virtual ~WebmLoadTask() 
    {
        AXLOG("free WebmLoadTask  %p", this);
    };
    LoadStatus status;
    std::function<void(bool)> callback;
    WebmResult result;
    std::string webm;
};
std::vector<WebmLoadTask*> Webm::asyncTasks;
std::mutex Webm::asyncTaskMutex;
std::set<std::string> Webm::g_allTextureKeySet;
int Webm::g_skipFramesPerTimes = 1;
bool Webm::g_loadFinishAutoCreateTexture = true;
int Webm::g_decodeThreadCount           = 1;


bool loadWebm(WebmResult* result, const std::string& webm, int skipFramesPerTimes)
{
    result->with = 0;
    result->height = 0;
    result->frameCount = 0;
    auto data = ax::FileUtils::getInstance()->getDataFromFile(webm);
    if (data.isNull())
    {
        return false;
    }

    auto context = create_webm_decoder(data.getBytes(), data.getSize(), true, 0, false, false, skipFramesPerTimes);
    assert(context);

    auto frameCount = frames_count(context);
    auto width = get_webm_width(context);
    auto height = get_webm_height(context);

    result->with = width;
    result->height = height;
    result->frameCount = frameCount;
    result->frames.reserve(frameCount);

    for (auto i = 0; i < frameCount; ++i) {
        auto frameDatLen = get_frame_data_size(context, i);
        auto frameData = get_frame_data(context, i);
        if (frameDatLen > 0)
        {
            auto image = new ax::Image();
            if (image && image->initWithRawData(frameData, frameDatLen, width, height, 0, false))
            {
                WebmFrame frame;
                frame.index = i;
                frame.image = image;
                result->frames.push_back(frame);
            }
        }
    }

    destroy_decoder(context);
    release_webm(context);
    return true;
}

inline std::string webmFrameKey(const char* webm, int frameIndex)
{
    return ax::StringUtils::format("webm@%s-%d", webm, frameIndex);
}


Webm* Webm::create(const std::string& webmfile, int skipFramesPerTimes)
{
    Webm* webm = new Webm();
    if (!webm)
    {
        return nullptr;
    }
    if (webm->initWithWebm(webmfile, skipFramesPerTimes))
    {
        webm->autorelease();
        return webm;
    }
    webm->release();
    return nullptr;
}

Webm* Webm::createAsync(const std::string& webmfile, int skipFramesPerTimes)
{
    Webm* webm = new Webm();
    if (!webm)
    {
        return nullptr;
    }
    if (webm->initWithWebmAsync(webmfile, skipFramesPerTimes))
    {
        webm->autorelease();
        return webm;
    }
    webm->release();
    return nullptr;
}

Webm::Webm()
    : m_loadTask(NULL)
    , m_playScale(1.0f)
    , m_frame(0)
    , m_play(false)
    , m_reverse(false)
    , m_loop(1)
    , m_time(0.0f)
    , m_isSyncLoad(false)
    , m_isKeepContentSize(false)
{
    setFps(30);
}

Webm::~Webm()
{
    m_textures.clear();
    AX_SAFE_RELEASE_NULL(m_loadTask);
}

bool Webm::initWithWebm(const std::string& webm, int skipFramesPerTimes)
{
    m_isSyncLoad = false;
    m_textures.clear();
    AX_SAFE_RELEASE_NULL(m_loadTask);

    asyncTaskMutex.lock();
    for (auto& it : asyncTasks)
    {
        if (it->webm == webm && (it->status == LoadStatus::Success || it->status == LoadStatus::Failed))
        {
            m_loadTask = it;
            break;
        }
    }
    asyncTaskMutex.unlock();

    if (m_loadTask == nullptr) 
    {
        auto task = new WebmLoadTask();
        task->status = LoadStatus::Loading;
        task->callback = nullptr;
        task->webm = webm;

        auto skipValue = skipFramesPerTimes >= 0 ? skipFramesPerTimes : g_skipFramesPerTimes;
        if (loadWebm(&task->result, webm, skipValue))
            task->status = LoadStatus::Success;
        else
            task->status = LoadStatus::Failed;

        asyncTaskMutex.lock();
        asyncTasks.push_back(task);
        asyncTaskMutex.unlock();

        m_loadTask = task;
    }
    AX_SAFE_RETAIN(m_loadTask);


    auto popupNotify = ax::FileUtils::getInstance()->isPopupNotify();
    ax::FileUtils::getInstance()->setPopupNotify(false);

    auto textureCache = ax::Director::getInstance()->getTextureCache();
    int index = 0;
    ax::Texture2D* lastTexture = nullptr;
    auto& frames = m_loadTask->result.frames;
    m_textures.reserve(m_loadTask->result.frameCount);
    for (auto i = 0; i < m_loadTask->result.frameCount; ++i)
    {
        if (index < frames.size()) 
        {
            if (i == frames[index].index) {
                auto key = webmFrameKey(m_loadTask->webm.c_str(), frames[index].index);
                lastTexture = textureCache->getTextureForKey(key);
                if (!lastTexture && frames[index].image) 
                {
                    g_allTextureKeySet.insert(key);
                    lastTexture = textureCache->addImage(frames[index].image, key);
                }
                AX_SAFE_RELEASE_NULL(frames[index].image);
                index++;
            }
        }

        if (lastTexture == nullptr) 
        {
            // Gets the texture by key firstly.
            lastTexture = textureCache->getTextureForKey(AX_2x2_WHITE_IMAGE_KEY);

            // If texture wasn't in cache, create it from RAW data.
            if (lastTexture == nullptr)
            {
                Image* image = new Image();
                bool AX_UNUSED isOK = image->initWithRawData(cc_2x2_white_image, sizeof(cc_2x2_white_image), 2, 2, 8);
                AXASSERT(isOK, "The 2x2 empty texture was created unsuccessfully.");

                lastTexture = textureCache->addImage(image, AX_2x2_WHITE_IMAGE_KEY);
                AX_SAFE_RELEASE(image);
            }
        }

        m_textures.pushBack(lastTexture);
    }
    ax::FileUtils::getInstance()->setPopupNotify(popupNotify);

    assert(m_textures.size() == m_loadTask->result.frameCount);

    auto oldSize = this->getContentSize();
    auto oldPos  = this->getPosition();
    auto oldAnchor  = this->getAnchorPoint();
    if (m_onEvent)
    {
        m_onEvent("onBeforeLoadTexture");
    }

    if (!m_textures.empty())
    {
        initWithTexture(m_textures.at(0));
    }
    setFrame(m_frame);
    scheduleUpdate();

    if (m_isKeepContentSize)
    {
        this->setContentSize(oldSize);
        this->setAnchorPoint(oldAnchor);
        this->setPosition(oldPos);
    }
    if (m_onEvent)
    {
        m_onEvent("onPostLoadTexture");
    }
    return true;
}

bool Webm::initWithWebmAsync(const std::string& webm, int skipFramesPerTimes)
{
    m_isSyncLoad = true;
    m_textures.clear();
    AX_SAFE_RELEASE_NULL(m_loadTask);

    asyncTaskMutex.lock();
    for (auto& it : asyncTasks)
    {
        if (it->webm == webm)
        {
            m_loadTask = it;
            break;
        }
    }
    asyncTaskMutex.unlock();

    if (m_loadTask == nullptr)
    {
        auto skipValue = skipFramesPerTimes >= 0 ? skipFramesPerTimes : g_skipFramesPerTimes;
        m_loadTask     = (WebmLoadTask*)preloadAsync(webm, nullptr, skipValue);
    }
    AX_SAFE_RETAIN(m_loadTask);
    scheduleUpdate();

    return true;
}

void Webm::play(int loop)
{
    m_play = true;
    m_loop = loop;

    if (m_frame == -10086)
    {
        int frame = m_reverse ? m_loadTask->result.frameCount - 1 : 0;
        setFrame(frame);
    }
}

void Webm::rePlay(int loop)
{
    stop();
    play(loop);
}

bool Webm::isPlay()
{
    return m_play;
}

void Webm::setLoop(int loop)
{
    m_loop = loop;
}

int Webm::getLoop()
{
    return m_loop;
}

void Webm::stop()
{
    m_frame = -10086;
    m_play = false;
    m_time = 0.0f;
}

void Webm::suspend()
{
    m_play = false;
}

bool Webm::setFrame(int frame)
{
    if (!isLoadFinish())
    {
        m_frame = frame;
        return true;
    }
    m_frame = frame;
    if (m_frame < 0 || m_frame >= getFrameCount())
    {
        return false;
    }

    setTexture(m_textures.at(m_frame));
    return true;
}

bool Webm::nextFrame()
{
    auto frame = m_frame + 1;
    if (frame >= getFrameCount())
    {
        if (m_loop > 0) --m_loop;
        if (m_loop == 0)
        {
            playEnd();
            return true;
        }
        frame = 0;
    }
    return setFrame(frame);
}

bool Webm::preFrame()
{
    auto frame = m_frame - 1;
    if (frame < 0)
    {
        if (m_loop > 0) --m_loop;
        if (m_loop == 0)
        {
            playEnd();
            return true;
        }
        frame = getFrameCount() - 1;
    }
    return setFrame(frame);
}

void Webm::setPlayScale(float playScale)
{
    m_playScale = playScale;
}

float Webm::getPlayScale()
{
    return m_playScale;
}

void Webm::setReverse(bool value)
{
    m_reverse = value;
}

void Webm::setFps(int fps)
{
    m_animationInterval = 1.0f / fps;
}

int Webm::getFrameCount()
{
    return m_textures.size();
}

void Webm::setOnPlayEnd(const std::function<void()>& call)
{
    m_onPlayEnd = call;
}

void Webm::setOnEventCallback(const std::function<void(const std::string&)>& call)
{
    m_onEvent = call;
}

bool Webm::isLoadFinish()
{
    return (m_loadTask && (m_loadTask->status == LoadStatus::Success || m_loadTask->status == LoadStatus::Failed));
}

void Webm::setKeepContentSize(bool value)
{
    m_isKeepContentSize = value;
}

std::string Webm::getWebmPath()
{
    if (m_loadTask)
    {
        return m_loadTask->webm;
    }
    return "";
}

void Webm::update(float dt)
{
    Sprite::update(dt);

    if (!isLoadFinish())
        return;

    if (m_isSyncLoad)
    {
        this->initWithWebm(m_loadTask->webm);
    }

    if (!m_play)
        return;

    dt *= m_playScale;
    m_time += dt;

    while (m_time >= m_animationInterval)
    {
        m_time -= m_animationInterval;
        if (m_reverse)
            preFrame();
        else
            nextFrame();

        if (!m_play) break;
    }
}

void Webm::playEnd()
{
    m_play = false;
    if (m_onPlayEnd)
    {
        this->runAction(ax::CallFunc::create(m_onPlayEnd));
    }
}

//////////////////////////////////////////////////// async ////////////////////////////////////////////////////
void* Webm::preloadAsync(const std::string& webm, const std::function<void(bool)>& callback, int skipFramesPerTimes)
{
    if (skipFramesPerTimes == -1)
    {
        skipFramesPerTimes = g_skipFramesPerTimes;
    }

    auto task = new WebmLoadTask();
    task->status = LoadStatus::Waiting;
    task->callback = callback;
    task->webm = webm;

    asyncTaskMutex.lock();
    asyncTasks.push_back(task);
    asyncTaskMutex.unlock();

    task->retain();
    ax::AsyncTaskPool::getInstance()->enqueue(getAsyncTaskType(),
        [](void* data) {
        auto task = (WebmLoadTask*)data;
        if (task->status != LoadStatus::Cancel) {
            if (task->status == LoadStatus::Success) {
                auto textureCache = ax::Director::getInstance()->getTextureCache();
                auto popupNotify = ax::FileUtils::getInstance()->isPopupNotify();
                ax::FileUtils::getInstance()->setPopupNotify(false);
                for (auto i = 0; i < task->result.frames.size(); ++i) {
                    auto& frame = task->result.frames[i];
                    auto key = webmFrameKey(task->webm.c_str(), frame.index);
                    if (frame.image && !textureCache->getTextureForKey(key))
                    {
                        g_allTextureKeySet.insert(key);
                        textureCache->addImage(frame.image, key);
                    }
                    AX_SAFE_RELEASE_NULL(frame.image);
                }
                ax::FileUtils::getInstance()->setPopupNotify(popupNotify);
            }
            if (task->callback) {
                task->callback(task->status == LoadStatus::Success);
                task->callback = nullptr;
            }
        }
        task->release();
    }, task, [task, webm, skipFramesPerTimes]() {
        asyncTaskMutex.lock();
        if (task->status == LoadStatus::Cancel)
        {
            asyncTaskMutex.unlock();
            return;
        }
        task->status = LoadStatus::Loading;
        asyncTaskMutex.unlock();
    
        auto ok = loadWebm(&task->result, webm, skipFramesPerTimes);
    
        asyncTaskMutex.lock();
        if (task->status == LoadStatus::Cancel)
        {
            asyncTaskMutex.unlock();
            return;
        }
        task->status = ok ? LoadStatus::Success : LoadStatus::Failed;
        asyncTaskMutex.unlock();
    });

    return task;
}

void Webm::cancelAllAsync()
{
    asyncTaskMutex.lock();
    for (auto& task : asyncTasks)
    {
        task->status = LoadStatus::Cancel;
        task->release();
    }
    asyncTasks.clear();
    asyncTaskMutex.unlock();

#if AX_REF_LEAK_DETECTION
    ax::Ref::printLeaks();
#endif
}

void Webm::setSkipFramesPerTimes(int skipFramesPerTimes)
{
    g_skipFramesPerTimes = MAX(skipFramesPerTimes, 0);
}

void Webm::setLoadFinishAutoCreateTexture(bool value)
{
    g_loadFinishAutoCreateTexture = value;
}

void Webm::removeAllWebmTexture()
{
    auto textureCache = ax::Director::getInstance()->getTextureCache();
    for (auto& key : g_allTextureKeySet)
    {
        textureCache->removeTextureForKey(key);
    }
    g_allTextureKeySet.clear();
}

void Webm::setDecodeThreadCount(int value)
{
    g_decodeThreadCount = value;
}

ax::AsyncTaskPool::TaskType Webm::getAsyncTaskType()
{
    if (g_decodeThreadCount <= 1)
    {
        return ax::AsyncTaskPool::TaskType::TASK_IO;
    }
    if (g_decodeThreadCount == 2)
    {
        ax::AsyncTaskPool::TaskType taskTypes[] = {
            ax::AsyncTaskPool::TaskType::TASK_IO,
            ax::AsyncTaskPool::TaskType::TASK_NETWORK,
        };
        return taskTypes[std::rand() % 2];
    }

    ax::AsyncTaskPool::TaskType taskTypes[] = {
        ax::AsyncTaskPool::TaskType::TASK_IO,
        ax::AsyncTaskPool::TaskType::TASK_NETWORK,
        ax::AsyncTaskPool::TaskType::TASK_OTHER,
    };
    return taskTypes[std::rand() % 3];
}

}  // namespace ax
