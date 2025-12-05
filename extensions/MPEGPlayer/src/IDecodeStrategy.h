#pragma once

#include "axmol.h"
#include "pl_mpeg.h"

namespace mpeg
{
struct VideoFrame
{
    plm_frame_t* frame;
};

class IDecodeStrategy
{
public:
    virtual ~IDecodeStrategy() = default;

    virtual bool initialize(const std::string& filename) = 0;

    virtual VideoFrame* decode(double dt) = 0;

    virtual bool seekTo(double time_sec)  = 0;
    virtual void setLooping(bool loop)    = 0;
    virtual bool isLooping() const        = 0;
    virtual double getDuration() const    = 0;
    virtual double getCurrentTime() const = 0;
    virtual int getVideoWidth() const     = 0;
    virtual int getVideoHeight() const    = 0;
};

}  // namespace mpeg
