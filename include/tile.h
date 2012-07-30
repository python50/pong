#ifndef TILE_H
#define TILE_H

#include "game_engine.h"
#include "game_object.h"

/**
 * \brief Generic tile class
 *
 * Attributes:
 *
 * -x (float)
 *
 * -y (float)
 *
 * -z (float)
 *
 * -no_collide (bool)
 *
 * -delete_this (bool)
 *
 * -persistant (bool)
 *
 * -id_type (string)
 */
class tile : public game_object
{
    public:
        tile(game_engine * gengine,float x, float y, float z, std::string image, std::string id="");
        virtual void update();
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
        virtual ~tile();
    protected:
    private:
        game_engine * gm_engine;
        wwsige_surface * sprite;
        float x;
        float y;
};

#endif // TILE_H
