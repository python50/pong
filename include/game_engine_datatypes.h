#ifndef GAME_ENGINE_DATATYPES_H_INCLUDED
#define GAME_ENGINE_DATATYPES_H_INCLUDED

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
