#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <controller.h>
#include "game_engine.h"

class game_object : public controller
{
    public:
        game_object();
        virtual ~game_object();
        game_engine * gm_engine;
    protected:
    private:

};

#endif // GAME_OBJECT_H
