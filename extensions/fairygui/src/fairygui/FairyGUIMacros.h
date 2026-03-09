#ifndef __FAIRYGUIMACROS_H__
#define __FAIRYGUIMACROS_H__

#include "cocos2d.h"

#define NS_FGUI_BEGIN                     namespace fairygui {
#define NS_FGUI_END                       }
#define USING_NS_FGUI                     using namespace fairygui

#define CALL_LATER_FUNC(__TYPE__,__FUNC__) \
void __selector_##__FUNC__(float dt) \
{\
    ax::Director::getInstance()->getScheduler()->unschedule(AX_SCHEDULE_SELECTOR(__TYPE__::__selector_##__FUNC__), this);\
    __FUNC__(); \
}\
void __FUNC__()

#define CALL_LATER(__TYPE__,__FUNC__,...) \
if (!ax::Director::getInstance()->getScheduler()->isScheduled(AX_SCHEDULE_SELECTOR(__TYPE__::__selector_##__FUNC__), this))\
    ax::Director::getInstance()->getScheduler()->schedule(AX_SCHEDULE_SELECTOR(__TYPE__::__selector_##__FUNC__), this, (__VA_ARGS__+0), false)

#define CALL_LATER_CANCEL(__TYPE__,__FUNC__) \
ax::Director::getInstance()->getScheduler()->unschedule(AX_SCHEDULE_SELECTOR(__TYPE__::__selector_##__FUNC__), this)

#define CALL_PER_FRAME(__TYPE__,__FUNC__) \
if (!ax::Director::getInstance()->getScheduler()->isScheduled(AX_SCHEDULE_SELECTOR(__TYPE__::__FUNC__), this))\
    ax::Director::getInstance()->getScheduler()->schedule(AX_SCHEDULE_SELECTOR(__TYPE__::__FUNC__), this, 0, false)

#define CALL_PER_FRAME_CANCEL(__TYPE__,__FUNC__) \
ax::Director::getInstance()->getScheduler()->unschedule(AX_SCHEDULE_SELECTOR(__TYPE__::__FUNC__), this)

#define SCRIPT_HANDLER_SYNTHESIZE(varName)         \
protected:                                         \
    int _scriptHandler_##varName = 0;              \
                                                   \
public:                                            \
    inline int getScriptHandler##varName() const   \
    {                                              \
        return _scriptHandler_##varName;           \
    }                                              \
    inline void setScriptHandler##varName(int var) \
    {                                              \
        _scriptHandler_##varName = var;            \
    }

#define SCRIPT_MAP_HANDLER_SYNTHESIZE(varName)                                       \
protected:                                                                           \
    std::unordered_map<std::string, int> _scriptHandlerMap_##varName;                \
                                                                                     \
public:                                                                              \
    inline int getScriptHandler##varName##ByName(const std::string& key) const       \
    {                                                                                \
        auto it = _scriptHandlerMap_##varName.find(key);                             \
        if (it == _scriptHandlerMap_##varName.end())                                 \
        {                                                                            \
            return 0;                                                                \
        }                                                                            \
        else                                                                         \
        {                                                                            \
            return it->second;                                                       \
        }                                                                            \
    }                                                                                \
    inline void setScriptHandler##varName##ByName(const std::string& key, int value) \
    {                                                                                \
        _scriptHandlerMap_##varName.insert(std::make_pair(key, value));              \
    }                                                                                \
    inline void clearScriptHandlerMap##varName()                                     \
    {                                                                                \
        _scriptHandlerMap_##varName.clear();                                         \
    }

#define UIRoot GRoot::getInstance()

#include "FieldTypes.h"

#endif