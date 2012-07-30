/**
 * @file
 * @author  Jason White <jason@jswhite.net> <whitewaterssoftwareinfo@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 * PONG - The open source pong clone Copyright (C) 2012 Jason White
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

#include <map>

#include "game_engine.h"
#include "message_log.h"
#include "map_parser.h"
#include "lua_object.h"
#include "tile.h"
#include "ship.h"
#include "astroid.h"
#include "misc.h"
#include "text.h"
#include "text_menu.h"
#include "main_menu_ui.h"
#include "startup_ui.h"

map_parser::map_parser(game_engine * gm_engine_, std::string filename_)
{
    gm_engine=gm_engine_;
    std::string map_table="map";
    filename=filename_;

    L = lua_open();
    luaL_openlibs(L);

    new message_log(MESSAGE_DEBUG5,"Loading Map `"+filename+"`");

    if (!luaL_dofile(L,filename.c_str())) //execute config file
    {
        /*
        if (!lua_istable(L, -1))
        {
        new message_log(WARNING,filename+": `map` should be a table");
        return ;
        }*/

        gm_engine->clear_objects();

        map_information new_map;

        new_map.scale=gm_engine->game_get_scale();


        int twidth=0;
        int theight=0;

        lua_getglobal(L,"map");
        lua_pushstring(L,"tilewidth");
        lua_gettable(L,-2);
        twidth=lua_tonumber(L,-1);
        lua_pop(L,1);

        lua_getglobal(L,"map");
        lua_pushstring(L,"tileheight");
        lua_gettable(L,-2);
        theight=lua_tonumber(L,-1);
        lua_pop(L,1);

        lua_getglobal(L,"map");
        lua_pushstring(L,"width");
        lua_gettable(L,-2);
        new_map.abs_width=lua_tonumber(L,-1)*twidth;
        lua_pop(L,1);

        lua_pushstring(L,"height");
        lua_gettable(L,-2);
        new_map.abs_height=lua_tonumber(L,-1)*theight;
        lua_pop(L,1);

        new_map.scale_width=new_map.abs_width*new_map.scale;
        new_map.scale_height=new_map.abs_height*new_map.scale;
        gm_engine->game_set_map_information(&new_map);

        int index=1;
        while (1)
        {
            lua_getglobal(L,"map");
            lua_pushstring(L,"layers");
            lua_gettable(L,-2);

            lua_pushnumber(L,index);
            lua_gettable(L,-2);

            if (!lua_istable(L,-1))
                break;

            parse_layer(index);
            index++;
        }
    }
    else
    {
        new message_log(MESSAGE_WARNING,"cannot execute "+filename);
    }

}

void map_parser::parse_layer(int layer_number)
{
    std::string layername;

    lua_pushstring(L,"type");
    lua_gettable(L,-2);
    layername=lua_tostring(L,-1);
    lua_pop(L,1); //pop 1 elements from the stack

    int index_objects=1;
    if (layername=="objectgroup")
    {
        while (1)
        {
            float layer_z=-1;

            if (lua_istable(L, -1) )
            {

                lua_pushstring(L,"properties");
                lua_gettable(L,-2); //+1

                if (lua_istable(L,-1))
                {
                    lua_pushstring(L,"z");
                    lua_gettable(L,-2); //+1

                    if ( lua_isnumber(L,-1) )
                        layer_z=lua_tonumber(L,-1);

                    lua_pop(L,1);
                }

                lua_pop(L,1);

                lua_pushstring(L,"objects");
                lua_gettable(L,-2);

                if (lua_istable(L, -1))
                {
                    lua_pushnumber(L,index_objects);
                    lua_gettable(L,-2);

                    if (lua_istable(L, -1))
                    {




                        if (!lua_istable(L,-1))
                            break;

                        parse_object(layer_number,index_objects,layer_z);

                        lua_pop(L,2);
                    }
                    else
                    {
                        lua_pop(L,3);
                        //new message_log(WARNING,"Map Parser: 'map.layers.[\""+ convert_int_string(layer_number) +"\"].objects.[\""+convert_int_string(index_objects)+"\"]' is not a table");
                        break;
                    }
                }
                else
                {
                    lua_pop(L,2);
                    new message_log(MESSAGE_WARNING,"Map Parser: 'map.layers.[\""+ convert_int_string(layer_number) +"\"].objects' is not a table");
                    break;
                }
            }
            else
            {
                lua_pop(L,1);
                new message_log(MESSAGE_WARNING,"Map Parser: 'map.layers.[\""+ convert_int_string(layer_number) +"\"]' is not a table");
                break;
            }


            index_objects++;
        }
    }
    else
        std::cout << "Bad layer" << "\n";
}

