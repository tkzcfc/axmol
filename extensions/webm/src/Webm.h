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

	/// <summary>
	/// Synchronous initialization
	/// </summary>
	/// <param name="webm"></param>
	/// <param name="skipFramesPerTimes"></param>
	/// <returns></returns>
	bool initWithWebm(const std::string& webm, int skipFramesPerTimes = -1);

    /// <summary>
    /// Asynchronous initialization
    /// </summary>
    /// <param name="webm"></param>
    /// <param name="skipFramesPerTimes"></param>
    /// <returns></returns>
    bool initWithWebmAsync(const std::string& webm, int skipFramesPerTimes = -1);

	/// <summary>
	/// Play
	/// </summary>
	/// <param name="loop"></param>
	void play(int loop = 1);

	/// <summary>
	/// Play from the beginning
	/// </summary>
	/// <param name="loop"></param>
	void rePlay(int loop = 1);

	/// <summary>
	/// Set the loop count
	/// </summary>
	/// <param name="loop"></param>
	void setLoop(int loop);

	/// <summary>
	/// Get the current loop count
	/// </summary>
	/// <returns></returns>
	int getLoop();

	/// <summary>
	/// Returns whether it is currently playing
	/// </summary>
	/// <returns></returns>
	bool isPlay();

	/// <summary>
	/// Stop playback
	/// </summary>
	void stop();

    /// <summary>
    /// Pause playback, Class Node already has a pause function
    /// </summary>
    void suspend();

	/// <summary>
	/// Set the current display frame
	/// </summary>
	/// <param name="frame"></param>
	/// <returns></returns>
	bool setFrame(int frame);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	bool nextFrame();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	bool preFrame();

	/// <summary>
	/// Set playback time scaling
	/// </summary>
	/// <param name="playScale"></param>
	void setPlayScale(float playScale);

	/// <summary>
	/// Get playback time scaling
	/// </summary>
	/// <returns></returns>
	float getPlayScale();

	/// <summary>
	/// Set reverse playback
	/// </summary>
	/// <param name="value"></param>
	void setReverse(bool value);

	/// <summary>
	/// Set the frame rate for animation playback
	/// </summary>
	/// <param name="fps"></param>
	void setFps(int fps);

	/// <summary>
	/// Get the total number of frames
	/// </summary>
	/// <returns></returns>
	int getFrameCount();

	/// <summary>
	/// Set the playback completion callback function
	/// </summary>
	/// <param name="call"></param>
	void setOnPlayEnd(const std::function<void()>& call);

    /// <summary>
    /// Set event callback function
    /// </summary>
    /// <param name="call"></param>
    void setOnEventCallback(const std::function<void(const std::string&)>& call);

    /// <summary>
    /// Query whether the loading is complete
    /// </summary>
    /// <returns></returns>
    bool isLoadFinish();

    /// <summary>
    /// Set whether to maintain the content size
    /// </summary>
    /// <param name="value"></param>
    void setKeepContentSize(bool value);

    /// <summary>
    /// Get the path of the webm file
    /// </summary>
    /// <returns></returns>
    std::string getWebmPath();

	/// <summary>
	/// Asynchronous preloading of webm files
	/// </summary>
	/// <param name="webm"></param>
	/// <param name="callback"></param>
	/// <param name="skipFramesPerTimes"></param>
	/// <returns></returns>
	static void* preloadAsync(const std::string& webm, const std::function<void(bool)>& callback, int skipFramesPerTimes = -1);

    /// <summary>
    /// Cancel all asynchronous loading tasks
    /// </summary>
    static void cancelAllAsync();

	/// <summary>
	/// Set skipped frames
	/// </summary>
	/// <param name="skipFramesPerTimes"></param>
	static void setSkipFramesPerTimes(int skipFramesPerTimes);

	/// <summary>
	/// deprecated API
	/// </summary>
	/// <param name="value"></param>
	static void setLoadFinishAutoCreateTexture(bool value);

    /// <summary>
    /// Remove all webm texture caches
    /// </summary>
    static void removeAllWebmTexture();

    /// <summary>
    /// Set the number of decoding threads (deprecated API)
    /// </summary>
    /// <param name="value"></param>
    static void setDecodeThreadCount(int value);

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
