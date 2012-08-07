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
#include "controller.h"

controller::controller()
{
    //ctor
}

void controller::init()
{

}

void controller::reset()
{

}

void controller::pause()
{

}

void controller::unpause()
{

}

void controller::update()
{

}

void controller::draw()
{

}

void controller::call(std::string item, bool &value)
{

}

void controller::call(std::string item, int &value)
{

}

void controller::call(std::string item, float &value)
{

}

void controller::call(std::string item, std::string &value)
{

}


void controller::get(std::string item, std::string &val)
{
    if (item=="id_type")
        val=id_type;
}

void controller::get(std::string item, bool &val)
{
    if (item=="delete_this")
        val=delete_this;

    if (item=="persistant")
        val=persistant;

    if (item=="no_collide")
        val=no_collide;
}

void controller::get(std::string item, int &val)
{
    return;
}

void controller::get(std:: string item, float &val)
{
    if (item=="z")
        val=z;
}


void controller::set(std::string item, std::string &value)
{
    if (item=="id_type")
        id_type=value;
}

void controller::set(std::string item, bool &value)
{
    if (item=="delete_this")
        delete_this=value;

    if (item=="persistant")
        persistant=value;

    if (item=="no_collide")
        no_collide=value;
}

void controller::set(std::string item, int &value)
{

}

void controller::set(std::string item, float &value)
{
    if (item=="z")
        z=value;
}

controller::~controller()
{
    //dtor
}
