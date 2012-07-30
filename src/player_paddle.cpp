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
#include "player_paddle.h"
#include "math.h"
player_paddle::player_paddle(game_engine * gm_engine_, float x_, float y_, int player_number_)
{
    player_paddle::id_type="";
    if (player_number_==0)
        player_paddle::id_type="paddle0";
    if (player_number_==1)
        player_paddle::id_type="paddle1";

    gm_engine=gm_engine_;
    x=x_;
    y=y_;
    z=10;
    speed_mod=0;
    speed=5;
    player_number=player_number_;


    delete_this=0;
    persistant=0;
    no_collide=0;

    sprite=gm_engine->get_surface("paddle");

    rect.w=sprite->data->w;
    rect.h=sprite->data->h;
    rect.x=x-rect.w/2;
    rect.y=y-rect.h/2;

    x=x+rect.w/2;
    y=y+rect.h/2;
    start_x=x;
    start_y=y;

}

void player_paddle::call(std::string item, bool &value)
{
    if (item=="reset")
    {
        x=start_x;
        y=start_y;
    }
}

void player_paddle::get(std::string item, float &return_value)
{
    if (item=="x")
        return_value=x;
    if (item=="y")
        return_value=y;
    if (item=="z")
        return_value=z;
}

void player_paddle::event()
{
    Uint8 *keystate = SDL_GetKeyState(NULL);

    if (player_number==0)
    {
        if (keystate[SDLK_UP] )
        {
            y-=speed+speed_mod;
        }

        if (keystate[SDLK_DOWN] )
        {
            y+=speed+speed_mod;
        }
    }

    if (player_number==1)
    {
        if (keystate[SDLK_w] )
        {
            y-=speed+speed_mod;
        }

        if (keystate[SDLK_s] )
        {
            y+=speed+speed_mod;
        }
    }
}

void player_paddle::collision()
{
    rect.x=x-rect.w/2;
    rect.y=y-rect.h/2;

    if (y <= rect.h/2)
        y=rect.h/2;

    if (y >= gm_engine->view_get().h-rect.h/2)
        y=gm_engine->view_get().h-rect.h/2;
}

void player_paddle::update()
{
    if (gm_engine->game_get_state()==GAME_PLAYING)
        x;
    else
        return;

    event();
    collision();

    gm_engine->blit(rect.x,rect.y,sprite,BLIT_ABSOLUTE);
}

player_paddle::~player_paddle()
{
    //dtor
}
