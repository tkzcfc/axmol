#pragma once

#include "IDecodeStrategy.h"
#include "concurrentqueue/concurrentqueue.h"

namespace mpeg
{

struct AsyncVideoFrame;
class AsyncDecodeStrategy : public IDecodeStrategy
{
public:
    AsyncDecodeStrategy();

    virtual ~AsyncDecodeStrategy();

    virtual bool initialize(const std::string& filename) override;

    virtual VideoFrame* decode(double dt) override;

    virtual void start() override;
    virtual void stop() override;
    virtual void pause() override;
    virtual void resume() override;
    virtual bool seekTo(double time_sec) override;
    virtual void setLooping(bool looping) override;
    virtual bool isLooping() const override;
    virtual double getDuration() const override;
    virtual double getCurrentTime() const override;
    virtual int getVideoWidth() const override;
    virtual int getVideoHeight() const override;
    virtual void setAudioEnabled(bool enabled) override;
    virtual void setVideoEnabled(bool enabled) override;
    virtual void setVolume(float volume) override;

private:
    bool m_pause;
    int m_videoWidth;
    int m_videoHeight;
    double m_currentTime;
    double m_duration;
    bool m_looping;
    bool m_waitFirstFrame;
    VideoFrame m_videoFrame;

    std::shared_ptr<std::atomic_bool> m_startFlag;
    std::shared_ptr<std::atomic_bool> m_exitFlag;
    std::shared_ptr<std::atomic_bool> m_isReady;
    std::shared_ptr<std::atomic_bool> m_isPlayEnd;
    std::shared_ptr<moodycamel::ConcurrentQueue<AsyncVideoFrame*>> m_freeVideoFrame;
    std::shared_ptr<moodycamel::ConcurrentQueue<AsyncVideoFrame*>> m_decodedVideoFrame;
    std::shared_ptr<moodycamel::ConcurrentQueue<AsyncVideoFrame*>> m_renderVideoFrame;
    std::shared_ptr<moodycamel::ConcurrentQueue<std::function<void(plm_t*)>>> m_decodingThreadOperation;
    std::unique_ptr<std::thread> m_decodingThread;
    AsyncVideoFrame* m_unusedVideoFrame;
};
}  // namespace mpeg
