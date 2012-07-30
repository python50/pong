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
#include "game_math.h"
#include "stdlib.h"
#include "time.h"
#include <iostream>
#include <math.h>


void gmath_randomize()
{
    srand ( time(NULL) );
}

int gmath_random(int low , int high)
{
    return rand() % (high-low+1) + low;
}

float gmath_direction(float x1, float y1, float x2, float y2)
{
    float dx=x2-x1;
    float dy=y2-y1;

    return atan2(dy,dx);
}

float gmath_distance(float x1, float y1,float x2, float y2)
{
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}


void gmath_compute_vector(gmath_vector &compute_vector)
{
    compute_vector.magnitude=compute_vector.speed*compute_vector.mass;
    compute_vector.x= cos(compute_vector.angle*M_PI/180)*compute_vector.speed;
    compute_vector.y=-sin(compute_vector.angle*M_PI/180)*compute_vector.speed;
   // std::cout << " speed " << compute_vector.speed << " mass " << compute_vector.mass << "" << compute_vector.angle << "\n";
}

void gmath_add_vector(gmath_vector &a,gmath_vector &b, bool unsafe)
{
    //std::cout
    if (!unsafe)
    {
        gmath_compute_vector(a);
        gmath_compute_vector(b);
    }

    a.x= cos(a.angle*M_PI/180)*a.magnitude;
    a.y= sin(a.angle*M_PI/180)*a.magnitude;

    a.x+= cos(b.angle*M_PI/180)*b.magnitude;
    a.y+= sin(b.angle*M_PI/180)*b.magnitude;

    //std::cout << a.x << "  " << a.y << "\n";

    a.angle=gmath_direction(0,0,a.x,a.y)/M_PI*180;

    a.magnitude=gmath_distance(0,0,a.x,a.y);
    a.speed=a.magnitude/a.mass;

    if (a.magnitude < 0)
        a.magnitude=-a.magnitude;

    if (a.angle < 0)
        a.angle=360+a.angle;
    if (a.angle > 360)
        a.angle=a.angle-360;
}
