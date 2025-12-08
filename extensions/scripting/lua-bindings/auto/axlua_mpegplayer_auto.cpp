#include "lua-bindings/auto/axlua_mpegplayer_auto.hpp"
#include "extensions/MPEGPlayer/src/MPEGPlayer.h"
#include "lua-bindings/manual/tolua_fix.h"
#include "lua-bindings/manual/LuaBasicConversions.h"

int lua_ax_mpegplayer_MPEGPlayer_setVideoFile(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_setVideoFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ax.MPEGPlayer:setVideoFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_setVideoFile'", nullptr);
            return 0;
        }
        obj->setVideoFile(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:setVideoFile",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_setVideoFile'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_getVideoFile(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_getVideoFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_getVideoFile'", nullptr);
            return 0;
        }
        auto&& ret = obj->getVideoFile();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:getVideoFile",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_getVideoFile'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_setUseAsyncDecoding(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_setUseAsyncDecoding'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "ax.MPEGPlayer:setUseAsyncDecoding");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_setUseAsyncDecoding'", nullptr);
            return 0;
        }
        obj->setUseAsyncDecoding(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:setUseAsyncDecoding",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_setUseAsyncDecoding'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_isUseAsyncDecoding(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_isUseAsyncDecoding'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_isUseAsyncDecoding'", nullptr);
            return 0;
        }
        auto&& ret = obj->isUseAsyncDecoding();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:isUseAsyncDecoding",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_isUseAsyncDecoding'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_getVideoWidth(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_getVideoWidth'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_getVideoWidth'", nullptr);
            return 0;
        }
        auto&& ret = obj->getVideoWidth();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:getVideoWidth",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_getVideoWidth'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_getVideoHeight(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_getVideoHeight'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_getVideoHeight'", nullptr);
            return 0;
        }
        auto&& ret = obj->getVideoHeight();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:getVideoHeight",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_getVideoHeight'.",&tolua_err);
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
        auto&& ret = obj->play();
        tolua_pushboolean(tolua_S,(bool)ret);
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
int lua_ax_mpegplayer_MPEGPlayer_setAudioEnabled(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_setAudioEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "ax.MPEGPlayer:setAudioEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_setAudioEnabled'", nullptr);
            return 0;
        }
        obj->setAudioEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:setAudioEnabled",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_setAudioEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_isAudioEnabled(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_isAudioEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_isAudioEnabled'", nullptr);
            return 0;
        }
        auto&& ret = obj->isAudioEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:isAudioEnabled",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_isAudioEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_setVideoEnabled(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_setVideoEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "ax.MPEGPlayer:setVideoEnabled");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_setVideoEnabled'", nullptr);
            return 0;
        }
        obj->setVideoEnabled(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:setVideoEnabled",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_setVideoEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_isVideoEnabled(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_isVideoEnabled'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_isVideoEnabled'", nullptr);
            return 0;
        }
        auto&& ret = obj->isVideoEnabled();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:isVideoEnabled",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_isVideoEnabled'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_setVolume(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_setVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "ax.MPEGPlayer:setVolume");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_setVolume'", nullptr);
            return 0;
        }
        obj->setVolume(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:setVolume",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_setVolume'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_mpegplayer_MPEGPlayer_getVolume(lua_State* tolua_S)
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
        tolua_error(tolua_S,"invalid 'obj' in function 'lua_ax_mpegplayer_MPEGPlayer_getVolume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_getVolume'", nullptr);
            return 0;
        }
        auto&& ret = obj->getVolume();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.MPEGPlayer:getVolume",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_mpegplayer_MPEGPlayer_getVolume'.",&tolua_err);
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

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_mpegplayer_MPEGPlayer_create'", nullptr);
            return 0;
        }
        auto&& ret = ax::MPEGPlayer::create();
        object_to_luaval<ax::MPEGPlayer>(tolua_S, "ax.MPEGPlayer",(ax::MPEGPlayer*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ax.MPEGPlayer:create",argc, 0);
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
        tolua_function(tolua_S,"setVideoFile",lua_ax_mpegplayer_MPEGPlayer_setVideoFile);
        tolua_function(tolua_S,"getVideoFile",lua_ax_mpegplayer_MPEGPlayer_getVideoFile);
        tolua_function(tolua_S,"setUseAsyncDecoding",lua_ax_mpegplayer_MPEGPlayer_setUseAsyncDecoding);
        tolua_function(tolua_S,"isUseAsyncDecoding",lua_ax_mpegplayer_MPEGPlayer_isUseAsyncDecoding);
        tolua_function(tolua_S,"getVideoWidth",lua_ax_mpegplayer_MPEGPlayer_getVideoWidth);
        tolua_function(tolua_S,"getVideoHeight",lua_ax_mpegplayer_MPEGPlayer_getVideoHeight);
        tolua_function(tolua_S,"play",lua_ax_mpegplayer_MPEGPlayer_play);
        tolua_function(tolua_S,"pausePlayback",lua_ax_mpegplayer_MPEGPlayer_pausePlayback);
        tolua_function(tolua_S,"resumePlayback",lua_ax_mpegplayer_MPEGPlayer_resumePlayback);
        tolua_function(tolua_S,"stop",lua_ax_mpegplayer_MPEGPlayer_stop);
        tolua_function(tolua_S,"seekTo",lua_ax_mpegplayer_MPEGPlayer_seekTo);
        tolua_function(tolua_S,"getCurrentTime",lua_ax_mpegplayer_MPEGPlayer_getCurrentTime);
        tolua_function(tolua_S,"getDuration",lua_ax_mpegplayer_MPEGPlayer_getDuration);
        tolua_function(tolua_S,"isPlaying",lua_ax_mpegplayer_MPEGPlayer_isPlaying);
        tolua_function(tolua_S,"setLooping",lua_ax_mpegplayer_MPEGPlayer_setLooping);
        tolua_function(tolua_S,"isLooping",lua_ax_mpegplayer_MPEGPlayer_isLooping);
        tolua_function(tolua_S,"setAudioEnabled",lua_ax_mpegplayer_MPEGPlayer_setAudioEnabled);
        tolua_function(tolua_S,"isAudioEnabled",lua_ax_mpegplayer_MPEGPlayer_isAudioEnabled);
        tolua_function(tolua_S,"setVideoEnabled",lua_ax_mpegplayer_MPEGPlayer_setVideoEnabled);
        tolua_function(tolua_S,"isVideoEnabled",lua_ax_mpegplayer_MPEGPlayer_isVideoEnabled);
        tolua_function(tolua_S,"setVolume",lua_ax_mpegplayer_MPEGPlayer_setVolume);
        tolua_function(tolua_S,"getVolume",lua_ax_mpegplayer_MPEGPlayer_getVolume);
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

