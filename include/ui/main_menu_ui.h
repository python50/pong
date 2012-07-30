#ifndef MAIN_MENU_UI_H
#define MAIN_MENU_UI_H

#include <controller.h>
#include "game_engine.h"
#include "text_menu.h"
#include "text.h"


class main_menu_ui : public controller
{
    public:
        main_menu_ui(game_engine * gm_engine);
        void update();
        virtual ~main_menu_ui();
    protected:
    private:
        void create_game();
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
};

#endif // MAIN_MENU_UI_H
