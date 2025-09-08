#ifndef __G_CACHE_H__
#define __G_CACHE_H__

#include "cocos2d.h"
#include "FairyGUIMacros.h"
#include <spine/spine-cocos2dx.h>

NS_FGUI_BEGIN


struct SkeletonCacheData
{
    spine::SkeletonData* data;
    spine::Atlas* atlas;
    spine::Cocos2dAtlasAttachmentLoader* attachmentLoader;
};

class GCache
{
    static GCache* cacheIns;

public:
    GCache();

    ~GCache();

    static GCache* getInstance();

    static void destroy();
    
	spine::SkeletonData* getOrCreateSkeletonData(const std::string& skeletonDataFile,
                                                 const std::string& atlasFile);

    void preloadSkeletonData(const std::string& skeletonDataFile, const std::string& atlasFile);

    void clearSkeletonData();

private:
    std::unordered_map<std::string, SkeletonCacheData> _skeletonCacheMap;
};

NS_FGUI_END

#endif
