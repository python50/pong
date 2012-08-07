#ifndef LUA_OBJECT_H
#define LUA_OBJECT_H

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

#include "game_engine.h"
#include "game_object.h"
#include "message_log.h"
#include "iostream"

class lua_object : public controller
{
    public:
        lua_object(game_engine * gm_engine, std::string filename, float x, float y, float z=0);
        void update();
        virtual ~lua_object();
    protected:
    private:
        game_engine * gm_engine;
        wwsige_surface * sprite;
        lua_State *L;
        float x,y,z;
        bool script_error;
        std::string scriptname;
};

#endif // LUA_OBJECT_H
