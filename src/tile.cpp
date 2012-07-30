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
#include "tile.h"
#include "message_log.h"
#include "misc.h"

tile::tile(game_engine *g_engine,float xx, float yy, float zz, std::string image, std::string id)
{
    if (id=="")
        id_type="tile";

    new message_log(MESSAGE_DEBUG3, "tile object created, id:`"+id_type+
                    " image:`"+image+
                    "`");
    gm_engine=g_engine;
    x=xx;
    y=yy;
    if (zz==-1)
    {
        z=10;
    }
    else
    {
        z=zz;
    }

    sprite=gm_engine->get_surface(image);
    rect.x=x;
    rect.y=y;
    rect.w=sprite->data->w;
    rect.h=sprite->data->h;

    delete_this=0;
    no_collide=1;
}

void tile::update()
{
    gm_engine->blit(x,y,sprite);
}


void tile::call(std::string item, bool &value)
{

}

void tile::call(std::string item, int &value)
{

}

void tile::call(std::string item, float &value)
{

}

void tile::call(std::string item, std::string &value)
{

}


void tile::get(std::string item, std::string &val)
{
    if (item=="id_type")
        val=id_type;
}

void tile::get(std::string item, bool &val)
{
    if (item=="delete_this")
        val=delete_this;

    if (item=="persistant")
        val=persistant;

    if (item=="no_collide")
        val=no_collide;
}

void tile::get(std::string item, int &val)
{
    return;
}

void tile::get(std:: string item, float &val)
{
    if (item=="z")
        val=z;

    if (item=="x")
        val=x;
    if (item=="y")
        val=y;
}


void tile::set(std::string item, std::string &value)
{
    if (item=="id_type")
        id_type=value;
}

void tile::set(std::string item, bool &value)
{
    if (item=="delete_this")
        delete_this=value;

    if (item=="persistant")
        persistant=value;

    if (item=="no_collide")
        no_collide=value;
}

void tile::set(std::string item, int &value)
{

}

void tile::set(std::string item, float &value)
{
    if (item=="z")
        z=value;
    if (item=="x")
        x=value;
    if (item=="y")
        y=value;
}

tile::~tile()
{
    new message_log(MESSAGE_DEBUG3,"tile object destroyed, id:`"+id_type+"`");
}
