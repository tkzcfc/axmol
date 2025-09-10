#pragma once

#include "axmol.h"


namespace ax
{

class WebmLoadTask;
class Webm : public ax::Sprite
{

public:
	Webm();
	virtual ~Webm();

	static Webm* create(const std::string& webm, int skipFramesPerTimes = -1);

    static Webm* createAsync(const std::string& webm, int skipFramesPerTimes = -1);

	bool initWithWebm(const std::string& webm, int skipFramesPerTimes = -1);

    bool initWithWebmAsync(const std::string& webm, int skipFramesPerTimes = -1);

	void play(int loop = 1);

	void rePlay(int loop = 1);

	void setLoop(int loop);

	int getLoop();

	bool isPlay();

	void stop();

    // Class Node already has a pause function
    void suspend();

	bool setFrame(int frame);

	bool nextFrame();

	bool preFrame();

	void setPlayScale(float playScale);

	float getPlayScale();

	void setReverse(bool value);

	void setFps(int fps);

	int getFrameCount();

	void setOnPlayEnd(const std::function<void()>& call);

    void setOnEventCallback(const std::function<void(const std::string&)>& call);

    bool isLoadFinish();

    void setKeepContentSize(bool value);

    std::string getWebmPath();

	static void* preloadAsync(const std::string& webm, const std::function<void(bool)>& callback, int skipFramesPerTimes = -1);
	static void cancelAllAsync();
	static void setSkipFramesPerTimes(int skipFramesPerTimes);
	static void setLoadFinishAutoCreateTexture(bool value);
    static void removeAllWebmTexture();
    static void setDecodeThreadCount(int value);
    static ax::AsyncTaskPool::TaskType getAsyncTaskType();

protected:
	void update(float dt) override;

private:
	void playEnd();

	float m_animationInterval;
	bool m_reverse;
	int m_loop;
	float m_playScale;
	int m_frame;
	bool m_play;
    float m_time;
    bool m_isSyncLoad;
    bool m_isKeepContentSize;
	WebmLoadTask* m_loadTask;
	std::function<void()> m_onPlayEnd;
    std::function<void(const std::string&)> m_onEvent;
	Vector<ax::Texture2D*> m_textures;

	static std::vector<WebmLoadTask*> asyncTasks;
	static std::mutex asyncTaskMutex;
    static std::set<std::string> g_allTextureKeySet;
	static int g_skipFramesPerTimes;
	static bool g_loadFinishAutoCreateTexture;
    static int g_decodeThreadCount;
};

}  // namespace ax
