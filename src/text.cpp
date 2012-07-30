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
#include "text.h"
#include "message_log.h"
#include "misc.h"

text::text(game_engine * gm_engine_, std::string id, float xx, float yy, std::string font_, std::string ntext, bool drawmode)
{

    new message_log(MESSAGE_DEBUG3,"text created, id:`"+id+
                    "` x:"+convert_int_string(xx)+
                    " y:"+convert_int_string(yy)+
                    " font:`"+font_+"` text:`"+ntext+"`");

    id_type=id;
    font=font_;
    raw_text=ntext;
    render_text=process_text(ntext);

    gm_engine=gm_engine_;

    justify_horizontal=TEXT_JUSTIFY_LEFT;
    justify_vertical=TEXT_JUSTIFY_TOP;

    x=xx;
    y=yy;
    z=-100;

    delete_this=false;
    persistant=false;
    no_collide=true;

    font_color.red  =0xFF;
    font_color.green=0xFF;
    font_color.blue =0xFF;
    font_color.alpha=0xFF;

    font_bgcolor.red  =0xFF;
    font_bgcolor.green=0xFF;
    font_bgcolor.blue =0xFF;
    font_bgcolor.alpha=0xFF;

    enable=1;
    change=1;
    shadow=0;
    draw=drawmode;

    lines=0;
    size=0;
    ptsize=gm_engine->get_font(font)->ptsize;

    //sprite_forground=NULL;
    //sprite_background=NULL;
}


void text::get(std::string item, bool &return_value)
{
    if (item=="enable")
        return_value=enable;

    if (item=="shadow")
        return_value=shadow;

    if (item=="draw")
        return_value=draw;
}

void text::get(std::string item, int &return_value)
{
    if (item=="justify_horizontal")
        return_value=justify_horizontal;
    if (item=="justify_vertical")
        return_value=justify_vertical;

    if (item=="font_red")
        return_value=font_color.red;
    if (item=="font_green")
        return_value=font_color.green;
    if (item=="font_blue")
        return_value=font_color.blue;
    if (item=="font_alpha")
        return_value=font_color.alpha;

    if (item=="font_bgcolor")
        return_value=font_bgcolor.red;
    if (item=="font_bgcolor")
        return_value=font_bgcolor.green;
    if (item=="font_bgcolor")
        return_value=font_bgcolor.blue;

    if (item=="lines")
    ;
    if (item=="size")
    ;
}

void text::get(std::string item, float &return_value)
{
    if (item=="x")
        return_value=x;
    if (item=="y")
        return_value=y;
    if (item=="z")
        return_value=z;
}

void text::get(std::string item, std::string &return_value)
{
    if (item=="text")
        return_value=raw_text;

    if (item=="font")
        return_value=font;
}

void text::set(std::string item, bool &value)
{
    if (item=="enable")
        enable=value;

    if (item=="shadow")
        shadow=value;

    if (item=="draw")
        draw=value;
}

void text::set(std::string item, int &value)
{
    if (item=="justify_horizontal")
        justify_horizontal= (text_justify) value;
    if (item=="justify_vertical")
        justify_vertical= (text_justify) value;

    if (item=="font_red")
        font_color.red=value;
    if (item=="font_green")
        font_color.green=value;
    if (item=="font_blue")
        font_color.blue=value;
    if (item=="font_alpha")
        font_color.alpha=value;

    if (item=="font_bgcolor_red")
        font_bgcolor.red=value;
    if (item=="font_bgcolor_green")
        font_bgcolor.green=value;
    if (item=="font_bgcolor_blue")
        font_bgcolor.blue=value;
}

void text::set(std::string item, float &value)
{
    if (item=="x")
        x=value;
    if (item=="y")
        y=value;
    if (item=="z")
        z=value;
}

void text::set(std::string item, std::string &value)
{
    if (item=="text")
    {
        if (value!=raw_text)
        {
            change=1;
            raw_text=value;
            render_text=process_text(raw_text);
        }
    }

    if (item=="font")
            font=value;
}

