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
#include "game_engine.h"
#include "message_log.h"
#include "math.h"

SDL_Rect game_engine::view_get()
{
    SDL_Rect view;
    view.x=video.view_x;
    view.y=video.view_y;
    view.w=video.width;
    view.h=video.height;
    return view;
}

void game_engine::view_set(SDL_Rect view)
{
    video.view_x=view.x;
    video.view_y=view.y;
}

void game_engine::view_reset()
{
    video.view_x=0;
    video.view_y=0;
}

void game_engine::view_translate(float x, float y)
{
    video.view_x+=x;
    video.view_y+=y;
}
