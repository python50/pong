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
 * This file contains the main loop for this project
 */



extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#include "config_file.h"
#include "message_log.h"
#include "misc.h"
#include "game_engine.h"
#include <stdlib.h>
#include <SDL_framerate.h>
//#include "main.h"

int main()
{
    new message_log(MESSAGE_EVENT,"WWSiGE Loading");

    game_engine * engine=new game_engine();

    if (! engine->load(640,480,0))
    {
        new message_log(MESSAGE_FATAL_ERROR,"WWSiGE Failed To Load Necessary Resources, Quitting ...");
        return 100;
    }

    new message_log(MESSAGE_EVENT,"WWSiGE Started");

    FPSmanager manager;
    SDL_initFramerate(&manager);
    SDL_setFramerate(&manager, 30);

    uint32_t last_tick=0;
    char counter=0;
    float fps=0;
    float fps_average=0;
    bool run=1;

    while (run)
    {
        last_tick=SDL_GetTicks();
        run=engine->update();
        SDL_framerateDelay(&manager);

        fps=SDL_GetTicks()-last_tick;
        fps/=1000;
        fps=1/fps;

        fps_average=(fps_average+fps)/2;

        counter++;

        if (counter > 59)
        {
            counter=0;
            printf("fps: %f (%f)\n", fps_average, fps);
        }
    }

    new message_log(MESSAGE_EVENT,"WWSiGE Closed");

    return 0;
}
