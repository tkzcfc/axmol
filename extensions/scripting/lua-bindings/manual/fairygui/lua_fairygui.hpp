#pragma once
#if defined(AX_ENABLE_EXT_FAIRYGUI)
#ifndef AX_USE_ENGINE_FAIRYGUI_LUA_BINDING

#include "tolua++.h"

int register_fairygui_manual(lua_State* tolua_S);

#endif
#endif
