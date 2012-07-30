/**
 ** Code Copyright (C) 2011 Jason White <whitewaterssoftwareinfo@gmail.com>
 **                         White Waters Software - wwsoft.co.cc
 **
 ** Copying and distributing this source is prohibited without
 ** explicit authorization by the copyright holder: Jason White
 **/

#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H


extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}


#include <iostream>
#include "game_engine.h"
using namespace std;

class config_file
{
    public:
        config_file(game_engine * gm_engine, string name);
        void run();
        int get_int(string var_name);
        float get_float(string var_name);
        string get_string(string var_name);
        virtual ~config_file();
    protected:
    private:
        game_engine * gm_engine;
        string filename;
        lua_State * L;
};

#endif // CONFIG_FILE_H
