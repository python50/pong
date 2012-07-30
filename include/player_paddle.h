#ifndef PLAYER_PADDLE_H
#define PLAYER_PADDLE_H

#include <game_engine.h>
#include <controller.h>


class player_paddle : public controller
{
    public:
        player_paddle(game_engine * gm_engine, float x, float y, int player_number);
        virtual void call(std::string item, bool &value);
        virtual void get(std::string item, float &return_value);
        virtual void update();
        virtual ~player_paddle();
    protected:
    private:
        void event();
        void collision();
        game_engine * gm_engine;
        wwsige_surface * sprite;
        static const int base_speed=1;
        float x;
        float y;
        float start_x,start_y;
        int speed_mod;
        int speed;
        int player_number;
};

#endif // PLAYER_PADDLE_H
