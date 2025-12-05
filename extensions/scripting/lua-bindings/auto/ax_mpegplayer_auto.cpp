#include "lua-bindings/auto/ax_mpegplayer_auto.hpp"
#include "extensions/MPEGPlayer/src/MPEGPlayer.h"
#include "lua-bindings/manual/tolua_fix.h"
#include "lua-bindings/manual/LuaBasicConversions.h"

int lua_ax_mpegplayer_MPEGPlayer_initWithMPEG(lua_State* tolua_S)
{
    int argc = 0;
    ax::MPEGPlayer* obj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.MPEGPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    obj = (ax::MPEGPlayer*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!obj)
    {
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_initWithMPEG'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ax.MPEGPlayer:initWithMPEG");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_initWithMPEG'", nullptr);
            return 0;
        }
        auto&& ret = obj->initWithMPEG(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:initWithMPEG",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_initWithMPEG'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if _AX_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ax.MPEGPlayer",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ax.MPEGPlayer:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_create'", nullptr);
            return 0;
        }
        auto&& ret = ax::MPEGPlayer::create(arg0);
        object_to_luaval<ax::MPEGPlayer>(tolua_S, "ax.MPEGPlayer",(ax::MPEGPlayer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ax.MPEGPlayer:create",argc, 1);
    return 0;
#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_create'.",&tolua_err);
#endif
    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_constructor(lua_State* tolua_S)
{
    int argc = 0;
    ax::MPEGPlayer* obj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_constructor'", nullptr);
            return 0;
        }
        obj = new ax::MPEGPlayer();
        obj->autorelease();
        int ID =  (int)obj->_ID ;
        int* luaID =  &obj->_luaID ;
        toluafix_pushusertype_object(tolua_S, ID, luaID, (void*)obj,"ax.MPEGPlayer");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:MPEGPlayer",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_ax_mpegplayer_MPEGPlayer_finalize(lua_State* tolua_S)
{
    AXLOGV("luabindings: finalizing LUA object (MPEGPlayer)");
    return 0;
}

int lua_register_ax_mpegplayer_MPEGPlayer(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ax.MPEGPlayer");
    tolua_cclass(tolua_S,"MPEGPlayer","ax.MPEGPlayer","ax.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"MPEGPlayer");
        tolua_function(tolua_S,"new",lua_ax_mpegplayer_MPEGPlayer_constructor);
        tolua_function(tolua_S,"initWithMPEG",lua_ax_mpegplayer_MPEGPlayer_initWithMPEG);
        tolua_function(tolua_S,"create", lua_ax_mpegplayer_MPEGPlayer_create);
    tolua_endmodule(tolua_S);
    auto typeName = typeid(ax::MPEGPlayer).name(); // rtti is literal storage
    g_luaType[reinterpret_cast<uintptr_t>(typeName)] = "ax.MPEGPlayer";
    g_typeCast[typeName] = "ax.MPEGPlayer";
    return 1;
}
TOLUA_API int register_all_ax_mpegplayer(lua_State* tolua_S)
{
    tolua_open(tolua_S);

    tolua_module(tolua_S,"ax",0);
    tolua_beginmodule(tolua_S,"ax");

    lua_register_ax_mpegplayer_MPEGPlayer(tolua_S);

    tolua_endmodule(tolua_S);
    return 1;
}

