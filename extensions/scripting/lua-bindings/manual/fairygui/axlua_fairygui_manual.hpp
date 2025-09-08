#pragma once
#if defined(AX_ENABLE_EXT_FAIRYGUI)
#if defined(AX_USE_ENGINE_FAIRYGUI_LUA_BINDING)
#include "tolua++.h"

TOLUA_API int register_fairygui_module(lua_State* L);

#endif  // defined(AX_USE_ENGINE_FAIRYGUI_LUA_BINDING)
#endif // defined(AX_ENABLE_EXT_FAIRYGUI)

