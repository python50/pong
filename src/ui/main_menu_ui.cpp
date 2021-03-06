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
#include "game_math.h"
#include "main_menu_ui.h"
#include "message_log.h"
#include "misc.h"
#include "player_paddle.h"
#include "pong_ball.h"
#include "tile.h"

main_menu_ui::main_menu_ui(game_engine * gm_engine_)
{
    gm_engine=gm_engine_;

    start_text=
"Welcome to PONG the open source\n\
PONG clone.\n\
\n\
Press Enter To Start\n\
\n\
\n\
\n\
\n\
\n\
\n\
--- Project Page --- Get the source at:\n\
github.com/python50/pong\n\
\n\
--- Like the game ? ---\n\
Let me know at Jason@JSWhite.net";

    help_text=
"--- Controls ---\n\
Keyboard:\n\
  --- Player 0 (Left) ---\n\
    UP     - Player 0 Up\n\
    DOWN - Player 0 Down\n\
  --- Player 1 (Right) ---\n\
    W     - Player 1 Up\n\
    S      - Player 1 Down\n\
\n\
Joysticks are also supported\n\
Simply add them before you start\n\
the game, joystick input will be\n\
enabled upon the detection of one\n\
or more input devices";

    options_text=
"--- Options ---\n\
You can't set options here.\n\
Better luck next release ...\n\
\n\
--- Input Modes ---\n\
    Player 0 -\n\
    Player 1  -\n\
--------------------------\n\
Settings in config.lua\n\
--------------------------\n\
Video: 640x480\n\
Fullscreen:\n\
Double Buffer:\n\
Sound Volume -\n\
Music Volume  -";

    about_text=
"--- About PONG 0.12 ----\n\
This game was written by Jason White -initially\n\
as a coding demo for a friend. Since then,\n\
it has matured into a open source project.\n\
\n\
All code, graphics, and sound effects:\n\
        Copyright (C) 2012 Jason White,\n\
        White Waters Software\n\
        All Rights Reserved.\n\
Source code ONLY:\n\
        Released under the GPLv3 License\n\
Music by a varity of people including:\n\
        gr0gg0, lemonade, maxuser6000, CrizZ,\n\
        rhodes, demosausje, Steam, Elwood\n\
Be sure to thank them for making such good stuff";

    quit_text=
"Leaving so soon ?";

    menu=new text_menu(gm_engine,"main-menu",5,100,46,"jura_bold-34","cursor-48",0,1);

    gm_engine->add_object(new text(gm_engine, "copyright-text", 0, 0, "jura_medium-12",
"PONG Copyright 2012 (C) Jason White\n\
V0.12 - 8/1/2012\n\
Development Version\n\
Program licenced under the GNU GPLv3", 1));
    
    gm_engine->add_object(new text(gm_engine, "title-text", 150, 50, "jura_bold-48","PONG",1));
    gm_engine->add_object(new text(gm_engine, "info-text", 165, 100, "jura_medium-24", start_text, 1));
  
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
    menu->call("push_back",mtext="Help");
    menu->call("push_back",mtext="Options");
    menu->call("push_back",mtext="About");
    menu->call("push_back",mtext="Quit");

    gm_engine->add_object(menu);

    background=gm_engine->get_surface("background-circuit");

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

void main_menu_ui::set_screen_text(int selected)
{
    if (selected==0)
    {
        //start
        string text=start_text;
        gm_engine->get_object("info-text")->set("text", text);
        text="jura_medium-24";
        gm_engine->get_object("info-text")->set("font", text);

        return;
    }
    else if (selected==1)
    {
        //help
        string text=help_text;
        gm_engine->get_object("info-text")->set("text", text);
        text="jura_medium-24";
        gm_engine->get_object("info-text")->set("font", text);
        return;
    }
    else if (selected==2)
    {
        //options
        string text=options_text;
        gm_engine->get_object("info-text")->set("text", text);
        text="jura_medium-24";
        gm_engine->get_object("info-text")->set("font", text);
        return;
    }
    else if (selected==3)
    {
        //about
        string text=about_text;
        gm_engine->get_object("info-text")->set("text", text);
        text="jura_medium-18";
        gm_engine->get_object("info-text")->set("font", text);
        return;
    }
    else if (selected==4)
    {
        //quit
        string text=quit_text;
        gm_engine->get_object("info-text")->set("text", text);
        text="jura_medium-24";
        gm_engine->get_object("info-text")->set("font", text);
        return;
    }
    else
    {
        new message_log(MESSAGE_DEBUG4,"main_menu_ui: menu selection out of range `"+convert_int_string(selected)+"`");
    }
}

void main_menu_ui::do_menu_item(int selected)
{
    if (selected==0)
    {
        //start
        create_game();
        return;
    }
    else if (selected==1)
    {
        //Help
        return;
    }
    else if (selected==2)
    {
        //Options
        return;
    }
    else if (selected==3)
    {
        //About
        return;
    }
    else if (selected==4)
    {
        //Quit
        gm_engine->music_stop();
        gm_engine->quit();
    }
    else
    {
        new message_log(MESSAGE_DEBUG4,"main_menu_ui: menu selection out of range `"+convert_int_string(selected)+"`");
    }
}
bool main_menu_ui::update()
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

            menu->get("selected",selection);
            set_screen_text(selection);
        }
        else if (keystate[SDLK_DOWN])
        {
            int selection=-2;
            menu->call("select",selection);
            gm_engine->sound_play("menu_ding");

            menu->get("selected",selection);
            set_screen_text(selection);
        }

        if (keystate[SDLK_SPACE] || keystate[SDLK_RETURN] )
        {
            int selection;
            menu->get("selected",selection);
            do_menu_item(selection);
        }

    }
	
	int selection;
	menu->get("selected",selection);
	if (selection==2)
		config_menu();
	
	
	return delete_this;
}

void main_menu_ui::config_menu()
{
	
}

main_menu_ui::~main_menu_ui()
{
    new message_log(MESSAGE_DEBUG3,"main_menu_ui destroyed");
}
