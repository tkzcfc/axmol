#include "lua-bindings/auto/axlua_webm_auto.hpp"
#include "extensions/webm/src/Webm.h"
#include "lua-bindings/manual/tolua_fix.h"
#include "lua-bindings/manual/LuaBasicConversions.h"

int lua_ax_webm_Webm_initWithWebm(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_initWithWebm'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ax.Webm:initWithWebm");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_initWithWebm'", nullptr);
            return 0;
        }
        auto&& ret = cobj->initWithWebm(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ax.Webm:initWithWebm");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ax.Webm:initWithWebm");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_initWithWebm'", nullptr);
            return 0;
        }
        auto&& ret = cobj->initWithWebm(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:initWithWebm",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_initWithWebm'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_initWithWebmAsync(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_initWithWebmAsync'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ax.Webm:initWithWebmAsync");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_initWithWebmAsync'", nullptr);
            return 0;
        }
        auto&& ret = cobj->initWithWebmAsync(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 2) 
    {
        std::string arg0;
        int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ax.Webm:initWithWebmAsync");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ax.Webm:initWithWebmAsync");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_initWithWebmAsync'", nullptr);
            return 0;
        }
        auto&& ret = cobj->initWithWebmAsync(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:initWithWebmAsync",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_initWithWebmAsync'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_play(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_play'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_play'", nullptr);
            return 0;
        }
        cobj->play();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ax.Webm:play");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_play'", nullptr);
            return 0;
        }
        cobj->play(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:play",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_play'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_rePlay(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_rePlay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_rePlay'", nullptr);
            return 0;
        }
        cobj->rePlay();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ax.Webm:rePlay");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_rePlay'", nullptr);
            return 0;
        }
        cobj->rePlay(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:rePlay",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_rePlay'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_setLoop(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_setLoop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ax.Webm:setLoop");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_setLoop'", nullptr);
            return 0;
        }
        cobj->setLoop(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:setLoop",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_setLoop'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_getLoop(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_getLoop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_getLoop'", nullptr);
            return 0;
        }
        auto&& ret = cobj->getLoop();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:getLoop",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_getLoop'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_isPlay(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_isPlay'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_isPlay'", nullptr);
            return 0;
        }
        auto&& ret = cobj->isPlay();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:isPlay",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_isPlay'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_stop(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_stop'", nullptr);
            return 0;
        }
        cobj->stop();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:stop",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_suspend(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_suspend'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_suspend'", nullptr);
            return 0;
        }
        cobj->suspend();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:suspend",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_suspend'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_setFrame(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_setFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ax.Webm:setFrame");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_setFrame'", nullptr);
            return 0;
        }
        auto&& ret = cobj->setFrame(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:setFrame",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_setFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_nextFrame(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_nextFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_nextFrame'", nullptr);
            return 0;
        }
        auto&& ret = cobj->nextFrame();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:nextFrame",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_nextFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_preFrame(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_preFrame'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_preFrame'", nullptr);
            return 0;
        }
        auto&& ret = cobj->preFrame();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:preFrame",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_preFrame'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_setPlayScale(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_setPlayScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "ax.Webm:setPlayScale");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_setPlayScale'", nullptr);
            return 0;
        }
        cobj->setPlayScale(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:setPlayScale",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_setPlayScale'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_getPlayScale(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_getPlayScale'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_getPlayScale'", nullptr);
            return 0;
        }
        auto&& ret = cobj->getPlayScale();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:getPlayScale",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_getPlayScale'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_setReverse(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_setReverse'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "ax.Webm:setReverse");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_setReverse'", nullptr);
            return 0;
        }
        cobj->setReverse(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:setReverse",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_setReverse'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_setFps(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_setFps'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ax.Webm:setFps");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_setFps'", nullptr);
            return 0;
        }
        cobj->setFps(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:setFps",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_setFps'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_getFrameCount(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_getFrameCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_getFrameCount'", nullptr);
            return 0;
        }
        auto&& ret = cobj->getFrameCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:getFrameCount",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_getFrameCount'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_isLoadFinish(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_isLoadFinish'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_isLoadFinish'", nullptr);
            return 0;
        }
        auto&& ret = cobj->isLoadFinish();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:isLoadFinish",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_isLoadFinish'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_setKeepContentSize(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_setKeepContentSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "ax.Webm:setKeepContentSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_setKeepContentSize'", nullptr);
            return 0;
        }
        cobj->setKeepContentSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:setKeepContentSize",argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_setKeepContentSize'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_getWebmPath(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S,1,0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_ax_webm_Webm_getWebmPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_getWebmPath'", nullptr);
            return 0;
        }
        auto&& ret = cobj->getWebmPath();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:getWebmPath",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_getWebmPath'.",&tolua_err);
