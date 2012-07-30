#include "lua_object.h"
#include "game_engine.h"

namespace lua_object_var
{
    game_engine * gm_engine;
}

static int printl (lua_State *L)
{
    std:: cout << lua_tostring(L,-1);
    //double d = lua_tonumber(L, 1);  /* get argument */
    //lua_pushnumber(L, sin(d));  /* push result */
    return 0;  /* number of results */
}

static int blit_lua(lua_State *L)
{
    float x,y;
    std::string image;
    bool no_move;

    x=lua_tonumber(L,-4);
    y=lua_tonumber(L,-3);
    image=lua_tostring(L,-2);
    no_move=lua_toboolean(L,-1);

    char flags=0;

    if (no_move)
        flags=BLIT_ABSOLUTE;
    lua_object_var::gm_engine->blit(x,y,lua_object_var::gm_engine->get_surface(image),flags);

    return 0;
}

static int keyboard_lua(lua_State * L)
{
    int lua_req=lua_tointeger(L, -1);

    Uint8 *keystate = SDL_GetKeyState(NULL);

    if (lua_req < 0 or lua_req > SDLK_LAST)
    {
        lua_pushinteger(L, 0);
        return 1;
    }

    lua_pushinteger(L, keystate[lua_req]);

    return 1;
}


lua_object::lua_object(game_engine * gm_engine_, std::string filename,float xx,float yy, float zz)
{
    gm_engine=gm_engine_;
    lua_object_var::gm_engine=gm_engine;
    scriptname= filename;
    script_error=0;
    x=xx;//xx;
    y=yy;//yy;

    delete_this=0;
    persistant=0;
    no_collide=0;
    std::string id_type=""; //FIX

    sprite=gm_engine->get_surface("ship1");
    L = lua_open();
    luaL_openlibs(L);

    lua_pushcfunction(L, printl);
    lua_setglobal(L, "printl");

    lua_pushcfunction(L, blit_lua);
    lua_setglobal(L, "blit");

    lua_pushcfunction(L, keyboard_lua);
    lua_setglobal(L, "get_keyboard");

    if (!luaL_dofile(L,filename.c_str())) //execute script
    {
        lua_getglobal(L,"update");
        lua_getglobal(L,"init");
        if (!lua_isfunction(L, -1))
        {
            script_error=true;
            new message_log(MESSAGE_WARNING,"`init` should be a function");
        }

        if (!lua_isfunction(L, -2))
        {
            script_error=true;
            new message_log(MESSAGE_WARNING,"`update` should be a function");
        }

        lua_pushnumber(L,xx);
        lua_setglobal(L,"x");
        lua_pushnumber(L,yy);
        lua_setglobal(L,"y");
        lua_pushnumber(L,zz);
        lua_setglobal(L,"z");
    }
    else
    {
        script_error=true;
        new message_log(MESSAGE_WARNING,"cannot execute `"+filename+"`");
    }

    if (!script_error)
    {
        lua_getglobal (L, "init");
        lua_call (L, 0, 0);
    }

}

void lua_object::update()
{
    if (script_error)
        return;


    lua_getglobal (L, "update");

    lua_call (L, 0, 0);

    lua_getglobal (L, "z");
    lua_getglobal (L, "y");
    lua_getglobal (L, "x");

    x=lua_tonumber(L,-1);
    y=lua_tonumber(L,-2);
    z=lua_tonumber(L,-3);

    //gm_engine->blit(x,y,sprite);
}

lua_object::~lua_object()
{
    lua_close(L);
}
