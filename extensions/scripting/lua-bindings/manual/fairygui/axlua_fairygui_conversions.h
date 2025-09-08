#pragma once

#if defined(AX_USE_ENGINE_FAIRYGUI_LUA_BINDING)
#include "lua-bindings/manual/tolua_fix.h"
#include "fairygui/FairyGUI.h"

extern void margin_to_luaval(lua_State* L, const fairygui::Margin& _margin);
extern bool luaval_to_margin(lua_State* L, int lo, fairygui::Margin* outValue, const char* funcName = "");

#endif  // defined(AX_USE_ENGINE_FAIRYGUI_LUA_BINDING)
