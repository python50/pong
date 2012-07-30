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
#include "message_log.h"
#include "misc.h"


/**
 * Initalize joysticks.
**/
void game_engine::joystick_init()
{
    // Check for joystick
    unsigned int number=SDL_NumJoysticks();

    for (unsigned int i=0;i < number;i++)
    {
        // Open joystick
        joystick_vector.push_back(SDL_JoystickOpen(i));

        if(joystick_vector.at(i))
        {
            new message_log(MESSAGE_DEBUG6, "joystick_init: Opened Joystick "+convert_int_string(i));
            new message_log(MESSAGE_DEBUG6,(string) "joystick_init: Name: "+SDL_JoystickName(i));
            new message_log(MESSAGE_DEBUG6,"joystick_init: Number of Axes: "+convert_int_string(SDL_JoystickNumAxes(joystick_vector.at(i))));
            new message_log(MESSAGE_DEBUG6,"joystick_init: Number of Buttons: "+convert_int_string(SDL_JoystickNumButtons(joystick_vector.at(i))));
            new message_log(MESSAGE_DEBUG6,"joystick_init: Number of Balls: "+convert_int_string(SDL_JoystickNumBalls(joystick_vector.at(i))));
        }
        else
            new message_log(MESSAGE_DEBUG6,"joystick_init: Couldn't open Joystick "+convert_int_string(i));
    }
    if (number < 1)
        new message_log(MESSAGE_DEBUG6,"joystick_init: No Joysticks Available, code "+convert_int_string(number));
}

/**
 * Get the number of joysticks present
 * @return The number of joysticks presents
**/
int game_engine::joystick_number_present()
{
    return joystick_vector.size();
}

/**
 * Get the selected joystick
 * @param number Which joystick to be returned
 * @return The selected joystick
**/
SDL_Joystick * game_engine::joystick_get(unsigned int number)
{
    if (number < joystick_vector.size() && number > -1)
    {
        return joystick_vector.at(number);
    }
    else
        return 0;
}
