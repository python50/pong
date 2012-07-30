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


/**
 * Compares two SDL_Rect s to see if they overlap
 * @param a The first SDL_Rect to compare
 * @param b The second SDL_Rect to compare
 * @return 1 if the overlap, 0 if they don't
**/
bool game_engine::rect_collide(SDL_Rect a , SDL_Rect b)
{
	if(b.x + b.w < a.x)	return 0;	//just checking if their
	if(b.x > a.x + a.w)	return 0;	//bounding boxes even touch

	if(b.y + b.h < a.y)	return 0;
	if(b.y > a.y + a.h)	return 0;

	return 1;				//bounding boxes intersect
}

/**
 * Compares a SDL_Rect to every object within the game loop to see if they overlap.
 * Then tests to se fi they are of the correct objec type
 * @param rect The SDL_Rect to compare
 * @param selfp A Pointer the the object you wish to exclude from comparison (eg. self)
 * @param id The object type you would like to test for, use an empty string to exclude this test
 * @return 1 if the overlap, 0 if they don't
**/
controller * game_engine::rect_collide_all(SDL_Rect rect,controller * selfp, std::string id)
{
    unsigned int size = control_data.size();

    SDL_Rect r1= rect;
    std::vector<controller*> a = control_data;

    for(unsigned int i=0;i < size;i+=1)
    {

        if (control_data.at(i)==NULL)
            continue;

        if (control_data.at(i)->no_collide)
            continue;

        if ( rect_collide(rect, control_data.at(i)->rect ) )
        {

            SDL_Rect r2= control_data.at(i)->rect;

            if ( control_data.at(i)==selfp)
            {
                continue;
            }
            else
            {
                if (id!="")
                {
                    if (control_data.at(i)->id_type==id)
                        return control_data.at(i);
                    else
                        continue;
                }
                else
                    return control_data.at(i);
            }
        }

    }

    return NULL;
}
