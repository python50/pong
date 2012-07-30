#ifndef TEXT_MENU_H
#define TEXT_MENU_H

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
#include "game_engine.h"
#include "text.h"
#include <vector>


/**
 * \brief Generic Text Menu
 *
 * Calls:
 *
 * -select(int, item_number) -1 up, -2 down
 *
 * -push_back(string, text) -add menu item
 *
 * -clear() -clear menu entries
 *
 * Attributes:
 *
 * -x (float)
 *
 * -y (float)
 *
 * -z (float)
 *
 * -delete_this (bool)
 *
 * -persistant (bool)
 *
 * -no_collide (bool)
 *
 * -draw (bool)
 *
*/
class text_menu : public controller
{
    public:
        text_menu(game_engine * gm_engine_, std::string id,float x, float y, float pitch, std::string font_, std::string cursor_name_, int cursor_mode=0, bool drawmode=0);
        /**
            \brief Call an internal function
            \param item             The identification string of the function
            \param value            value to pass to the function
         */
        virtual void call(std::string item, bool &value);

        /**
            \brief Call an internal function
            \param item             The identification string of the function
            \param value            value to pass to the function
         */
        virtual void call(std::string item, int &value);

        /**
            \brief Call an internal function
            \param item             The identification string of the function
            \param value            value to pass to the function
         */
        virtual void call(std::string item, float &value);

        /**
            \brief Call an internal function
            \param item             The identification string of the function
            \param value            value to pass to the function
         */
        virtual void call(std::string item, std::string &value);
        /**
            \brief Get a (bool) variable
            \param item             The identification string of the variable to get, note: if `item` is not a name of a know variable
                                        return_value will not be changed
            \param return_value     A refrence to the variable to be set to the variable to be set by `item`
         */
        virtual void get(std::string item, bool &return_value);
        /**
            \brief Get a (int) variable
            \param item             The identification string of the variable to get, note: if `item` is not a name of a know variable
                                        return_value will not be changed
            \param return_value     A refrence to the variable to be set to the variable to be set by `item`
         */
        virtual void get(std::string item, int &return_value);
        /**
            \brief Get a (float) variable
            \param item             The identification string of the variable to get, note: if `item` is not a name of a know variable
                                        return_value will not be changed
            \param return_value     A refrence to the variable to be set to the variable to be set by `item`
         */
        virtual void get(std::string item, float &return_value);
        /**
            \brief Get a (string) variable
            \param item             The identification string of the variable to get, note: if `item` is not a name of a know variable
                                        return_value will not be changed
            \param return_value     A refrence to the variable to be set to the variable to be set by `item`
         */
        virtual void get(std::string item, std::string &return_value);
        /**
            \brief Set a (bool) variable
            \param item     The identification string of the variable to be set, note: if `item` is not a name of a know variable nothing will happen
            \param value    Value to set item to
         */
        virtual void set(std::string item, bool &value);
        /**
            \brief Set a (int) variable
            \param item     The identification string of the variable to be set, note: if `item` is not a name of a know variable nothing will happen
            \param value    Value to set item to
         */
        virtual void set(std::string item, int &value);
        /**
            \brief Set a (float) variable
            \param item     The identification string of the variable to be set, note: if `item` is not a name of a know variable nothing will happen
            \param value    Value to set item to
         */
        virtual void set(std::string item, float &value);
        /**
            \brief Set a (string) variable
            \param item     The identification string of the variable to be set, note: if `item` is not a name of a know variable nothing will happen
            \param value    Value to set item to
         */
        virtual void set(std::string item, std::string &value);
        /**
            \brief Update text, eg. draw to screen, render a new surface if render_text has changed
         */
        void update();

        ~text_menu();
    protected:
    private:
        void compute_menu();

        game_engine * gm_engine;// Pointer to the game engne, init this FIRST !

        wwsige_surface * cursor;// Surface of the cursor to be used in the menu
        float x,y;              // The Menus x and y coordinates
        float pitch;            // Pitch (line spacing) of the text in pixels
        bool loop_cursor;       // Should the menu cursor loop when it reaches the end of the list
        bool draw_mode;         // Drawing mode, dynamic (0, moves with view) or absolute (1, remains onscreen ie. HUD interface) coordinates
        int selected;           // Index of the menu entery selected, the index is in `menu_text_positions`

        std::string font;                               // ID of the font used to render the text
        std::string cursor_name;                        // ID of the image used for the selection cursor
        std::vector<std::string> menu_text;             // Text contents of the menu, used to create the text objects
        std::vector<controller*> menu_text_objects;     // The text objects used to create the lines [of text] in the menu
        std::vector<unsigned int> menu_text_positions;  // Absolute line number for each new menu entery

        wwsige_color font_color;
};

#endif // TEXT_MENU_H