void text::render()
{
    for(unsigned int i=0;i < sprite_forground.size();i++)
    {
        SDL_FreeSurface(sprite_forground.at(i)->data);
    }
    sprite_forground.clear();

    change=0;
    for(unsigned int i=0;i<render_text.size();i++)
    {
        sprite_forground.push_back(gm_engine->render_text(font, render_text.at(i), font_color, font_bgcolor, blended));
    }
}

std::vector<std::string> text::process_text(std::string text_)
{
    std::vector<std::string> new_text;

    int position=0;
    unsigned int nlines=0;

    position=text_.find("##");

    while(position!=-1)
    {
        nlines++;
        new_text.push_back(text_.substr(0,position));
        text_=text_.substr(position+2,text_.size()-(position+1));
        position=text_.find("##");
    }

    //no newlines
    if (position==-1)
    {
        nlines++;
        new_text.push_back(text_);
    }

    return new_text;
}

void text::update()
{
    if (change)
        render();
/*
    if (sprite_background!=NULL && !shadow)
    {
        float x_tmp=y;
        float y_tmp=x;

        if (justify_horizontal==TEXT_JUSTIFY_LEFT)
            x_tmp=x;
        if (justify_horizontal==TEXT_JUSTIFY_RIGHT)
            x_tmp=x-(sprite_forground->w);
        if (justify_horizontal==TEXT_JUSTIFY_CENTER)
            x_tmp=x-(sprite_forground->w/2);

        if (justify_vertical==TEXT_JUSTIFY_TOP)
            y_tmp=y;
        if (justify_vertical==TEXT_JUSTIFY_BOTTOM)
            y_tmp=y-(sprite_forground->h);
        if (justify_vertical==TEXT_JUSTIFY_MIDDLE)
            y_tmp=y-(sprite_forground->h/2);

        char mode=0;
        if (!draw)
            mode=BLIT_DYNAMIC;
        else
            mode=BLIT_ABSOLUTE;

        for (int i=0;i < sprite_foreground.size();i++)
        {
            gm_engine->blit(x_tmp+1,y_tmp+1,sprite_foreground.at(i),mode);
        }
    }*/

    if (sprite_forground.size()!=0 and enable)
    {
        float x_tmp=x;
        float y_tmp=y;

        char mode=0;
        if (!draw)
            mode=BLIT_DYNAMIC;
        else
            mode=BLIT_ABSOLUTE;

        for (unsigned int i=0; i < sprite_forground.size();i++)
        {
            if (sprite_forground.at(i)==0)
                continue;
            if (sprite_forground.at(i)->data==0)
                continue;

            if (justify_horizontal==TEXT_JUSTIFY_LEFT)
                x_tmp=x;
            if (justify_horizontal==TEXT_JUSTIFY_RIGHT)
                x_tmp=x-(sprite_forground.at(i)->data->w);
            if (justify_horizontal==TEXT_JUSTIFY_CENTER)
                x_tmp=x-(sprite_forground.at(i)->data->w/2);

            if (justify_vertical==TEXT_JUSTIFY_TOP)
                y_tmp=y;
            if (justify_vertical==TEXT_JUSTIFY_BOTTOM)
                y_tmp=y-(sprite_forground.at(i)->data->h);
            if (justify_vertical==TEXT_JUSTIFY_MIDDLE)
                y_tmp=y-(sprite_forground.at(i)->data->h/2);

            gm_engine->blit(x_tmp,y_tmp+(i*ptsize),sprite_forground.at(i),mode);
        }
    }
}

text::~text()
{/*
    for(int i=0;i < sprite_forground.size();i++)
    {
        SDL_FreeSurface(sprite_forground.at(i)->data);
    }
    sprite_forground.clear();
*/
    new message_log(MESSAGE_DEBUG4,"Text Object Destroyed, id:`"+id_type+"`");
}
