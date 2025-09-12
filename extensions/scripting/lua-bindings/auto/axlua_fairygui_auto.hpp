#pragma once
#if defined(AX_USE_ENGINE_FAIRYGUI_LUA_BINDING)
#include "base/Config.h"
#include "tolua++.h"
int register_all_ax_fairygui(lua_State* tolua_S);
#endif //#if defined(AX_USE_ENGINE_FAIRYGUI_LUA_BINDING)
