/**
 ** Code Copyright (C) 2011 Jason White <whitewaterssoftwareinfo@gmail.com>
 **                         White Waters Software - http://wwsoft.co.cc
 **
 ** modifying, copying and distribution of this source is prohibited without
 ** explicit authorization by the copyright holder: Jason White
 **/

#include "astroid.h"
#include "message_log.h"
#include "SDL_rotozoom.h"
#include "game_math.h"
#include "misc.h"


astroid::astroid(game_engine * engine, float xx, float yy)
{
    gm_engine=engine;
    new message_log(MESSAGE_DEBUG3,"Astroid Created");

    id_type="astroid";

    if (xx==-1 && yy==-1)
    {
        x=gmath_random(0,gm_engine->game_get_width()*10)/10;
        y=gmath_random(0,gm_engine->game_get_height()*10)/10;
    }
    else
    {
        x=xx;
        y=yy;
    }

    vector.angle=gmath_random(0,3600)/10;
    image_angle=0;
    vector.magnitude=0;
    vector.speed=(float)gmath_random(500,4000)/1000;
    vector.mass=100;

    delete_this=0;
    persistant=0;
    no_collide=0;

    sprite=gm_engine->get_surface("astroid0");

    rect.w=sprite->data->w;
    rect.h=sprite->data->h;

    z=10;

    counter=0;
}

void astroid::init()
{

}

void astroid::reset() //simply delete at reset
{
    delete_this=1;
}

void astroid::call(std::string item, bool &value)
{

}

void astroid::call(std::string item, int &value)
{

}

void astroid::call(std::string item, float &value)
{

}

void astroid::call(std::string item, std::string &value)
{

}


void astroid::get(std::string item, std::string &val)
{
    if (item=="id_type")
        val=id_type;
}

void astroid::get(std::string item, bool &val)
{
    if (item=="delete_this")
        val=delete_this;

    if (item=="persistant")
        val=persistant;

    if (item=="no_collide")
        val=no_collide;
}

void astroid::get(std::string item, int &val)
{
    return;
}

void astroid::get(std::string item, float  &return_value)
{
    if (item=="z")
    {
        return_value=z;
        return;
    }

    if (item=="x")
    {
        return_value=x;
        return;
    }

    if (item=="y")
    {
        return_value=y;
        return;
    }

    if (item=="angle")
    {
        return_value=vector.angle;
        return;
    }

    if (item=="mass")
    {
        return_value=vector.mass;
        return;
    }

    if (item=="speed")
    {
        return_value=vector.speed;
        return;
    }
}


void astroid::set(std::string item, std::string &value)
{
    if (item=="id_type")
        id_type=value;
}

void astroid::set(std::string item, bool &value)
{
    if (item=="delete_this")
        delete_this=value;

    if (item=="persistant")
        persistant=value;

    if (item=="no_collide")
        no_collide=value;
}

void astroid::set(std::string item, int &value)
{

}

void astroid::set(std::string item, float &value)
{
    if (item=="z")
    {
        z=value;
        return;
    }

    if (item=="x")
    {
        x=value;
        return;
    }

    if (item=="y")
    {
        y=value;
        return;
    }

    if (item=="angle")
    {
        vector.angle=value;
        return;
    }

    if (item=="mass")
    {
        vector.mass=value;
        return;
    }

    if (item=="speed")
    {
        vector.speed=value;
        return;
    }
}

void astroid::update()
{
    rect.x=x-(rect.w/2);
    rect.y=y-(rect.h/2);

    /*void * self=this;
    controller * ctrl = rect_collide_all(rect,this,0);
    if (!ctrl==NULL)
    {
        if (ctrl->id_type=="astroid")
        {
            gmath_vector collision;
            float xx,yy;
            ctrl->get("angle",collision.angle);
            ctrl->get("magnitude",collision.magnitude);
            ctrl->get("x",xx);
            ctrl->get("y",yy);

            float xxx,yyy;
            xxx=x-(xx);
            yyy=y-(yy);
            collision.angle=(atan2(yyy,xxx)/M_PI*180)*-1;

            gmath_add_vector(vector,collision);

            if (vector.magnitude > 8)
                vector.magnitude=8;
        }
    }*/

    physics();
    draw();
}

void astroid::physics()
{
    if (x > gm_engine->game_get_width())
        x=0;
    if (y > gm_engine->game_get_height())
        y=0;

    if (x < 0)
        x=gm_engine->game_get_width();
    if (y < 0)
        y=gm_engine->game_get_height();

    gmath_vector gravity;
    //controller * player=gm_engine->get_object("player");
/*
    float xx, yy;
    xx=1648+320;
    yy=1008+320;
    //player->get("x", xx);
    //player->get("y", yy);

    gravity.angle=gmath_direction(x,y,xx,yy)/M_PI*180*-1;//(atan2(yy,xx)/M_PI*180);//*-1;
    gravity.speed=9.8/pow(gmath_distance(x,y,xx,yy),2);
    gravity.mass=1000*vector.mass;


    gmath_add_vector(vector,gravity);
*/
    gmath_compute_vector(vector);

    x+=vector.x;
    y+=vector.y;
}

void astroid::draw()
{
    gm_engine->blit(x-sprite->data->w/2,y-sprite->data->h/2,sprite);
}

astroid::~astroid()
{
    new message_log(MESSAGE_DEBUG3,"Astroid Destoryed");//gm_engine->play_sound("thud_0",0);
}
