#ifndef GAME_MATH_H_INCLUDED
#define GAME_MATH_H_INCLUDED

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

struct gmath_vector
{
    float angle;
    float magnitude;
    float speed;
    float mass;
    float x;
    float y;
};

void gmath_randomize();
int gmath_random(int low , int high);
float gmath_direction(float x1, float y1, float x2, float y2);
float gmath_distance(float x1, float y1,float x2, float y2);

float gmath_to_deg(float rad);
float gmath_to_rad(float deg);


void gmath_compute_vector(gmath_vector &vec);
//Vector A+Vector B
void gmath_add_vector(gmath_vector &a,gmath_vector &b, bool unsafe=0);//, gmath_vector * c=0, gmath_vector * d=0, gmath_vector * e=0);

#endif // GAME_MATH_H_INCLUDED
