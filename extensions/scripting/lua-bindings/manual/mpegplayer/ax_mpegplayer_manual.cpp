#include "lua-bindings/manual/mpegplayer/ax_mpegplayer_manual.hpp"
#include "lua-bindings/auto/axlua_mpegplayer_auto.hpp"

#include "lua-bindings/manual/tolua_fix.h"
#include "lua-bindings/manual/LuaBasicConversions.h"
#include "lua-bindings/manual/base/LuaScriptHandlerMgr.h"
#include "lua-bindings/manual/LuaValue.h"
#include "extensions/MPEGPlayer/src/MPEGPlayer.h"
#include "lua-bindings/manual/LuaEngine.h"

static int register_all_ax_mpegplayer_manual(lua_State* L)
{
    if (nullptr == L)
        return 0;

    //lua_pushstring(L, "ax.MPEGPlayer");
    //lua_rawget(L, LUA_REGISTRYINDEX);
    //if (lua_istable(L, -1))
    //{
    //}
    //lua_pop(L, 1);

    return 1;
}

int register_mpegplayer_module(lua_State* L)
{
    lua_getglobal(L, "_G");
    if (lua_istable(L, -1))  // stack:...,_G,
    {
        register_all_ax_mpegplayer(L);
        register_all_ax_mpegplayer_manual(L);
    }
    lua_pop(L, 1);
    return 1;
}
