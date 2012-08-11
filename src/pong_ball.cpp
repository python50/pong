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
#include "pong_ball.h"
#include "math.h"
pong_ball::pong_ball(game_engine * gm_engine_, float x_, float y_,float speed_)
{
    gm_engine=gm_engine_;
    x=x_;
    y=y_;
    z=10;
    speed=speed_;

    id_type="ball";
    delete_this=0;
    persistant=0;
    no_collide=0;

    if (gmath_random(-100,100) > 0)
        vector.angle=gmath_random(-25,25);
    else
        vector.angle=180+gmath_random(-25,25);

    vector.mass=1;
    vector.speed=speed;

    sprite=gm_engine->get_surface("ball");
    rect.w=sprite->data->w;
    rect.h=sprite->data->h;
    rect.x=x-rect.w/2;
    rect.y=y-rect.h/2;
    start_x=x;
    start_y=y;

    counter=0;
}

void pong_ball::call(std::string item, bool &value)
{
    if (item=="reset")
    {
        counter=0;
        x=start_x;
        y=start_y;
        vector.angle=gmath_direction(0,0,-vector.x,-vector.y)/M_PI*180;
    }
}

void pong_ball::get(std::string item, float &return_value)
{
    if (item=="x")
        return_value=x;
    if (item=="y")
        return_value=y;
    if (item=="z")
        return_value=z;
}

bool pong_ball::update()
{
    gm_engine->game_logic();

    if (gm_engine->game_get_state()==GAME_PLAYING)
        x;
    else
        return delete_this;

    collision();

    gmath_compute_vector(vector);

    x+=vector.x;
    y+=vector.y;

    rect.x=x-rect.w/2;
    rect.y=y-rect.h/2;

    gm_engine->blit(rect.x,rect.y,sprite, BLIT_ABSOLUTE);
	
	return delete_this;
}

void pong_ball::collision()
{
    counter++;
    bool nothing;
    if (counter > 300)
    {
        call("reset", nothing);
        vector.angle=gmath_random(-45,45);
    }

    if (y-rect.h/2 <= 0)
    {
        gm_engine->sound_play("beep0");
        vector.angle=gmath_direction(0,0,vector.x,vector.y)/M_PI*180;
        y=rect.h/2+1;
    }

    if (y+rect.h/2 >= gm_engine->view_get().h)
    {
        gm_engine->sound_play("beep0");
        vector.angle=gmath_direction(0,0,vector.x,vector.y)/M_PI*180;
        y=gm_engine->view_get().h-rect.h/2-1;
    }

    controller * paddle0=gm_engine->get_object("paddle0");
    SDL_Rect paddle0_rect=paddle0->rect;

    controller * paddle1=gm_engine->get_object("paddle1");
    SDL_Rect paddle1_rect=paddle1->rect;

    if (vector.angle > 360)
        vector.angle=vector.angle-360;
    if (vector.angle < 0)
        vector.angle=vector.angle+360;

    float paddle_y=0;


    if (gm_engine->rect_collide(rect,paddle0_rect) and counter > 15)
    {
        paddle0->get("y",paddle_y);
        counter=0;
        gm_engine->sound_play("beep1");

        float difference=((paddle_y)-(y)); //Need resolution scalling

        vector.angle=gmath_direction(0,0,-vector.x,-vector.y)/M_PI*180+difference;
    }

    if (gm_engine->rect_collide(rect,paddle1_rect) and counter > 15)
    {
        paddle1->get("y",paddle_y);
        counter=0;
        gm_engine->sound_play("beep1");

        float difference=((y)-(paddle_y))*1.25; //Need resolution scalling

        vector.angle=gmath_direction(vector.x,vector.y,0,0)/M_PI*180+difference;
    }

    if (rect.x-rect.w/2 > gm_engine->view_get().w)
    {
        call("reset",nothing);
        gm_engine->sound_play("beep0");
        gm_engine->game_score(0,1);
    }
    if (rect.x+rect.w/2 < 0)
    {
        call("reset",nothing);
        gm_engine->sound_play("beep0");
        gm_engine->game_score(1,1);
    }
}

pong_ball::~pong_ball()
{
    //dtor
}
