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
#include "game_engine.h"
#include "message_log.h"
#include "math.h"

/**
 * Render a drawing surface with the provided font, text, and colors
 * @param font The string identifier of the desired font
 * @param text The text to be rendered
 * @param fgR Foreground red (0-255) [text color]
 * @param fgG Foreground green (0-255) [text color]
 * @param fgB Foreground blue (0-255) [text color]
 * @param fgA Foreground alpha (0-255) [text transparency]
 * @param bgR Background red (0-255)
 * @param bgG Background green (0-255)
 * @param bgB Background blue (0-255)
 * @param bgA Background alpha (0-255) [transparency]
 * @param quality Quality of the text rendering. Can be: solid - ugly but fast, shaded - ok looking and not terribly slow, blended - good looking and slow
 * @return A pointer to the rendered surface, 0 on failure
**/
wwsige_surface * game_engine::render_text(std::string font, std::string text, wwsige_color foreground ,wwsige_color background , textquality quality)
{
    TTF_Font * fonttodraw=get_font(font)->data;

    if (fonttodraw==NULL)
    {
        return NULL; //depth argument must be fixed to change with diffrenent screen bit depths
    }

    SDL_Color tmpfontcolor = {foreground.red, foreground.green, foreground.blue, foreground.alpha};
    SDL_Color tmpfontbgcolor = { background.red , background.green, background.blue, background.alpha};
    SDL_Surface *resulting_text;

    if (quality == solid) resulting_text = TTF_RenderText_Solid(fonttodraw, text.c_str(), tmpfontcolor);
    else if (quality == shaded) resulting_text = TTF_RenderText_Shaded(fonttodraw, text.c_str(), tmpfontcolor, tmpfontbgcolor);
    else if (quality == blended) resulting_text = TTF_RenderText_Blended(fonttodraw, text.c_str(), tmpfontcolor);

    return new wwsige_surface{"",resulting_text};
}

/**
 * Copy the surface provided onto the screen at coordinates x,y.
 *
 * Drawing flags:
 *
 *      BLIT_DYNAMIC - draw relative to the view, eg. a tile on a large map, when the player moves away
 *          from the tile the view moves and the tile gets pushed off screen.
 *
 *      BLIT_ABSOLUTE - draw at the absolute position on the screen surface. Used for drawing HUD elements
 *          which don't move relative to the player view
 *
 *      BLIT_FREE - Frees (deletes) the surface after it is drawn
 *
 * These flags can be OR'ed together to produce the desired results, eg. Draw the game fps in ABSOULTE mode
 * and then delete it since the surface containing the fps is generated every game cycle
 *
 * @param x X position of the surface
 * @param y Y position of the surface
 * @param source Surface to be drawn
 * @param flags Drawing flags, see function description
**/
void game_engine::blit( float x, float y, wwsige_surface* source, char flags)
{
    if (source==NULL)
    {
        new message_log(MESSAGE_WARNING,"Blit: trying to draw a NULL surface (NULL struct)");
        return ;
    }

    // If you get a segfault here you have a bad pointer to a resource.
    // Make sure the object has not been deleted while the function is
    // being run.

    if (source->data==NULL)
    {
        new message_log(MESSAGE_WARNING,"Blit: trying to draw a NULL surface (NULL data)");
        return ;
    }

    SDL_Rect rect;
    rect.x=0;
    rect.y=0;
    rect.w=0;
    rect.h=0;

    if (flags & BLIT_ABSOLUTE)
    {
        rect.x=round(x);
        rect.y=round(y);
    }

    if (flags & BLIT_DYNAMIC)
    {
        rect.x=round(x)-video.view_x;
        rect.y=round(y)-video.view_y;
    }


    SDL_BlitSurface(source->data, 0 , video.screen, &rect);

    if (flags & BLIT_FREE)
        SDL_FreeSurface(source->data);
}
