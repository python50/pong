/**
 * @file
 * @author  Jason White <whitewaterssoftwareinfo@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 *
 * @section DESCRIPTION
 *
 * This file contains all game_engine functions related to views
 */

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
