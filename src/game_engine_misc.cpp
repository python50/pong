/**
 * @file
 * @author  Jason White <whitewaterssoftwareinfo@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 * @section DESCRIPTION
 *
 * This file contains all miscellaneous game_engine functions
 */

#include "game_engine.h"
#include "message_log.h"


/**
 * Scale a number (eg.number of pixels) to match the scale of the sceen
 */
double game_engine::scale_value(double value)
{
    return value* map.scale;
}
