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
