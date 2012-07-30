/**
 ** Code Copyright (C) 2011 Jason White <whitewaterssoftwareinfo@gmail.com>
 **                         White Waters Software - wwsoft.co.cc
 **
 ** Copying and distributing this source is prohibited without
 ** explicit authorization by the copyright holder: Jason White
 **/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "game_engine_datatypes.h"
#include <iostream>
#include "SDL.h"

class controller
{
    public:
        controller();

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
        virtual void update();
        virtual void init();
        virtual void reset();
        virtual void pause();
        virtual void unpause();
        virtual ~controller();

        bool delete_this;
        bool persistant;
        bool no_collide;
        SDL_Rect rect;
        std::string id_type;
        float z;

    protected:
    private:
        virtual void draw();
};

#endif // CONTROLLER_H
