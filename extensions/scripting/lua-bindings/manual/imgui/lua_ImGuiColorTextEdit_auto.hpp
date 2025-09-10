#pragma once
#include "base/Config.h"
#include "lua_conversion.hpp"

extern int luaReg_imguiTextEditor_imguiTextEditor(lua_State* lua_S);

inline int luaReg_imguiTextEditor(lua_State* lua_S)
{
	luaReg_imguiTextEditor_imguiTextEditor(lua_S);
	return 0;
}