#endif

    return 0;
}
int lua_ax_webm_Webm_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if _AX_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ax.Webm:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_create'", nullptr);
            return 0;
        }
        auto&& ret = ax::Webm::create(arg0);
        object_to_luaval<ax::Webm>(tolua_S, "ax.Webm",(ax::Webm*)ret);
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        int arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ax.Webm:create");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ax.Webm:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_create'", nullptr);
            return 0;
        }
        auto&& ret = ax::Webm::create(arg0, arg1);
        object_to_luaval<ax::Webm>(tolua_S, "ax.Webm",(ax::Webm*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ax.Webm:create",argc, 1);
    return 0;
#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_create'.",&tolua_err);
#endif
    return 0;
}
int lua_ax_webm_Webm_createAsync(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if _AX_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ax.Webm:createAsync");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_createAsync'", nullptr);
            return 0;
        }
        auto&& ret = ax::Webm::createAsync(arg0);
        object_to_luaval<ax::Webm>(tolua_S, "ax.Webm",(ax::Webm*)ret);
        return 1;
    }
    if (argc == 2)
    {
        std::string arg0;
        int arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "ax.Webm:createAsync");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "ax.Webm:createAsync");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_createAsync'", nullptr);
            return 0;
        }
        auto&& ret = ax::Webm::createAsync(arg0, arg1);
        object_to_luaval<ax::Webm>(tolua_S, "ax.Webm",(ax::Webm*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ax.Webm:createAsync",argc, 1);
    return 0;
#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_createAsync'.",&tolua_err);
#endif
    return 0;
}
int lua_ax_webm_Webm_cancelAllAsync(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if _AX_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_cancelAllAsync'", nullptr);
            return 0;
        }
        ax::Webm::cancelAllAsync();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ax.Webm:cancelAllAsync",argc, 0);
    return 0;
#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_cancelAllAsync'.",&tolua_err);
#endif
    return 0;
}
int lua_ax_webm_Webm_setSkipFramesPerTimes(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if _AX_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ax.Webm:setSkipFramesPerTimes");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_setSkipFramesPerTimes'", nullptr);
            return 0;
        }
        ax::Webm::setSkipFramesPerTimes(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ax.Webm:setSkipFramesPerTimes",argc, 1);
    return 0;
#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_setSkipFramesPerTimes'.",&tolua_err);
#endif
    return 0;
}
int lua_ax_webm_Webm_setLoadFinishAutoCreateTexture(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if _AX_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        bool arg0;
        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "ax.Webm:setLoadFinishAutoCreateTexture");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_setLoadFinishAutoCreateTexture'", nullptr);
            return 0;
        }
        ax::Webm::setLoadFinishAutoCreateTexture(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ax.Webm:setLoadFinishAutoCreateTexture",argc, 1);
    return 0;
#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_setLoadFinishAutoCreateTexture'.",&tolua_err);
#endif
    return 0;
}
int lua_ax_webm_Webm_removeAllWebmTexture(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if _AX_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_removeAllWebmTexture'", nullptr);
            return 0;
        }
        ax::Webm::removeAllWebmTexture();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ax.Webm:removeAllWebmTexture",argc, 0);
    return 0;
#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_removeAllWebmTexture'.",&tolua_err);
#endif
    return 0;
}
int lua_ax_webm_Webm_setDecodeThreadCount(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if _AX_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"ax.Webm",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        int arg0;
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "ax.Webm:setDecodeThreadCount");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_setDecodeThreadCount'", nullptr);
            return 0;
        }
        ax::Webm::setDecodeThreadCount(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ax.Webm:setDecodeThreadCount",argc, 1);
    return 0;
#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_setDecodeThreadCount'.",&tolua_err);
#endif
    return 0;
}
int lua_ax_webm_Webm_constructor(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok  = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_ax_webm_Webm_constructor'", nullptr);
            return 0;
        }
        cobj = new ax::Webm();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_object(tolua_S, ID, luaID, (void*)cobj,"ax.Webm");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:Webm",argc, 0);
    return 0;

