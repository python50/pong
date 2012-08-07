#ifndef MAP_PARSER_H
#define MAP_PARSER_H


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
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include <iostream>
#include "game_engine.h"


class map_parser
{
    public:
        map_parser(game_engine * gm_engine, std::string filename);
        virtual ~map_parser();
    protected:
    private:
        bool test_lua_filename(lua_State * L, int index);
        void parse_layer(int layer_number);
        void parse_object(int layer_number,int index, float z);

        lua_State *L;
        game_engine * gm_engine;
        std::string filename;
};

#endif // MAP_PARSER_H
