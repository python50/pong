#ifndef STARTUP_SPLASH_UI_H
#define STARTUP_SPLASH_UI_H

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
#include "controller.h"

class startup_splash_ui : public controller
{
    public:
        startup_splash_ui(game_engine * gm_engine);
        void update();
        virtual ~startup_splash_ui();
    protected:
    private:
        void load_next();
        game_engine * gm_engine;
        wwsige_surface * background;

        int counter;
};

#endif // STARTUP_SPLASH_UI_H