void map_parser::parse_object(int layer_number,int index,float layer_z)
{
    //in map.layers[A].objects[B]

    lua_pushstring(L,"type");
    lua_gettable(L,-2);

    std::string object_type;
    if (lua_isstring(L,-1))
        object_type=lua_tostring(L,-1);

    lua_pop(L,1);

    lua_pushstring(L,"name");
    lua_gettable(L,-2);

    std::string object_name;
    if (lua_isstring(L,-1))
        object_name=lua_tostring(L,-1);

    lua_pop(L,1);

    float x,y,w,h;
    x=0;
    y=0;
    w=0;
    h=0;

    lua_pushstring(L,"x");
    lua_gettable(L,-2);
    if (lua_isnumber(L,-1))
        x=lua_tonumber(L,-1)*gm_engine->game_get_scale();
    else
    {
        new message_log(MESSAGE_WARNING,"Map Parser: 'map.layers.[\""+ convert_int_string(layer_number) +"\"].objects.[\""+ convert_int_string(index) +"\"].x' is not a number");
    }
    lua_pop(L,1);

    lua_pushstring(L,"y");
    lua_gettable(L,-2);
    if (lua_isnumber(L,-1))
        y=lua_tonumber(L,-1)*gm_engine->game_get_scale();
    else
    {
        new message_log(MESSAGE_WARNING,"Map Parser: 'map.layers.[\""+ convert_int_string(layer_number) +"\"].objects.[\""+ convert_int_string(index) +"\"].x' is not a number");
    }
    lua_pop(L,1);

    lua_pushstring(L,"width");
    lua_gettable(L,-2);
    if (lua_isnumber(L,-1))
        w=lua_tonumber(L,-1)*gm_engine->game_get_scale();
    else
    {
        new message_log(MESSAGE_WARNING,"Map Parser: 'map.layers.[\""+ convert_int_string(layer_number) +"\"].objects.[\""+ convert_int_string(index) +"\"].height' is not a number");
    }
    lua_pop(L,1);


    lua_pushstring(L,"height");
    lua_gettable(L,-2);
    if (lua_isnumber(L,-1))
        h=lua_tonumber(L,-1)*gm_engine->game_get_scale();
    else
    {
        new message_log(MESSAGE_WARNING,"Map Parser: 'map.layers.[\""+ convert_int_string(layer_number) +"\"].objects.[\""+ convert_int_string(index) +"\"].width' is not a number");
    }
    lua_pop(L,1);

    //std::cout << "New Object: " <<  object_type << " " << x << " " << y << " " << w << " " << h <<"\n";


    if (object_type=="lua_object")
    {
        std::string script_name;
        lua_pushstring(L,"properties");
        lua_gettable(L,-2);

        lua_pushstring(L,"script");
        lua_gettable(L,-2);

        if (lua_isstring(L,-1))
        {
            script_name=lua_tostring(L,-1);
        }

        gm_engine->add_object(new lua_object(gm_engine,script_name, x*1, y*1));

        lua_pop(L,2);
    }

    if (object_type=="tile")
    {
        float z;

        z=-1;

        std::string image_name;
        lua_pushstring(L,"properties");
        lua_gettable(L,-2);

        lua_pushstring(L,"image");
        lua_gettable(L,-2);

        if (lua_isstring(L,-1))
        {
            image_name=lua_tostring(L,-1);
        }

        lua_pop(L,1);

        //in map.layers[A].objects[B].properties

        lua_pushstring(L,"z");
        lua_gettable(L,-2);


        if (lua_isnumber(L,-1))
            z=lua_tonumber(L,-1);
        else
            z=layer_z;

        lua_pop(L,2);

        //back to map.layers[A].objects[B]

        gm_engine->add_object(new tile(gm_engine, x*1, y*1, z, image_name));

    }

    if (object_type=="astroid")
    {
        controller * ast=new astroid(gm_engine, x*1, y*1);
        gm_engine->add_object(ast);

        lua_pushstring(L,"properties");
        lua_gettable(L,-2);
        //
        float number;
        lua_pushstring(L,"speed");
        lua_gettable(L,-2);

        if (lua_isnumber(L,-1))
        {
            ast->set("speed",number=lua_tonumber(L,-1));
        }

        lua_pop(L,1);
        //
        lua_pushstring(L,"angle");
        lua_gettable(L,-2);

        if (lua_isnumber(L,-1))
        {
            ast->set("angle",number=lua_tonumber(L,-1));
        }

        lua_pop(L,1);
        //
        lua_pushstring(L,"mass");
        lua_gettable(L,-2);

        if (lua_isnumber(L,-1))
        {
            ast->set("mass",number=lua_tonumber(L,-1));
        }

        lua_pop(L,1);
        //
        lua_pop(L,1);
    }

    if (object_type=="text")
    {
        std::string name="";
        std::string strtext="";
        std::string font="";
        text_justify justify_horizontal=TEXT_JUSTIFY_LEFT;
        text_justify justify_vertical=TEXT_JUSTIFY_TOP;

        lua_pushstring(L,"name");
        lua_gettable(L,-2);

        if (lua_isstring(L,-1))
        {
            name=lua_tostring(L,-1);
        }

        lua_pop(L,1);

        lua_pushstring(L,"properties");
        lua_gettable(L,-2);

        lua_pushstring(L,"text");
        lua_gettable(L,-2);

        if (lua_isstring(L,-1))
        {
            strtext=lua_tostring(L,-1);
        }

        lua_pop(L,1);

        lua_pushstring(L,"font");
        lua_gettable(L,-2);

        if (lua_isstring(L,-1))
        {
            font=lua_tostring(L,-1);
        }

        lua_pop(L,1);

        lua_pushstring(L,"justify_horizontal");
        lua_gettable(L,-2);

        if (lua_isstring(L,-1))
        {
            if (strcmp(lua_tostring(L,-1),"left")==0)
                justify_horizontal= TEXT_JUSTIFY_LEFT;
            if (strcmp(lua_tostring(L,-1),"right")==0)
                justify_horizontal= TEXT_JUSTIFY_RIGHT;
            if (strcmp(lua_tostring(L,-1),"center")==0)
                justify_horizontal= TEXT_JUSTIFY_CENTER;
        }


        lua_pop(L,1);

        lua_pushstring(L,"justify_vertical");
        lua_gettable(L,-2);

        if (lua_isstring(L,-1))
        {
            if (strcmp(lua_tostring(L,-1),"top")==0)
                justify_vertical= TEXT_JUSTIFY_TOP;
            if (strcmp(lua_tostring(L,-1),"bottom")==0)
                justify_vertical= TEXT_JUSTIFY_BOTTOM;
            if (strcmp(lua_tostring(L,-1),"middle")==0)
                justify_vertical= TEXT_JUSTIFY_MIDDLE;
        }

        lua_pop(L,1);

        controller * textobj=new text(gm_engine, name ,x, y, font, strtext);

        int justify_h=(int) justify_horizontal;
        int justify_v=(int) justify_vertical;

        textobj->set((std::string)"justify_horizontal", justify_h);
        textobj->set((std::string)"justify_vertical", justify_v);
        gm_engine->add_object(textobj);

        lua_pop(L,1);
    }

    if (object_type=="main_menu_ui")
    {
        gm_engine->add_object(new main_menu_ui(gm_engine));
    }

    if (object_type=="startup_ui")
    {
        gm_engine->add_object(new startup_ui(gm_engine));
    }
}

/**  test_lua_filename(lua_State L, int index)
    tests to see if the entry at index in lua_State L is a suitable filename
    Returns:
        1|True : Good filename
        0|False: Bad filename
**/
bool map_parser::test_lua_filename(lua_State * L, int index)
{
    if (lua_isstring(L,index)) // is it a string ?
    {
        if (strcmp(lua_tostring(L,-index),"")==0) // is it not empty ?
            return true; // Yes it Not empty, Good
        else
            return false; // No it is empty, Bad
    }
    else
        return false; // Not a string, Bad
}

map_parser::~map_parser()
{
    //dtor
}
