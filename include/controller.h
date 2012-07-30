#ifndef CONTROLLER_H
#define CONTROLLER_H

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
#include "game_engine_datatypes.h"
#include <iostream>
#include "SDL.h"

class controller
{
    public:
        controller();

        virtual void call(std::string item, bool &value);
        virtual void call(std::string item, int &value);
        virtual void call(std::string item, float &value);
        virtual void call(std::string item, std::string &value);
        virtual void get(std::string item, std::string &return_value);
        virtual void get(std::string item, bool &return_value);
        virtual void get(std::string item, int &return_value);
        virtual void get(std::string item, float &return_value);
        virtual void set(std::string item, bool &value);
        virtual void set(std::string item, int &value);
        virtual void set(std::string item, float &value);
        virtual void set(std::string item, std::string &value);
        virtual void update();
        virtual void init();
        virtual void reset();
        virtual void pause();
        virtual void unpause();
        virtual ~controller();

        bool delete_this;
        bool persistant;
        bool no_collide;
        SDL_Rect rect;
        std::string id_type;
        float z;

    protected:
    private:
        virtual void draw();
};

#endif // CONTROLLER_H
