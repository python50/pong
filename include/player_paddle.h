#ifndef PLAYER_PADDLE_H
#define PLAYER_PADDLE_H


/**
 * @file
 * @author  Jason White <jason@jswhite.net> <whitewaterssoftwareinfo@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 * PONG - The open source pong clone Copyright (C) 2012 Jason White
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
#include <game_engine.h>
#include <controller.h>


class player_paddle : public controller
{
    public:
        player_paddle(game_engine * gm_engine, float x, float y, int player_number);
        virtual void call(std::string item, bool &value);
        virtual void get(std::string item, float &return_value);
        virtual void update();
        virtual ~player_paddle();
    protected:
    private:
        void event();
        void collision();
        game_engine * gm_engine;
        wwsige_surface * sprite;
        static const int base_speed=1;
        float x;
        float y;
        float start_x,start_y;
        int speed_mod;
        int speed;
        int player_number;
};

#endif // PLAYER_PADDLE_H
