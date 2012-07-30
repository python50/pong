#ifndef MAP_PARSER_H
#define MAP_PARSER_H

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
