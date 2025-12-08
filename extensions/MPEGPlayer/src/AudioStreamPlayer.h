#pragma once

#include <AL/al.h>
#include <AL/alc.h>

class AudioStreamPlayer
{
public:
    AudioStreamPlayer(int sampleRate, int channels);
    ~AudioStreamPlayer();

    bool isValid() const { return valid; }

    void pushFrame(const float* data, int samples);

    void setVolume(float volume);

private:
    void checkALError(const char* msg);

    ALuint source       = 0;
    int sampleRate      = 0;
    int channels        = 0;
    bool valid          = false;
};
