/**
 ** Code Copyright (C) 2011 Jason White <whitewaterssoftwareinfo@gmail.com>
 **                         White Waters Software - wwsoft.co.cc
 **
 ** Copying and distributing this source is prohibited without
 ** explicit authorization by the copyright holder: Jason White
 **/

#ifndef GAME_MATH_H_INCLUDED
#define GAME_MATH_H_INCLUDED

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
