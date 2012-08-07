/**
 * @file
 * @author  Jason White <jason@jswhite.net> <whitewaterssoftwareinfo@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 *
 * PONG - The open source pong clone Copyright (C) 2012 Jason White, White Waters Software
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

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_rotozoom.h"

#include "map_parser.h"

/**
 * Load font into game engine with with provided string identifier
 * @param file path to file to be loaded (including data directory)
 * @param id string identifier to be assigned to the resource
 * @param ptsize (int) desired hieght of font in pixels
 * @return 0 on failure, 1 on success
 */
int game_engine::load_font(std::string file, const char * id, int ptsize)
{
    TTF_Font *font_file;
    font_file=TTF_OpenFont(file.c_str(), ptsize);

    if (!font_file)
    {
        new message_log(MESSAGE_WARNING,"Load Font: Could Not Load `"+file+"`");

        return NULL;
    }

    font_data.push_back(new wwsige_font{id,font_file, ptsize});
    //font_id.push_back(id);

    return 1;
}

/**
 * Load music stream into game engine with with provided string identifier
 * @param file path to file to be loaded (including data directory)
 * @param id string identifier to be assigned to the resource
 * @return 0 on failure, 1 on success
 */
int game_engine::load_music(std::string file, const char * id)
{
    Mix_Music *musics;
    musics=Mix_LoadMUS(file.c_str());
    if (!musics)
    {
        new message_log(MESSAGE_WARNING,"Load Music: Could Not Load `"+file+"`");

        return 0;
    }

    music_data.push_back(new wwsige_music{id, musics} );
    //music_id.push_back(id);

    return 1;
}

/**
 * Load surface into game engine with with provided string identifier
 * @param file path to file to be loaded (including data directory)
 * @param id string identifier to be assigned to the resource
 * @return 0 on failure, 1 on success
 */
int game_engine::load_surface(std::string file, const char * id)
{
    const char * function_name="game_engine::load_surface:";

    SDL_Surface * data=IMG_Load(file.c_str());

    if (data==0)
    {
        new message_log(MESSAGE_WARNING,*function_name+"Could Not Load `"+file+"`, `"+IMG_GetError()+"`");

        return 0;//throw IMG_GetError();
    }

    //Scale is not set !
    //data=zoomSurface(data, (double) map.scale, (double) map.scale, 0);

    surface_data.push_back(new wwsige_surface{id,data});

    return 1;
}

/**
 * Load sound chunk into game engine with with provided string identifier
 * @param file path to file to be loaded (including data directory)
 * @param id string identifier to be assigned to the resource
 * @return 0 on failure, 1 on success
 */
int game_engine::load_sound(std::string file, const char * id)
{
    Mix_Chunk * sounds;
    sounds=Mix_LoadWAV(file.c_str());
    if (!sounds)
    {
        new message_log(MESSAGE_WARNING,"Load Sound: Could Not Load `"+file+"`, `"+Mix_GetError()+"`");

        return 0;//throw Mix_GetError();
    }


    sound_data.push_back(new wwsige_sound{id,sounds});
    //sound_id.push_back(id);

    return 1;
}

/** Get Functions **/


/**
 * Get the surface with the assigned string identifier
 * @param id the string identifier of the desired resource
 * @return NULL on failure, the resource on success
*/
wwsige_surface * game_engine::get_surface(std::string id)
{
    for (unsigned int i=0; i <= surface_data.size()-1 ; i++)
    {

        if ( surface_data.at(i)->id==id)
        {
            if ((surface_data.size()-1) >= i)
                return surface_data.at(i);
        }

    }

    new message_log(MESSAGE_WARNING, "Surface `"+id+"` not found");

    return NULL;
}

/**
 * Get the music stream with the assigned string identifier
 * @param id the string identifier of the desired resource
 * @return NULL on failure, the resource on success
*/
wwsige_music * game_engine::get_music(std::string id)
{
    for(unsigned int i=0; i <= music_data.size()-1 ; i+=1)
    {
        if (music_data.at(i)->id==id)
        {
            if ((music_data.size()-1) >= i)
                return music_data.at(i);
        }
    }

    new message_log(MESSAGE_WARNING, "Music `"+id+"` not found");

    return NULL;
}

/**
 * Get the sound chunnk with the assigned string identifier
 * @param id the string identifier of the desired resource
 * @return NULL on failure, the resource on success
*/
wwsige_sound * game_engine::get_sound(std::string id)
{
    for(unsigned int i=0; i <= sound_data.size()-1 ; i+=1)
    {
        if (sound_data.at(i)->id==id)
        {
            if ((sound_data.size()-1) >= i)
                return sound_data.at(i);
        }
    }

    new message_log(MESSAGE_WARNING, "Sound `"+id+"` not found");

    return NULL;
}

/**
 * Get the font with the assigned string identifier
 * @param id the string identifier of the desired resource
 * @return NULL on failure, the resource on success
*/
wwsige_font * game_engine::get_font(std::string id)
{
    for(unsigned int i=0; i <= font_data.size()-1 ; i+=1)
    {
        if (font_data.size()==0)
            break;

        if (font_data.at(i)->id==id)
        {
            if ((font_data.size()-1) >= i)
                return font_data.at(i);
        }
    }

    new message_log(MESSAGE_WARNING, "Font `"+id+"` not found");

    return NULL;
}

//----------------------------

/**
 * Add object to the game loop
 * Example: controller * text=add_object(new text(1,2,"hi"))
 * @param cont A pointer to the object
 * @return The object added to the game loop
 */
controller * game_engine::add_object(controller * cont)
{
    control_data.push_back(cont);
    return cont;
}

/**
 * Get object (from the game loop)
 * @param id The string identifier to search for
 * @return NULL on failure, an oibject with the string identifier on success
 */
controller * game_engine::get_object(std::string id)
{
    for(unsigned int i=0; i < control_data.size(); i+=1)
    {
        if (control_data.size()==0)
            break;

        if (control_data.at(i)==NULL)
            continue;

        if (control_data.at(i)->id_type==id)
        {
            return control_data.at(i);
        }

    }

    new message_log(MESSAGE_WARNING, "Object `"+id+"` not found");

    return NULL;
}

/**
 * Clear all objects from game loop
 */
void game_engine::clear_objects()
{
    control_data.clear();
}

/**
 * Remove an object from the game loop
 * @param id The string identifier of the object to be removed
 * @return 0 on failure (can't find object), 1 on success
 */
bool game_engine::remove_object(std::string id)
{
    for(unsigned int i=0; i < control_data.size(); i+=1)
    {
        if (control_data.size()==0)
            break;

        if (control_data.at(i)==NULL)
            continue;

        if (control_data.at(i)->id_type==id)
        {
            delete control_data.at(i);
            control_data.at(i)=NULL;
            return 1;
        }
    }

    return 0;
}

/**
 * Remove an object from the game loop
 * @param cont A pointer to the object to be removed
 * @return 0 on failure (can't find object), 1 on success
 */
bool game_engine::remove_object(controller * cont)
{
    for(unsigned int i=0; i < control_data.size(); i+=1)
    {
        if (control_data.size()==0)
            break;

        if (control_data.at(i)==NULL)
            continue;

        if (control_data.at(i)==cont)
        {
            delete control_data.at(i);
            control_data.at(i)=NULL;
            return 1;
        }
    }

    return 0;
}


//----------

/**
 * Clear objects from the game loop and load map,
 * @param mapname The string identifier of the object to be removed
 * @return always returns 1
 */
bool game_engine::load_map(std::string mapname)
{
    new map_parser(this, mapname);
    return 1;
}
