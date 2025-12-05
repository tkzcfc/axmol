#pragma once

#include "axmol.h"
#include "IDecodeStrategy.h"

namespace ax
{

class MPEGPlayer : public Sprite
{

public:
    MPEGPlayer();

    virtual ~MPEGPlayer();

    static MPEGPlayer* create(const std::string& filename, bool useAsyncDecoding = true);

    virtual bool init() override;

    bool initWithMPEG(const std::string& filename, bool useAsyncDecoding);

    /**
     * @brief Set if playback is done in loop mode
     *
     * @param looping the video will or not automatically restart at the end
     */
    virtual void setLooping(bool looping);

    /**
     * Starts playback.
     */
    virtual void play();

    /**
     * Pauses actions and playback.
     */
    void pause() override;

    /**
     * Resumes actions and playback.
     */
    void resume() override;

    /**
     * @brief Pauses playback
     *
     */
    void pausePlayback();

    /**
     * @brief Resumes playback
     *
     */
    void resumePlayback();

    /**
     * Stops playback.
     */
    virtual void stop();

    /**
     * Seeks to specified time position.
     *
     * @param sec   The offset in seconds from the start to seek to.
     */
    virtual void seekTo(double sec);

    /**
     * Gets the current media position.
     *
     * @return float The current position in seconds
     */
    virtual double getCurrentTime();

    /**
     * Gets total video duration
     *
     * @return float The duration in seconds
     */
    virtual double getDuration();

    /**
     * Checks whether the MediaPlayer is playing.
     *
     * @return True if currently playing, false otherwise.
     */
    virtual bool isPlaying() const;

    /**
     * Checks whether the MediaPlayer is set with looping mode.
     *
     * @return true if the videoplayer is set to loop, false otherwise.
     */
    virtual bool isLooping() const;

private:
    void update(float dt) override;

    std::unique_ptr<mpeg::IDecodeStrategy> m_decoder;
    Texture2D* m_texture_y;
    Texture2D* m_texture_cb;
    Texture2D* m_texture_cr;
    bool m_isPasued;
};

}  // namespace ax
