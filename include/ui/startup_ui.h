#ifndef STARTUP_UI_H
#define STARTUP_UI_H

#include <controller.h>
#include "game_engine.h"

class startup_ui : public controller
{
    public:
        startup_ui(game_engine * gm_engine);
        void update();
        virtual ~startup_ui();
    protected:
    private:
        void load_next();
        game_engine * gm_engine;
        wwsige_surface * background;
        int counter;
};

#endif // STARTUP_UI_H
