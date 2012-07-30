/**
 ** Code Copyright (C) 2011 Jason White <whitewaterssoftwareinfo@gmail.com>
 **                         White Waters Software - http://wwsoft.co.cc
 **
 ** modifying, copying and distribution of this source is prohibited without
 ** explicit authorization by the copyright holder: Jason White
 **/

#include "shot.h"
#include "math.h"
#include "SDL_rotozoom.h"
#include <iostream>

shot::shot(game_engine * g_engine,float xx,float yy,gmath_vector &vector_)
{
    id_type="shot";

    gm_engine=g_engine;
    new message_log(MESSAGE_DEBUG3,"Shot Created");

    vector=vector_;

    vector.mass=1;
    vector.speed+=1;

    x=xx;
    y=yy;
    z=10;

    life_counter=0;

    delete_this=0;
    persistant=0;
    no_collide=0;

    sprite=gm_engine->get_surface("shot0.png");

    rect.w=round(sprite->data->w * gm_engine->game_get_scale());
    rect.h=round(sprite->data->h * gm_engine->game_get_scale());
}

void shot::init()
{

}

void shot::reset()
{
    delete_this=1;
}

void shot::pause()
{

}

void shot::unpause()
{

}

void shot::call(std::string item, void * value_1, void * value_2)
{

}

void shot::get(std::string item, void * return_value)
{

}

void shot::set(std::string item, void * value)
{

}

void shot::update()
{
    life_counter++;

    rect.x=x-(rect.w/2);
    rect.y=y-(rect.h/2);

    controller * ctrl = gm_engine->rect_collide_all(rect,this, "astroid");
    if (ctrl!=0)
    {
        gm_engine->sound_play("thud_0");
        ctrl->delete_this=true;
        delete_this=true;
    }

    physics();
    draw();

    if (life_counter > 60)
        delete_this=true;
}

void shot::physics()
{

    if (x > gm_engine->game_get_width())
       x=0;
    if (y > gm_engine->game_get_height())
       y=0;

    if (x < 0)
        x=gm_engine->game_get_width();
    if (y < 0)
        y=gm_engine->game_get_height();

    gmath_compute_vector(vector);
    x+=vector.x;
    y+=vector.y;
}

void shot::draw()
{
    gm_engine->blit(x,y,sprite,BLIT_DYNAMIC);
}

shot::~shot()
{

}
