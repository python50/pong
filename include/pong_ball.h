#ifndef PONG_BALL_H
#define PONG_BALL_H

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
#include "game_engine.h"
#include <controller.h>
#include "game_math.h"

class pong_ball : public controller
{
    public:
        pong_ball(game_engine * gm_engine_, float x_, float y_,float speed_);
        virtual void call(std::string item, bool &value);
        virtual void get(std::string item, float &return_value);
        void update();
        virtual ~pong_ball();
    private:
        void collision();

        game_engine * gm_engine;

        float start_x,start_y,x,y;
        float speed;
        int counter;
        wwsige_surface * sprite;
        gmath_vector vector;
};

#endif // PONG_BALL_H
