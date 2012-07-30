#include "startup_splash_ui.h"
#include "message_log.h"
#include "SDL_image.h"
startup_splash_ui::startup_splash_ui(game_engine * gm_engine_)
{
    gm_engine=gm_engine_;
    new message_log(MESSAGE_DEBUG4,"startup_splash_ui: Created");

    delete_this=0;
    persistant=0;
    no_collide=0;

    z=10;
    counter=0;

    background=gm_engine->get_surface("background-splash");
}

void startup_splash_ui::update()
{
    counter++;
    if (counter > 6)
    {
        gm_engine->load_map("./data/map/menu/main.lua");
        return;
    }
    gm_engine->blit(0,0,background,BLIT_ABSOLUTE);
}


startup_splash_ui::~startup_splash_ui()
{
    new message_log(MESSAGE_DEBUG4,"startup_splash_ui: Destroyed");
}
