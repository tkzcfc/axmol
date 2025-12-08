#include "AudioStreamPlayer.h"
#include "axmol.h"
#include "audio/AudioEngine.h"
#include <alext.h>

using namespace ax;

AudioStreamPlayer::AudioStreamPlayer(int sampleRate, int channels) : sampleRate(sampleRate), channels(channels)
{
    if (!AudioEngine::lazyInit())
        return;

    alGenSources(1, &source);
    if (alGetError() != AL_NO_ERROR)
    {
        AXLOGE("Failed to create OpenAL source");
        return;
    }

    alSourcef(source, AL_GAIN, 1.0f);
    alSourcef(source, AL_PITCH, 1.0f);
    alSource3f(source, AL_POSITION, 0.0f, 0.0f, 0.0f);
    alSource3f(source, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
    alSourcei(source, AL_LOOPING, AL_FALSE);

    valid = true;
}

AudioStreamPlayer::~AudioStreamPlayer()
{
    if (source)
        alDeleteSources(1, &source);
}

void AudioStreamPlayer::pushFrame(const float* data, int samples)
{
    if (!valid)
        return;

    ALenum format;
    if (channels == 1)
    {
        format = AL_FORMAT_MONO_FLOAT32;
    }
    else if (channels == 2)
    {
        format = AL_FORMAT_STEREO_FLOAT32;
    }
    else
    {
        AXLOGE("Unsupported number of channels: {}", channels);
        return;
    }

    ALuint buffer;
    alGenBuffers(1, &buffer);
    checkALError("alGenBuffers");
    alBufferData(buffer, format, data, sizeof(float) * samples * channels, sampleRate);
    checkALError("alBufferData");
    alSourceQueueBuffers(source, 1, &buffer);
    checkALError("alSourceQueueBuffers");

    ALint state;
    alGetSourcei(source, AL_SOURCE_STATE, &state);
    if (state != AL_PLAYING)
    {
        alSourcePlay(source);
        checkALError("alSourcePlay");
    }

    ALint processed = 0;
    alGetSourcei(source, AL_BUFFERS_PROCESSED, &processed);
    while (processed-- > 0)
    {
        ALuint buf;
        alSourceUnqueueBuffers(source, 1, &buf);
        alDeleteBuffers(1, &buf);
    }
}

void AudioStreamPlayer::setVolume(float volume)
{
    if (!valid)
        return;
    alSourcef(source, AL_GAIN, (ALfloat)volume);
    checkALError("AudioStreamPlayer::setVolume");
}

void AudioStreamPlayer::checkALError(const char* msg)
{
    ALenum err = alGetError();
    if (err != AL_NO_ERROR)
    {
        AXLOGE("OpenAL error ({}): {}", msg, err);
    }
}
