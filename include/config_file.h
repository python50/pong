#ifndef CONFIG_FILE_H
#define CONFIG_FILE_H

/**
 * @file
 * @author  Jason White <jason@jswhite.net> <whitewaterssoftwareinfo@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 * PONG - The open source pong clone Copyright (C) 2012 Jason White, White Waters Software
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see http://www.gnu.org/licenses/.
 *
 * @section DESCRIPTION
 *
 *
 */

// C library includes

// library includes

// project includes

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
