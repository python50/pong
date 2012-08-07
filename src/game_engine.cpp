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
extern "C"
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#include "algorithm"


#include "game_engine.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_rotozoom.h"

#include <stdlib.h>
#include "math.h"
#include "misc.h"

#include "message_log.h"
#include "game_math.h"
#include "misc.h"
#include "tile.h"
#include "lua_object.h"
#include "map_parser.h"
#include "config_file.h"

#include "text.h"
#include "text_menu.h"
#include "startup_ui.h"

namespace view
{
    int x=0;
    int y=0;
    int scale_width=0;
    int scale_height=0;
    int width=0;
    int height=0;
    int target_width=0;
    int target_height=0;
}

namespace play_area
{
    double scale=0;
    int scale_width=0;
    int scale_height=0;
    int width=0;
    int height=0;
}

namespace game
{
    int lives=0;
    bool pause=0;
    bool reset=0;
    bool over=0;
}

game_engine::game_engine()
{
    state=UNINITED;
    quit_=0;
}

bool game_engine::load(int width,int height, bool cursor)
{
    atexit(SDL_Quit);

    video.target_width=width;
    video.target_height=height;

    load__initalize();

    sound_set_volume(sound.sample_volume);
    music_set_volume(sound.stream_volume);


    engine_event = new SDL_Event();


    // --- now initialized ---

    config_file startup(this, "data/startup.lua"); //startup is only run after we have a window
    startup.run(); //run startup script

    gmath_randomize();
    joystick_init();

    SDL_ShowCursor(cursor);

    load_surface("data/image/background/startup.png","background-startup");
    load_surface("data/image/background/splash.png","background-splash");

    const bool mode=0;
    if (mode==0)
    {
        control_data.push_back(new startup_ui(this));
    }
    else
    {


    }

    state=RUNNING;
    return 1;
}

bool game_engine::load__initalize()
{
    load__config();


    if ( SDL_Init( SDL_INIT_EVERYTHING) < 0 )
    {
        std::string errorm="Unable to init SDL: ";
        new message_log(MESSAGE_FATAL_ERROR,errorm+SDL_GetError());
        state=ERRORS;
        return 0;
    }

    string double_buffer="Disabled";
    string full_screen="Disabled";

    if (video.full_screen)
        full_screen="Enabled";
    else
        full_screen="Disabled";

    if (video.double_buffer)
        double_buffer="Enabled";
    else
        double_buffer="Disabled";

    new message_log(MESSAGE_EVENT,  "Entering Video Mode: Width: "+convert_int_string(video.width)+
                                    " Height: "+convert_int_string(video.height)+
                                    " Fullscreen: "+full_screen+
                                    " Double Buffer: "+double_buffer);
    long video_flags=SDL_HWSURFACE;

    if (video.double_buffer)
        video_flags=video_flags|SDL_DOUBLEBUF;

    if (video.full_screen)
        video_flags=video_flags|SDL_FULLSCREEN;

    video.screen = SDL_SetVideoMode(video.width, video.height, 32, video_flags);
    video.format=video.screen->format;

    if (video.screen==NULL)
    {
        std::string errorm="Unable to create window: ";
        new message_log(MESSAGE_FATAL_ERROR,errorm+SDL_GetError());
        state=ERRORS;
        return 0;
    }

    if (Mix_OpenAudio(sound.sample_rate, MIX_DEFAULT_FORMAT, sound.channels, sound.buffer_size)<0)
    {
        new message_log(MESSAGE_FATAL_ERROR,"Unable to init SDL_Mixer");
        state=ERRORS;
        return 0;
    }

    TTF_Init();

}

void game_engine::load__config()
{
    config_file config(this, "config.lua");

    video.full_screen=config.get_int("fullscreen");
    video.double_buffer=config.get_int("double_buffer");
    video.width=config.get_int("screen_width");
    video.height=config.get_int("screen_height");

    map.scale=video.width/video.target_width;

    sound.sample_volume=config.get_int("sound_volume");
    sound.stream_volume=config.get_int("music_volume");

    printf("Sample Volume: %d Music Volume: %d \n",sound.sample_volume,sound.stream_volume);

}

/** update **/

bool sort_control(controller *obj1, controller * obj2)
{
    if (obj1==NULL || obj2==NULL)
        return NULL;

    return obj1->z > obj2->z;
}

bool game_engine::update()
{
    if (!state==RUNNING)
        return 0;

    if (quit_==1)
        return 0;

    SDL_FillRect(video.screen, 0, SDL_MapRGB(video.format, 0, 0, 0));

    update_objects();

    if (event()==0)
        return 0;

    if (game::reset)
    {
        new map_parser(this, map_name);
        game::reset=false;
    }

    SDL_Flip(video.screen);
    return 1;
}

void game_engine::update_objects()
{
    if (!control_data.size()==0)
        std::sort(control_data.begin(),control_data.end(),sort_control);

    std::vector<controller *> new_control;

    for (unsigned int i=0; i <= control_data.size()-1; i++)
    {
        if (control_data.size()==0)
            break;

        if (control_data.at(i)==NULL)
            continue;

        control_data.at(i)->update();

        if (control_data.at(i)->delete_this)
        {
            control_data.at(i)->~controller();
            control_data.at(i)=NULL;
        }
        else
            new_control.push_back(control_data.at(i));
    }

    control_data.swap(new_control);
}


bool game_engine::event()
{
    while (SDL_PollEvent(engine_event))
    {
        switch (engine_event->type)
        {
            case SDL_QUIT:
            {
                return 0;
                break;
            }

            case SDL_KEYDOWN:
            {
                if (engine_event->key.keysym.sym == SDLK_ESCAPE)
                {
                    return 0;
                    break;
                }

                if (engine_event->key.keysym.sym == SDLK_PRINT)
                {
                    time_t rawtime;
                    time ( &rawtime );
                    std::string stimes="./data/screenshots/screen"+convert_int_string(rawtime)+" "+convert_int_string(gmath_random(0,99999))+".bmp";
                    SDL_SaveBMP(video.screen, stimes.c_str());
                    cout << "Screenshot: " << stimes << " added\n";
                }

                if (engine_event->key.keysym.sym == SDLK_PAUSE)
                {
                    break;
                }

            }
        }
    }

    return 1;
}

void game_engine::quit()
{
    quit_=1;
}

game_engine::~game_engine()
{
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();
}
