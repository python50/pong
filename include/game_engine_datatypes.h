#ifndef GAME_ENGINE_DATATYPES_H_INCLUDED
#define GAME_ENGINE_DATATYPES_H_INCLUDED

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

#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "vector"

struct wwsige_color
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
};

struct wwsige_surface
{
    const char * id;
    SDL_Surface * data;
};

struct wwsige_font
{
    const char * id;
    TTF_Font * data;
    int ptsize;
    //int width; Does this have future use ?
};

struct wwsige_sound
{
    const char * id;
    Mix_Chunk * data;
};

struct wwsige_music
{
    const char * id;
    Mix_Music * data;
};

#endif // GAME_ENGINE_DATATYPES_H_INCLUDED
