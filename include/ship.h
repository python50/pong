/**
 ** Code Copyright (C) 2011 Jason White <whitewaterssoftwareinfo@gmail.com>
 **                         White Waters Software - wwsoft.co.cc
 **
 ** Copying and distributing this source is prohibited without
 ** explicit authorization by the copyright holder: Jason White
 **/

#ifndef SHIP_H
#define SHIP_H

#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_net.h"
#include "game_math.h"

#include "game_engine.h"
#include "game_object.h"
#include "message_log.h"

#include <vector>


class ship : public game_object
{
    public:
        ship(game_engine * gm_engine,float x, float y);
        virtual void init();
        virtual void reset();
        virtual void load();
        virtual void save();
        virtual void pause();
        virtual void unpause();
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
        void update();
        virtual ~ship();
    protected:
    private:
        void draw();
        void event();
        void physics();

        //

        int kup, kdown, kleft, kright;

        //

        float x;
        float y;
        float direction;
        float image_angle;
        float speed;
        float friction;
        float image_offset;
        float start_x;
        float start_y;
        float start_direction;
        std::vector<wwsige_surface *> sprites;
        game_engine * gm_engine;
        int shot_counter;
        int reset_counter;
        bool god;

        gmath_vector vector;

        SDL_Joystick * joystick;
};

#endif // SHIP_H
