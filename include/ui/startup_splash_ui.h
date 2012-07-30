#ifndef STARTUP_SPLASH_UI_H
#define STARTUP_SPLASH_UI_H

#include "game_engine.h"
#include "controller.h"

class startup_splash_ui : public controller
{
    public:
        startup_splash_ui(game_engine * gm_engine);
        void update();
        virtual ~startup_splash_ui();
    protected:
    private:
        game_engine * gm_engine;
        wwsige_surface * background;

        int counter;
};

#endif // STARTUP_SPLASH_UI_H
