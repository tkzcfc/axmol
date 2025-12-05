#include "lua-bindings/auto/axlua_mpegplayer_auto.hpp"
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
    if (argc == 2)
    {
        std::string arg0;
        bool arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ax.MPEGPlayer:initWithMPEG");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "ax.MPEGPlayer:initWithMPEG");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_initWithMPEG'", nullptr);
            return 0;
        }
        auto&& ret = obj->initWithMPEG(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:initWithMPEG",argc, 2);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_initWithMPEG'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_setLooping(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_setLooping'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "ax.MPEGPlayer:setLooping");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_setLooping'", nullptr);
            return 0;
        }
        obj->setLooping(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:setLooping",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_setLooping'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_play(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_play'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_play'", nullptr);
            return 0;
        }
        obj->play();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:play",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_play'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_pausePlayback(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_pausePlayback'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_pausePlayback'", nullptr);
            return 0;
        }
        obj->pausePlayback();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:pausePlayback",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_pausePlayback'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_resumePlayback(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_resumePlayback'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_resumePlayback'", nullptr);
            return 0;
        }
        obj->resumePlayback();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:resumePlayback",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_resumePlayback'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_stop(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_stop'", nullptr);
            return 0;
        }
        obj->stop();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:stop",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_seekTo(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_seekTo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "ax.MPEGPlayer:seekTo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_seekTo'", nullptr);
            return 0;
        }
        obj->seekTo(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:seekTo",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_seekTo'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_getCurrentTime(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_getCurrentTime'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_getCurrentTime'", nullptr);
            return 0;
        }
        auto&& ret = obj->getCurrentTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:getCurrentTime",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_getCurrentTime'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_getDuration(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_getDuration'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_getDuration'", nullptr);
            return 0;
        }
        auto&& ret = obj->getDuration();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:getDuration",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_getDuration'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_isPlaying(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_isPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_isPlaying'", nullptr);
            return 0;
        }
        auto&& ret = obj->isPlaying();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:isPlaying",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_isPlaying'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_isLooping(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_isLooping'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_isLooping'", nullptr);
            return 0;
        }
        auto&& ret = obj->isLooping();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:isLooping",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_isLooping'.",&tolua_err);
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
    if (argc == 2)
    {
        std::string arg0;
        bool arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ax.MPEGPlayer:create");
        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "ax.MPEGPlayer:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_create'", nullptr);
            return 0;
        }
        auto&& ret = ax::MPEGPlayer::create(arg0, arg1);
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
        tolua_function(tolua_S,"setLooping",lua_ax_mpegplayer_MPEGPlayer_setLooping);
        tolua_function(tolua_S,"play",lua_ax_mpegplayer_MPEGPlayer_play);
        tolua_function(tolua_S,"pausePlayback",lua_ax_mpegplayer_MPEGPlayer_pausePlayback);
        tolua_function(tolua_S,"resumePlayback",lua_ax_mpegplayer_MPEGPlayer_resumePlayback);
        tolua_function(tolua_S,"stop",lua_ax_mpegplayer_MPEGPlayer_stop);
        tolua_function(tolua_S,"seekTo",lua_ax_mpegplayer_MPEGPlayer_seekTo);
        tolua_function(tolua_S,"getCurrentTime",lua_ax_mpegplayer_MPEGPlayer_getCurrentTime);
        tolua_function(tolua_S,"getDuration",lua_ax_mpegplayer_MPEGPlayer_getDuration);
        tolua_function(tolua_S,"isPlaying",lua_ax_mpegplayer_MPEGPlayer_isPlaying);
        tolua_function(tolua_S,"isLooping",lua_ax_mpegplayer_MPEGPlayer_isLooping);
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

