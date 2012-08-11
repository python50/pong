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
#include "game_engine.h"
#include "message_log.h"
#include "text.h"
#include "tile.h"
#include "player_paddle.h"
#include "pong_ball.h"
#include "misc.h"
void game_engine::game_init()
{
    gameplay.counter=0;
    gameplay.score_limit=1;
    gameplay.state=GAME_START;

    music_play("game_play",-1);

    add_object(new tile(this, 0, 0, 100, "background-circuit", ""));
    add_object(new player_paddle(this,16,view_get().h/2-24, (int) 0) );
    add_object(new player_paddle(this,view_get().w-16-16, view_get().h/2-24, (int) 1) );
    add_object(new pong_ball(this , 320-8, 240-8, 9));

    for(int i=0; i < view_get().h;i+=64)
        add_object(new tile(this,view_get().w/2-2,i,100,"line","line"));
}

void game_engine::game_logic_start()
{

    if (gameplay.counter==0)
    {
        controller * start_text=new text(this, "start-text",320,200,"jura_bold-48", "GET READY !\nSCORE LIMIT: "+convert_int_string(gameplay.score_limit));
        int value;
        start_text->set("font_red",value=0);
        start_text->set("font_green",value=0xff);
        start_text->set("font_blue",value=0);
        start_text->set("justify_horizontal",value=TEXT_JUSTIFY_CENTER);
        add_object(start_text);

        gameplay.player0_score=0;
        gameplay.player1_score=0;
    }

    gameplay.counter++;
    if (gameplay.counter > 65000)
        gameplay.counter=100;

    if (gameplay.counter%30==1 and gameplay.counter > 15)
    {
        bool value=0;
        get_object("start-text")->get("enable",value);
        value=!value;
        get_object("start-text")->set("enable",value);
    }

    if (gameplay.counter > 60)
    {
        //Uint8 *keystate = SDL_GetKeyState(NULL);
        //if (keystate[SDLK_SPACE] )
        //{
            gameplay.state=GAME_PLAYING;
            remove_object("start-text");
            gameplay.counter=0;
        //}
    }
}

void game_engine::game_logic_playing()
{
    if (gameplay.counter==0)
    {
        controller * score0_text=new text(this, "score0-text",280,20,"jura_bold-48", "0");
        controller * score1_text=new text(this, "score1-text",360,20,"jura_bold-48", "0");

        int value;
        score0_text->set("font_red",value=0);
        score0_text->set("font_green",value=0xff);
        score0_text->set("font_blue",value=0);
        score0_text->set("justify_horizontal",value=TEXT_JUSTIFY_CENTER);
        add_object(score0_text);

        score1_text->set("font_red",value=0);
        score1_text->set("font_green",value=0xff);
        score1_text->set("font_blue",value=0);
        score1_text->set("justify_horizontal",value=TEXT_JUSTIFY_CENTER);
        add_object(score1_text);
        gameplay.counter++;
    }
    string value;
    get_object("score0-text")->set("text",value=convert_int_string(gameplay.player0_score));
    get_object("score1-text")->set("text",value=convert_int_string(gameplay.player1_score));

    if (gameplay.player0_score >= gameplay.score_limit)
    {
        gameplay.counter=0;
        gameplay.state=GAME_WIN0;
        remove_object("score0-text");
        remove_object("score1-text");

        music_stop();
        music_play("game_over", -1);
    }

    if (gameplay.player1_score >= gameplay.score_limit)
    {
        gameplay.counter=0;
        gameplay.state=GAME_WIN1;
        remove_object("score0-text");
        remove_object("score1-text");

        music_stop();
        music_play("game_over", -1);
    }
}

void game_engine::game_logic_pause()
{

}

void game_engine::game_logic_win0()
{
    if (gameplay.counter==0)
    {
        controller * win_text=new text(this, "win-text",320,200,"jura_bold-48", "PLAYER 1 WINS\nPRESS ENTER");
        int value;
        win_text->set("font_red",value=0);
        win_text->set("font_green",value=0xff);
        win_text->set("font_blue",value=0);
        win_text->set("justify_horizontal",value=TEXT_JUSTIFY_CENTER);
        add_object(win_text);
        gameplay.counter++;
    }


    gameplay.counter++;
    if (gameplay.counter > 65000)
        gameplay.counter=100;

    if (gameplay.counter%30==1 and gameplay.counter > 15)
    {
        bool value=0;
        get_object("win-text")->get("enable",value);
        value=!value;
        get_object("win-text")->set("enable",value);
    }

    if (gameplay.counter > 15)
    {
        Uint8 *keystate = SDL_GetKeyState(NULL);
        if (keystate[SDLK_SPACE] or keystate[SDLK_RETURN])
        {
            gameplay.state=GAME_OVER;
            remove_object("win-text");
            gameplay.counter=0;

            music_stop();
            music_play("game_play", -1);
        }
    }
}

void game_engine::game_logic_win1()
{
    if (gameplay.counter==0)
    {
        controller * win_text=new text(this, "win-text",320,200,"jura_bold-48", "PLAYER 0 WINS\nPRESS ENTER");
        int value;
        win_text->set("font_red",value=0);
        win_text->set("font_green",value=0xff);
        win_text->set("font_blue",value=0);
        win_text->set("justify_horizontal",value=TEXT_JUSTIFY_CENTER);
        add_object(win_text);
        gameplay.counter++;
    }


    gameplay.counter++;
    if (gameplay.counter > 65000)
        gameplay.counter=100;

    if (gameplay.counter%30==1 and gameplay.counter > 15)
    {
        bool value=0;
        get_object("win-text")->get("enable",value);
        value=!value;
        get_object("win-text")->set("enable",value);
    }

    if (gameplay.counter > 15)
    {
        Uint8 *keystate = SDL_GetKeyState(NULL);
        if (keystate[SDLK_SPACE] or keystate[SDLK_RETURN])
        {
            gameplay.state=GAME_OVER;
            remove_object("win-text");
            gameplay.counter=0;

            music_stop();
            music_play("game_play", -1);
        }
    }
}

void game_engine::game_logic_over()
{
	//clear_objects();
	music_stop();
	music_play("startup",-1);
	load_map("./data/map/menu/main.lua");
}

void game_engine::game_logic()
{

    if (gameplay.state==GAME_START)
        game_logic_start();

    if (gameplay.state==GAME_PLAYING)
        game_logic_playing();

    if (gameplay.state==GAME_PAUSED)
        game_logic_pause();

    if (gameplay.state==GAME_WIN0)
        game_logic_win0();

    if (gameplay.state==GAME_WIN1)
        game_logic_win1();
    
    if (gameplay.state==GAME_OVER)
        game_logic_over();
}

void game_engine::game_score(int player_number, int points)
{
    if (player_number==0)
        gameplay.player0_score++;
    if (player_number==1)
        gameplay.player1_score++;
}

int  game_engine::game_get_score_limit()
{
    return gameplay.score_limit;
}

void game_engine::game_set_score_limit()
{

}

game_state game_engine::game_get_state()
{
    return gameplay.state;
}

int game_engine::game_get_width()
{
    return map.scale_width;
}

int game_engine::game_get_height()
{
    return map.scale_height;
}

int game_engine::game_get_abswidth()
{
    return map.abs_width;
}

int game_engine::game_get_absheight()
{
    return map.abs_height;
}

int game_engine::game_get_scale()
{
    return map.scale;
}

void game_engine::game_set_map_information(map_information * info)
{
    map=*info;
}
