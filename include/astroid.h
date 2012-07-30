/**
 ** Code Copyright (C) 2011 Jason White <whitewaterssoftwareinfo@gmail.com>
 **                         White Waters Software - wwsoft.co.cc
 **
 ** Copying and distributing this source is prohibited without
 ** explicit authorization by the copyright holder: Jason White
 **/

#ifndef ASTROID_H
#define ASTROID_H

#include "game_engine.h"
#include "game_object.h"
#include "game_math.h"

class astroid : public game_object
{
    public:
        astroid(game_engine * engine, float x=-1, float y=-1);
        void init();
        void reset();
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
        void physics();
        virtual ~astroid();
    protected:
    private:
        void draw();

        float x;
        float y;
        float image_angle;

        int counter;
        gmath_vector vector;

        wwsige_surface * sprite;

        game_engine *gm_engine;
};

#endif // ASTROID_H
