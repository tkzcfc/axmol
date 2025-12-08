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

    static MPEGPlayer* create();

    virtual bool init() override;

    /**
     * Set the MPEG file to play
    */
    virtual void setVideoFile(const std::string& filename);

    /**
     * Get the MPEG file
     *
     * @return The video file name.
     */
    virtual const std::string getVideoFile() const;

    /**
    * Set if use async decoding
    */
    virtual void setUseAsyncDecoding(bool useAsyncDecoding);

    /**
     * Get if use async decoding
     *
     * @return true if use async decoding
     */
    virtual bool isUseAsyncDecoding() const;

    /**
     * Get video width
    */
    virtual int getVideoWidth() const;

    /**
     * Get video height
    */
    virtual int getVideoHeight() const;

    /**
     * Starts playback.
     */
    virtual bool play();

    /**
     * Pauses actions and playback.
     */
    void pause() override;

    /**
     * Resumes actions and playback.
     */
    void resume() override;

    /**
     * Pauses playback
     *
     */
    virtual void pausePlayback();

    /**
     * Resumes playback
     *
     */
    virtual void resumePlayback();

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
     * Checks whether the MPEGPlayer is playing.
     *
     * @return True if currently playing, false otherwise.
     */
    virtual bool isPlaying() const;

    /**
     * Set if playback is done in loop mode
     *
     * @param looping the video will or not automatically restart at the end
     */
    virtual void setLooping(bool looping);

    /**
     * Checks whether the MPEGPlayer is set with looping mode.
     *
     * @return true if the videoplayer is set to loop, false otherwise.
     */
    virtual bool isLooping() const;

    /**
     * Enable or disable audio playback
    */
    virtual void setAudioEnabled(bool enabled);

    /**
     * Checks whether audio playback is enabled.
    */
    virtual bool isAudioEnabled() const;

    /**
     * Enable or disable video playback
    */
    virtual void setVideoEnabled(bool enabled);

    /**
     * Checks whether video playback is enabled.
    */
    virtual bool isVideoEnabled() const;

    /**
     * Set the audio volume
     *
     * @param volume The volume value (range from 0.0 to 1.0).
     */
    void setVolume(float volume);

    /**
     * Get the audio volume
     *
     * @return The volume value (range from 0.0 to 1.0).
     */
    float getVolume() const;

private:
    void update(float dt) override;

    std::unique_ptr<mpeg::IDecodeStrategy> m_decoder;
    Texture2D* m_texture_y;
    Texture2D* m_texture_cb;
    Texture2D* m_texture_cr;
    bool m_isPasued;
    bool m_useAsyncDecoding;
    bool m_audioEnabled;
    bool m_videoEnabled;
    std::string m_videoFile;
    float m_volume;
};

}  // namespace ax
