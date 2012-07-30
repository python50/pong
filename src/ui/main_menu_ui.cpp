#include "main_menu_ui.h"
#include "player_paddle.h"
#include "game_math.h"
#include "shot.h"
#include "message_log.h"
#include "misc.h"
#include "tile.h"
#include "pong_ball.h"
main_menu_ui::main_menu_ui(game_engine * gm_engine_)
{
    gm_engine=gm_engine_;
    menu=new text_menu(gm_engine,"main-menu",10,100,46,"jura_bold-34","cursor-48",0,1);

    gm_engine->add_object(new text(gm_engine, "copyright-text", 0, 0, "jura_medium-12",
"Copyright 2012 (C) Jason White##\
V0.11 - 5/28/2012##\
Development", 1));
    gm_engine->add_object(new text(gm_engine, "title-text", 150, 50, "jura_bold-48","PONG",1));
    gm_engine->add_object(new text(gm_engine, "info-text", 150, 100, "jura_medium-24",
"This is a DEMO Of the WWSiGE Engine##\
##\
This particular DEMO is a CLONE of the##\
GAME \"PONG\". If you are not familiar with##\
\"PONG\", Why are you here ?##\
##\
--- CONTROLS ---##\
  UP - Player 0 Up##\
  W - Player 1 Up##\
  DOWN - Player 0 Down##\
  S - Player 1 Down##\
##\
--- About ---##\
  By Jason White##\
  As a Coding Demo", 1));
    int value=0;
    gm_engine->get_object("info-text")->set("font_red",value);
    gm_engine->get_object("info-text")->set("font_blue",value);

    gm_engine->get_object("title-text")->set("font_red",value);
    gm_engine->get_object("title-text")->set("font_blue",value);

    gm_engine->get_object("copyright-text")->set("font_red",value);
    gm_engine->get_object("copyright-text")->set("font_blue",value);



    delete_this=0;
    persistant=0;
    no_collide=0;

    z=10;

    menu->set("font_red",value=0x00);
    menu->set("font_green",value=0xFF);
    menu->set("font_blue",value=0x00);
    menu->set("font_alpha",value=0xFF);

    std::string mtext;
    menu->call("push_back",mtext="Start");
    menu->call("push_back",mtext="Quit");

    gm_engine->add_object(menu);

    background=gm_engine->get_surface("background-circuit");
    //foreground=gm_engine->get_surface("background-space0");

    width=8;
    height=7;
    tile_width=background->data->w;
    tile_height=background->data->h;
    counter=0;
    direction=0;

    if (gm_engine->music_get_playing()==0)
        gm_engine->music_play("startup",-1);

}

void main_menu_ui::create_game()
{
    gm_engine->music_stop();

    SDL_Rect view;
    view.x=0;
    view.y=0;
    gm_engine->view_set(view);
    gm_engine->clear_objects();

    gm_engine->game_init();

}

void main_menu_ui::update()
{
    counter++;

    if (!direction)
        gm_engine->view_translate(5,2);
    else
        gm_engine->view_translate(-5,-2);

    if (gm_engine->view_get().x >= (width-1)*tile_width)
        direction=1;
    if (gm_engine->view_get().x <= 0)
        direction=0;

    for(int i=0;i < width;i++)
    {
        for(int j=0; j < height;j++)
        {
            gm_engine->blit(i*tile_width,j*tile_height,background,BLIT_DYNAMIC);
        }
    }


    if (counter > 5)
    {
        counter=0;

        Uint8 *keystate = SDL_GetKeyState(NULL);

        if ( keystate[SDLK_UP] )
        {
            int selection=-1;
            menu->call("select",selection);
            gm_engine->sound_play("menu_ding");
        }
        else if (keystate[SDLK_DOWN])
        {
            int selection=-2;
            menu->call("select",selection);
            gm_engine->sound_play("menu_ding");
        }

        if (keystate[SDLK_SPACE] || keystate[SDLK_RETURN] )
        {
            int selected;
            menu->get("selected", selected=0);

            if (selected==0)
            {
                new message_log(MESSAGE_DEBUG4,"main_menu_ui: start");
                create_game();
                return;
            }
            else if (selected==1)
            {
                new message_log(MESSAGE_DEBUG4,"main_menu_ui: quit");
                gm_engine->music_stop();
                gm_engine->quit();
            }
            else
            {
                new message_log(MESSAGE_DEBUG4,"main_menu_ui: menu selection out of range `"+convert_int_string(selected)+"`");
            }
        }

    }

    //gm_engine->blit(0,0,foreground,BLIT_ABSOLUTE);
}

main_menu_ui::~main_menu_ui()
{
    new message_log(MESSAGE_DEBUG3,"main_menu_ui destroyed");
}
