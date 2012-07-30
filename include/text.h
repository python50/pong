#ifndef TEXT_H
#define TEXT_H

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
#include <controller.h>
#include <vector>
#include "game_engine.h"

enum text_justify
{
    TEXT_JUSTIFY_LEFT=0,
    TEXT_JUSTIFY_RIGHT=1,
    TEXT_JUSTIFY_CENTER=2,
    TEXT_JUSTIFY_TOP=3,
    TEXT_JUSTIFY_BOTTOM=4,
    TEXT_JUSTIFY_MIDDLE=5
};

/*! \brief A generic in-game text class

    list of varibles (get/set);

        bool

            enable - enable drawing

            shadow - presence of a text shadow

            draw - draw in dynamic or absolute mode

        int

            font_red - font color (0-255)

            font_green - font color (0-255)

            font_blue - font color (0-255)

            font_alpha - font alpha (0-255)

            shadow_red - shadow color (0-255)

            shadow_green - shadow color (0-255)

            shadow_blue - shadow color (0-255)

            justify_horizontal - were the text is in relationship to the xy position (or rather the other way around)

            justify_vertical -

            *lines - number of lines the text occupies

            *size - number of chars

        float

            x - x position

            y - y position

            z - z position

        string




 */

class text : public controller
{
    public:

        /**
            Contructer for class `text`
            \param gm_engine_   A pointer to the game engine
            \param id           The objects (hopefully) unique identification string
            \param x            The objects x position
            \param y            The objects y position
            \param font         The identification string of the font to be used
            \param text         The text to be contained
            \param drawmode     0 Dynamic, 1 Absolute
         */
        text(game_engine * gm_engine_, std::string id, float x, float y, std::string font, std::string text, bool drawmode=0);



        /**
            \brief Get a (bool) variable
            \param item             The identification string of the variable to get, note: if `item` is not a name of a know variable
                                        return_value will not be changed
            \param return_value     A refrence to the variable to be set to the variable to be set by `item`
         */
        virtual void get(std::string item, bool &return_value);

        /*!
            \brief Get a (int) variable
            \param item             The identification string of the variable to get, note: if `item` is not a name of a know variable
                                        return_value will not be changed
            \param return_value     A refrence to the variable to be set to the variable to be set by `item`
         */
        virtual void get(std::string item, int &return_value);
        /*!
            \brief Get a (float) variable
            \param item             The identification string of the variable to get, note: if `item` is not a name of a know variable
                                        return_value will not be changed
            \param return_value     A refrence to the variable to be set to the variable to be set by `item`
         */
        virtual void get(std::string item, float &return_value);
        /*!
            \brief Get a (string) variable
            \param item             The identification string of the variable to get, note: if `item` is not a name of a know variable
                                        return_value will not be changed
            \param return_value     A refrence to the variable to be set to the variable to be set by `item`
         */
        virtual void get(std::string item, std::string &return_value);
        /*!
            \brief Set a (bool) variable
            \param item     The identification string of the variable to be set, note: if `item` is not a name of a know variable nothing will happen
            \param value    Value to set item to
         */
        virtual void set(std::string item, bool &value);
        /*!
            \brief Set a (int) variable
            \param item     The identification string of the variable to be set, note: if `item` is not a name of a know variable nothing will happen
            \param value    Value to set item to
         */
        virtual void set(std::string item, int &value);
        /*!
            \brief Set a (float) variable
            \param item     The identification string of the variable to be set, note: if `item` is not a name of a know variable nothing will happen
            \param value    Value to set item to
         */
        virtual void set(std::string item, float &value);
        /*!
            \brief Set a (string) variable
            \param item     The identification string of the variable to be set, note: if `item` is not a name of a know variable nothing will happen
            \param value    Value to set item to
         */
        virtual void set(std::string item, std::string &value);
        /*!
            \brief Update text, eg. draw to screen, render a new surface if render_text has changed
         */
        void update();
        virtual ~text();
    protected:
    private:
        /*!
            \brief Render a new surface containing render_text using the font referenced by `font`
         */
        void render();
        std::vector<string> process_text(std::string text_);

        float x,y;

        game_engine * gm_engine;
        vector<wwsige_surface *> sprite_forground;
        //SDL_Surface * sprite_background;
        bool enable;
        bool change;
        bool shadow;
        text_justify justify_horizontal;
        text_justify justify_vertical;
        std::string font;
        std::vector <std::string> render_text;
        std::string raw_text;
        wwsige_color font_color;
        wwsige_color font_bgcolor;

        int ptsize;
        unsigned int lines;
        unsigned int size;

        bool draw;
};

#endif // TEXT_H
