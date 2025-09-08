#include "GCache.h"
#include "UIConfig.h"

NS_FGUI_BEGIN
USING_NS_AX;

static spine::Cocos2dTextureLoader textureLoader;


GCache* GCache::cacheIns = nullptr;


GCache* GCache::getInstance()
{
    if (cacheIns == nullptr)
    {
        cacheIns = new GCache();
    }
    return cacheIns;
}

void GCache::destroy()
{
    if (cacheIns)
    {
        delete cacheIns;
        cacheIns = nullptr;
    }
}

GCache::GCache() {}

GCache::~GCache()
{
    this->clearSkeletonData();
}

spine::SkeletonData* GCache::getOrCreateSkeletonData(const std::string& skeletonDataFile,
                                             const std::string& atlasFile)
{

    auto key = skeletonDataFile + atlasFile;
    auto it  = _skeletonCacheMap.find(key);
    if (it != _skeletonCacheMap.end())
        return it->second.data;

    // CCLOG("load skeletonDataFile: %s", skeletonDataFile.c_str());
    // CCLOG("load atlasFile: %s", atlasFile.c_str());

    auto pAtlas = new spine::Atlas(atlasFile.c_str(), &textureLoader, true);
    CCASSERT(pAtlas, "Error reading atlas file.");

    if (pAtlas == nullptr)
        return nullptr;

    auto pAttachmentLoader             = new spine::Cocos2dAtlasAttachmentLoader(pAtlas);
    spine::SkeletonData* pSkeletonData = NULL;

    if (FileUtils::getInstance()->getFileExtension(skeletonDataFile) == ".json")
    {
        spine::SkeletonJson json(pAttachmentLoader);

        pSkeletonData = json.readSkeletonDataFile(skeletonDataFile.c_str());
        CCASSERT(pSkeletonData,
                 (json.getError().isEmpty() ? json.getError().buffer() : "Error reading skeleton data file."));
    }
    else
    {
        spine::SkeletonBinary binary(pAttachmentLoader);
        binary.setScale(1.0f);

        pSkeletonData = binary.readSkeletonDataFile(skeletonDataFile.c_str());
        CCASSERT(pSkeletonData,
                 (!binary.getError().isEmpty() ? binary.getError().buffer() : "Error reading skeleton data."));
    }

    SkeletonCacheData data;
    data.data              = pSkeletonData;
    data.atlas             = pAtlas;
    data.attachmentLoader  = pAttachmentLoader;
    _skeletonCacheMap[key] = data;

    return data.data;
}

void GCache::preloadSkeletonData(const std::string& skeletonDataFile, const std::string& atlasFile)
{
    if (!UIConfig::useSkeletonCache)
    {
        return;
    }
    auto fileUtils = FileUtils::getInstance();
    if (fileUtils->isFileExist(skeletonDataFile))
    {
        getOrCreateSkeletonData(skeletonDataFile, atlasFile);
    }
}

void GCache::clearSkeletonData()
{
    for (auto& it : _skeletonCacheMap)
    {
        delete it.second.atlas;
        delete it.second.attachmentLoader;
        delete it.second.data;
    }
    _skeletonCacheMap.clear();
}

NS_FGUI_END