#if _AX_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_ax_webm_Webm_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_ax_webm_Webm_finalize(lua_State* tolua_S)
{
    AXLOGV("luabindings: finalizing LUA object (Webm)");
    return 0;
}

int lua_register_ax_webm_Webm(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"ax.Webm");
    tolua_cclass(tolua_S,"Webm","ax.Webm","ax.Sprite",nullptr);

    tolua_beginmodule(tolua_S,"Webm");
        tolua_function(tolua_S,"new",lua_ax_webm_Webm_constructor);
        tolua_function(tolua_S,"initWithWebm",lua_ax_webm_Webm_initWithWebm);
        tolua_function(tolua_S,"initWithWebmAsync",lua_ax_webm_Webm_initWithWebmAsync);
        tolua_function(tolua_S,"play",lua_ax_webm_Webm_play);
        tolua_function(tolua_S,"rePlay",lua_ax_webm_Webm_rePlay);
        tolua_function(tolua_S,"setLoop",lua_ax_webm_Webm_setLoop);
        tolua_function(tolua_S,"getLoop",lua_ax_webm_Webm_getLoop);
        tolua_function(tolua_S,"isPlay",lua_ax_webm_Webm_isPlay);
        tolua_function(tolua_S,"stop",lua_ax_webm_Webm_stop);
        tolua_function(tolua_S,"suspend",lua_ax_webm_Webm_suspend);
        tolua_function(tolua_S,"setFrame",lua_ax_webm_Webm_setFrame);
        tolua_function(tolua_S,"nextFrame",lua_ax_webm_Webm_nextFrame);
        tolua_function(tolua_S,"preFrame",lua_ax_webm_Webm_preFrame);
        tolua_function(tolua_S,"setPlayScale",lua_ax_webm_Webm_setPlayScale);
        tolua_function(tolua_S,"getPlayScale",lua_ax_webm_Webm_getPlayScale);
        tolua_function(tolua_S,"setReverse",lua_ax_webm_Webm_setReverse);
        tolua_function(tolua_S,"setFps",lua_ax_webm_Webm_setFps);
        tolua_function(tolua_S,"getFrameCount",lua_ax_webm_Webm_getFrameCount);
        tolua_function(tolua_S,"isLoadFinish",lua_ax_webm_Webm_isLoadFinish);
        tolua_function(tolua_S,"setKeepContentSize",lua_ax_webm_Webm_setKeepContentSize);
        tolua_function(tolua_S,"getWebmPath",lua_ax_webm_Webm_getWebmPath);
        tolua_function(tolua_S,"create", lua_ax_webm_Webm_create);
        tolua_function(tolua_S,"createAsync", lua_ax_webm_Webm_createAsync);
        tolua_function(tolua_S,"cancelAllAsync", lua_ax_webm_Webm_cancelAllAsync);
        tolua_function(tolua_S,"setSkipFramesPerTimes", lua_ax_webm_Webm_setSkipFramesPerTimes);
        tolua_function(tolua_S,"setLoadFinishAutoCreateTexture", lua_ax_webm_Webm_setLoadFinishAutoCreateTexture);
        tolua_function(tolua_S,"removeAllWebmTexture", lua_ax_webm_Webm_removeAllWebmTexture);
        tolua_function(tolua_S,"setDecodeThreadCount", lua_ax_webm_Webm_setDecodeThreadCount);
    tolua_endmodule(tolua_S);
    auto typeName = typeid(ax::Webm).name(); // rtti is literal storage
    g_luaType[reinterpret_cast<uintptr_t>(typeName)] = "ax.Webm";
    g_typeCast[typeName] = "ax.Webm";
    return 1;
}
TOLUA_API int register_all_ax_webm(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ax",0);
	tolua_beginmodule(tolua_S,"ax");

	lua_register_ax_webm_Webm(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

