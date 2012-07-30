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
#include "startup_ui.h"
#include "startup_splash_ui.h"

startup_ui::startup_ui(game_engine * gm_engine_)
{
    gm_engine=gm_engine_;
    counter=0;
    background=gm_engine->get_surface("background-startup");

    delete_this=0;
    persistant=0;
    no_collide=0;

    z=10;

    gm_engine->music_play("startup",-1);
}

void startup_ui::update()
{
    counter++;
    if (counter > 6)
    {
        load_next();
        return ;
    }
    /*Uint8 *keystate = SDL_GetKeyState(NULL);
    if (keystate[SDLK_SPACE] || keystate[SDLK_RETURN] )
    {
        load_next();
        return ;
    }*/
    gm_engine->blit(0,0,background, BLIT_ABSOLUTE);
}

void startup_ui::load_next()
{
    gm_engine->clear_objects();
    gm_engine->add_object(new startup_splash_ui(gm_engine));
}

startup_ui::~startup_ui()
{
    //dtor
}
