#include "lua-bindings/manual/webm/ax_webm_manual.hpp"
#include "lua-bindings/auto/axlua_webm_auto.hpp"

#include "lua-bindings/manual/tolua_fix.h"
#include "lua-bindings/manual/LuaBasicConversions.h"
#include "lua-bindings/manual/base/LuaScriptHandlerMgr.h"
#include "lua-bindings/manual/LuaValue.h"
#include "extensions/webm/src/Webm.h"
#include "lua-bindings/manual/LuaEngine.h"

int lua_ax_webm_Webm_setOnPlayEnd(lua_State* tolua_S)
{
    int argc = 0;
    ax::Webm* cobj = nullptr;
    bool ok = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "ax.Webm", 0, &tolua_err)) goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S, 1, 0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_ax_webm_Webm_setOnPlayEnd'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        if (lua_isnil(tolua_S, 2))
        {
            cobj->setOnPlayEnd(nullptr);
            return 0;
        }
        LUA_FUNCTION handler = (toluafix_ref_function(tolua_S, 2, 0));
        if (0 == handler) {
            tolua_error(tolua_S, "invalid arguments in function 'lua_ax_webm_Webm_setOnPlayEnd'", nullptr);
            return 0;
        }

        cobj->setOnPlayEnd([handler]() {
            LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 0);
            });
        ScriptHandlerMgr::getInstance()->addCustomHandler((void*)cobj, handler);

        lua_settop(tolua_S, 1);
        return 1;
    }
    else
    {
        cobj->setOnPlayEnd(nullptr);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:setOnPlayEnd", argc, 1);
    return 0;

#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_ax_webm_Webm_setOnPlayEnd'.", &tolua_err);
#endif

    return 0;
}

int lua_ax_webm_Webm_setOnEventCallback(lua_State* tolua_S)
{
    int argc       = 0;
    ax::Webm* cobj = nullptr;
    bool ok        = true;

#if _AX_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if _AX_DEBUG >= 1
    if (!tolua_isusertype(tolua_S, 1, "ax.Webm", 0, &tolua_err))
        goto tolua_lerror;
#endif

    cobj = (ax::Webm*)tolua_tousertype(tolua_S, 1, 0);

#if _AX_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S, "invalid 'cobj' in function 'lua_ax_webm_Webm_setOnEventCallback'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        if (lua_isnil(tolua_S, 2))
        {
            cobj->setOnEventCallback(nullptr);
            return 0;
        }
        LUA_FUNCTION handler = (toluafix_ref_function(tolua_S, 2, 0));
        if (0 == handler)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_ax_webm_Webm_setOnPlayEnd'", nullptr);
            return 0;
        }

        cobj->setOnEventCallback([handler](const std::string& eventName) {
            LuaEngine::getInstance()->getLuaStack()->pushString(eventName);
            LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 1);
        });
        ScriptHandlerMgr::getInstance()->addCustomHandler((void*)cobj, handler);

        lua_settop(tolua_S, 1);
        return 1;
    }
    else
    {
        cobj->setOnEventCallback(nullptr);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "ax.Webm:setOnEventCallback", argc,
               1);
    return 0;

#if _AX_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_ax_webm_Webm_setOnEventCallback'.", &tolua_err);
#endif

    return 0;
}

int lua_ax_webm_Webm_preloadAsync(lua_State* tolua_S)
{
    int argc = 0;
    bool ok = true;

    tolua_Error tolua_err;

#if _AX_DEBUG >= 1
    if (!tolua_isusertable(tolua_S, 1, "ax.Webm", 0, &tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2, &arg0, "ax.Webm:preloadAsync");
        if (ok && !toluafix_isfunction(tolua_S, 3, "LUA_FUNCTION", 0, &tolua_err))
        {
            ok = false;
        }

        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_ax_webm_Webm_preloadAsync'", nullptr);
            return 0;
        }

        LUA_FUNCTION handler = (toluafix_ref_function(tolua_S, 3, 0));

        Webm::preloadAsync(arg0, [=](bool success) {
            auto stack = ax::LuaEngine::getInstance()->getLuaStack();
        stack->pushBoolean(success);
        stack->executeFunctionByHandler(handler, 1);
        stack->removeScriptHandler(handler);
            });
        return 0;
    }
    if (argc == 3)
    {
        std::string arg0;
        int arg2;
        ok &= luaval_to_std_string(tolua_S, 2, &arg0, "ax.Webm:preloadAsync");
        ok &= luaval_to_int32(tolua_S, 4, (int*)&arg2, "ax.Webm:preloadAsync");

        if (ok && !toluafix_isfunction(tolua_S, 3, "LUA_FUNCTION", 0, &tolua_err))
        {
            ok = false;
        }
        if (!ok)
        {
            tolua_error(tolua_S, "invalid arguments in function 'lua_ax_webm_Webm_preloadAsync'", nullptr);
            return 0;
        }
        LUA_FUNCTION handler = (toluafix_ref_function(tolua_S, 3, 0));

        Webm::preloadAsync(arg0, [=](bool success) {
            auto stack = ax::LuaEngine::getInstance()->getLuaStack();
        stack->pushBoolean(success);
        stack->executeFunctionByHandler(handler, 1);
        stack->removeScriptHandler(handler);
            }, arg2);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "ax.Webm:preloadAsync", argc, 2);
    return 0;
#if _AX_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S, "#ferror in function 'lua_ax_webm_Webm_preloadAsync'.", &tolua_err);
#endif
    return 0;
}

static int register_all_ax_webm_manual(lua_State* L)
{
    if (nullptr == L)
        return 0;

    lua_pushstring(L, "ax.Webm");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L, -1))
    {
        tolua_function(L, "setOnPlayEnd", lua_ax_webm_Webm_setOnPlayEnd);
        tolua_function(L, "setOnEventCallback", lua_ax_webm_Webm_setOnEventCallback);
        tolua_function(L, "preloadAsync", lua_ax_webm_Webm_preloadAsync);
    }
    lua_pop(L, 1);

    return 1;
}

int register_webm_module(lua_State* L)
{
    lua_getglobal(L, "_G");
    if (lua_istable(L, -1))  // stack:...,_G,
    {
        register_all_ax_webm(L);
        register_all_ax_webm_manual(L);
    }
    lua_pop(L, 1);
    return 1;
}
