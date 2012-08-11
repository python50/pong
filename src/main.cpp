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
 * This file contains the main loop for this project
 */



extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

/*
Include Template

// C library includes

// library includes

// project includes

*/

// C library includes
#include <stdlib.h>

// library includes
#include "SDL_framerate.h"

// project includes
#include "config_file.h"
#include "message_log.h"
#include "misc.h"
#include "game_engine.h"
#include "text.h"

#include "config_manager.h"

int main(){
    //config_manager config("data/settings.sqlite");
	//config.set_setting_int("int", "Settings",100);
    //cout << config.get_setting_int("int", "Settings") << "\n";

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
			new message_log("FPS" ,"%f (%f)", fps_average, fps);
        }

        controller * fps_text = engine->get_object("fps-text");
        if (fps_text==NULL)
        {
            fps_text=new text(engine,"fps-text",625,0,"jura_medium-12","",BLIT_ABSOLUTE);
            engine->add_object(fps_text);
            int value=0xFF;
            engine->get_object("fps-text")->set("font_green",value);
        }

        string text=convert_int_string(fps_average);
        fps_text->set("text",text);

    }

    new message_log(MESSAGE_EVENT,"WWSiGE Closed");

    return 0;
}
