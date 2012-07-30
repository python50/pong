/**
 ** Code Copyright (C) 2011 Jason White <whitewaterssoftwareinfo@gmail.com>
 **                         White Waters Software - http://wwsoft.co.cc
 **
 ** modifying, copying and distribution of this source is prohibited without
 ** explicit authorization by the copyright holder: Jason White
 **/

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "lfs.h"
}

#include "message_log.h"
#include "config_file.h"
#include "game_engine.h"

using namespace std;

namespace config_file_gm_engine
{
    game_engine * gm_engine=NULL;
}

/*
    TODO: Error Checking - sane datatypes
*/

static int config_file_load_surface (lua_State *L)
{
    const char * name = lua_tostring(L, 2);
    string path = lua_tostring(L, 1);

    //cout << "SURF: Name: " << name << " Path: " << path << "\n";

    config_file_gm_engine::gm_engine->load_surface(path,name);

    //lua_pushnumber(L, sin(d));
    return 0;
}

static int config_file_load_sound (lua_State *L)
{
    const char * name = lua_tostring(L, 2);
    string path = lua_tostring(L, 1);

    //cout << "SOUND: Name: " << name << " Path: " << path << "\n";

    config_file_gm_engine::gm_engine->load_sound(path,name);

    //lua_pushnumber(L, sin(d));
    return 0;
}

static int config_file_load_music (lua_State *L)
{
    const char *  name = lua_tostring(L, 2);
    string path = lua_tostring(L, 1);

    //cout << "MUSIC: Name: " << name << " Path: " << path << "\n";

    config_file_gm_engine::gm_engine->load_music(path,name);

    //lua_pushnumber(L, sin(d));
    return 0;
}

static int config_file_load_font (lua_State *L)
{
    unsigned int size = lua_tonumber(L, 3);
    const char * name = lua_tostring(L, 2);
    string path = lua_tostring(L, 1);

    //cout << "FONT: Name: " << name << " Path: " << path << " Size:" << size << "\n";

    config_file_gm_engine::gm_engine->load_font(path,name,size);

    //lua_pushnumber(L, sin(d));
    return 0;
}


/*-----------*/

config_file::config_file(game_engine * gm_engine_, string name)
{
    new message_log(MESSAGE_DEBUG0,"New Config File: "+name);
    //should do error checking on `name`

    gm_engine= gm_engine_;
    config_file_gm_engine::gm_engine=gm_engine;

    L = lua_open();
    luaL_openlibs(L);
    luaopen_lfs(L);

    lua_pushcfunction(L, config_file_load_surface );
    lua_setglobal(L,"load_surface");

    lua_pushcfunction(L, config_file_load_sound );
    lua_setglobal(L,"load_sound");

    lua_pushcfunction(L, config_file_load_music );
    lua_setglobal(L,"load_music");

    lua_pushcfunction(L, config_file_load_font );
    lua_setglobal(L,"load_font");

    filename=name;
}

void config_file::run()
{
    new message_log(MESSAGE_DEBUG0,"Executing Config File `"+filename+"`");
    if (!luaL_dofile(L,filename.c_str())) //execute config file
    {
        //Nothing
    }
    else
    {
        std::string errormessage=lua_tostring(L,-1);
        new message_log(MESSAGE_WARNING,"cannot execute `"+filename+"`\n\t"+errormessage);
    }
}

int config_file::get_int(string var_name)
{
    new message_log(MESSAGE_DEBUG0,"Config File `"+filename+"`: getting `"+var_name+"`");

    int number=0;

    if (!luaL_dofile(L,filename.c_str())) //execute config file
    {
        lua_getglobal(L,var_name.c_str());
        if (!lua_isnumber(L, -1))
        {
            new message_log(MESSAGE_WARNING,filename+": `"+var_name+"` should be a number");
        }
        else
            number=(int)lua_tonumber(L, -1);
    }
    else
    {
        std::string errormessage=lua_tostring(L,-1);
        new message_log(MESSAGE_WARNING,"cannot execute `"+filename+"`\n\t"+errormessage);
    }

    return number;
}

float config_file::get_float(string var_name)
{
    float number=0;

    if (!luaL_dofile(L,filename.c_str())) //execute config file
    {
        lua_getglobal(L,var_name.c_str());
        if (!lua_isnumber(L, -1))
        {
            new message_log(MESSAGE_WARNING,filename+": `"+var_name+"` should be a number");
        }
        else
            number=(float)lua_tonumber(L, -1);
    }
    else
    {
        std::string errormessage=lua_tostring(L,-1);
        new message_log(MESSAGE_WARNING,"cannot execute `"+filename+"`\n\t"+errormessage);
    }

    return number;
}

string config_file::get_string(string var_name)
{
    string data_string="";

    if (!luaL_dofile(L,filename.c_str())) //execute config file
    {
        lua_getglobal(L,var_name.c_str());
        if (!lua_isstring(L, -1))
        {
            new message_log(MESSAGE_WARNING,filename+": `"+var_name+"` should be a string");
        }
        else
            data_string=lua_tolstring(L, -1,NULL);
    }
    else
    {
        std::string errormessage=lua_tostring(L,-1);
        new message_log(MESSAGE_WARNING,"cannot execute `"+filename+"`\n\t"+errormessage);
    }

    return data_string;
}

config_file::~config_file()
{
    //dtor
}
