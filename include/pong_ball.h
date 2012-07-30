#ifndef PONG_BALL_H
#define PONG_BALL_H

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
