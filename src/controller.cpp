/**
 ** Code Copyright (C) 2011 Jason White <whitewaterssoftwareinfo@gmail.com>
 **                         White Waters Software - http://wwsoft.co.cc
 **
 ** modifying, copying and distribution of this source is prohibited without
 ** explicit authorization by the copyright holder: Jason White
 **/

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
