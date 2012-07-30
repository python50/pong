/**
 * @file
 * @author  Jason White <whitewaterssoftwareinfo@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 * @section DESCRIPTION
 *
 * This file contains all game_engine functions related to joysticks
 */

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
