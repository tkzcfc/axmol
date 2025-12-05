#pragma once

#include "IDecodeStrategy.h"

struct plm_t;

namespace mpeg
{

class SyncDecodeStrategy : public IDecodeStrategy
{
public:
    SyncDecodeStrategy();

    virtual ~SyncDecodeStrategy();

    virtual bool initialize(const std::string& filename) override;

    virtual VideoFrame* decode(double dt) override;

    virtual bool seekTo(double time_sec) override;
    virtual void setLooping(bool looping) override;

    virtual bool isLooping() const override;
    virtual double getDuration() const override;
    virtual double getCurrentTime() const override;
    virtual int getVideoWidth() const override;
    virtual int getVideoHeight() const override;

private:
    plm_t* m_plm;
    ax::IFileStream* m_fs;
    VideoFrame m_frame;
};
}  // namespace mpeg
