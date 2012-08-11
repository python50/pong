#ifndef MAIN_MENU_UI_H
#define MAIN_MENU_UI_H

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

#include <controller.h>
#include "game_engine.h"
#include "text_menu.h"
#include "text.h"


class main_menu_ui : public controller
{
    public:
        main_menu_ui(game_engine * gm_engine);
        bool update();
        virtual ~main_menu_ui();
    protected:
    private:
        void create_game();
        void set_screen_text(int position);
        void do_menu_item(int position);
		void config_menu();
		
        game_engine * gm_engine;

        text_menu * menu;
        text * copyright_text;

        wwsige_surface * background;
        wwsige_surface * foreground;

        int tile_width;
        int tile_height;
        int width;
        int height;

        int counter;
        bool direction;

        char * start_text;
        char * help_text;
        char * options_text;
        char * about_text;
        char * quit_text;

};

#endif // MAIN_MENU_UI_H
