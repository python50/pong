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
#include "text_menu.h"
#include "message_log.h"
#include "misc.h"

text_menu::text_menu(game_engine * gm_engine_, std::string id,float xx, float yy, float pitch_, std::string font_, std::string cursor_name_,int cursor_mode, bool drawmode)
{
    gm_engine=gm_engine_;

    new message_log(MESSAGE_DEBUG0,"new text_menu, id:`"+id+
                    "` x:"+convert_int_string(xx)+
                    " y:"+convert_int_string(yy)+
                    " pitch:"+convert_int_string(pitch_)+
                    " font:"+font_+
                    " cursor_id:"+cursor_name+
                    " cursor_mode:"+convert_int_string(cursor_mode));

    id_type=id;
    x=xx;
    y=yy;
    z=-99;

    delete_this=false;
    persistant=false;
    no_collide=true;

    pitch=pitch_;
    cursor_name=cursor_name_;
    cursor=gm_engine->get_surface(cursor_name);

    selected=0;
    loop_cursor=1;

    draw_mode=drawmode;

    font=font_;

    font_color.red  =0xff;
    font_color.green=0xff;
    font_color.blue =0xff;
    font_color.alpha=0xff;

    compute_menu();
}
void text_menu::compute_menu()
{
/*
    std::vector<controller *> new_control;

    for (unsigned int i=0; i < resources::control.size(); i++)
    {
        bool save_object=1;
        unsigned int menu_text_pos=0;

        //if (menu_text_objects.size()==0)
        //    break;

        //if (resources::control.at(i)==NULL)
        //    continue;

        //resources::control.at(i)->update();

        for (unsigned int ii=0;ii < menu_text_objects.size();ii++)
        {

            if (resources::control.at(i)==menu_text_objects.at(ii))
            {
                save_object=0;
                menu_text_pos=ii;
                break;
            }
        }


        if (!save_object)
        {
            std::cout << "Destoryed: " << resources::control.at(i)->id_type << "\n" ;
            delete resources::control.at(i);
        }
        else
            new_control.push_back(resources::control.at(i));
    }

    resources::control.swap(new_control);*/
    for(unsigned int i=0; i < menu_text_objects.size();i++)
        gm_engine->remove_object(menu_text_objects.at(i));


    menu_text_objects.clear();


    int line_number=0;
    int previous_line_number=0;
    for (unsigned int i=0;i < menu_text.size(); i++)
    {

        int pos=menu_text.at(i).find("#",pos);
        while(pos!=-1)
        {
            pos=menu_text.at(i).find("#",pos);
            line_number++;
        }

        new message_log(MESSAGE_DEBUG0, "text_menu: "+convert_int_string(line_number));

        controller * object = new text(gm_engine, id_type+"_text-"+convert_int_string(i),x+cursor->data->w,y+(previous_line_number*pitch), font, menu_text.at(i), draw_mode );
        int value=0;
        object->set("font_red",value=font_color.red);
        object->set("font_green",value=font_color.green);
        object->set("font_blue",value=font_color.blue);
        object->set("font_alpha",value=font_color.alpha);
        menu_text_objects.push_back(object);
        gm_engine->add_object(object);

        line_number++;
        previous_line_number=line_number;
    }

}


void text_menu::call(std::string item, bool &value)
{

}

void text_menu::call(std::string item, int &value)
{
    if (item=="select")
    {
        if (value < 0)
        {
            if (value == -1 or value == -2)
            {
                if (value==-1)
                {
                    if (selected > 0)
                        selected--;
                    else
                    {
                        if (!loop_cursor)
                            new message_log(MESSAGE_DEBUG4,"Text Menu: Call to 'select', menu boundry reached. Cannot deincrement selection");
                        else
                            selected=menu_text.size()-1;
                    }
                }

                if (value==-2)
                {
                    if (selected < (int) menu_text.size()-1)
                        selected++;
                    else
                    {
                        if (!loop_cursor)
                            new message_log(MESSAGE_DEBUG4,"Text Menu: Call to 'select', menu boundry reached. Cannot increment selection");
                        else
                            selected=0;
                    }
                }
            }
            else
                new message_log(MESSAGE_DEBUG4,"Text Menu: Call to 'select', value out of range (too low)");
        }
        else
        {
            if (value < (int)  menu_text.size())
                selected=value;
            else
                new message_log(MESSAGE_DEBUG4,"Text Menu: Call to 'select', value out of range (too high)");
        }
    }
}

void text_menu::call(std::string item, float &value)
{

}

void text_menu::call(std::string item, std::string &value)
{
    if (item=="push_back")
    {
        menu_text.push_back(value);
        compute_menu();
    }

    if (item=="clear")
    {
        menu_text.clear();
        compute_menu();
    }
}

void text_menu::get(std::string item, bool &return_value)
{
    if (item=="draw_mode")
        return_value=draw_mode;

    if (item=="delete_this")
        return_value=delete_this;

    if (item=="persistant")
        return_value=persistant;

    if (item=="no_collide")
        return_value=no_collide;
}

void text_menu::get(std::string item, int &return_value)
{
    if (item=="selected")
        return_value=selected;

    if (item=="font_red")
        return_value=font_color.red;
    if (item=="font_green")
        return_value=font_color.green;
    if (item=="font_blue")
        return_value=font_color.blue;
    if (item=="font_alpha")
        return_value=font_color.alpha;
}

void text_menu::get(std::string item, float &return_value)
{
    if (item=="x")
        return_value=x;
    if (item=="y")
        return_value=y;
    if (item=="z")
        return_value=z;

}

void text_menu::get(std::string item, std::string &return_value)
{
    if (item=="font")
        return_value=font;
}

void text_menu::set(std::string item, bool &value)
{
    if (item=="draw_mode")
        draw_mode=value;

    if (item=="delete_this")
        delete_this=value;

    if (item=="persistant")
        persistant=value;

    if (item=="no_collide")
        no_collide=value;
}

void text_menu::set(std::string item, int &value)
{
    if (item=="font_red")
        font_color.red=value;
    if (item=="font_green")
        font_color.green=value;
    if (item=="font_blue")
        font_color.blue=value;
    if (item=="font_alpha")
        font_color.alpha=value;
}

void text_menu::set(std::string item, float &value)
{
    if (item=="x")
        x=value;
    if (item=="y")
        y=value;
    if (item=="z")
        z=value;
}

void text_menu::set(std::string item, std::string &value)
{
    if ( item=="font" )
        font=value;
}

void text_menu::update()
{
    if (!draw_mode)
        gm_engine->blit(x,y+(selected*pitch),cursor,BLIT_DYNAMIC);
    else
        gm_engine->blit(x,y+(selected*pitch),cursor,BLIT_ABSOLUTE);
}

text_menu::~text_menu()
{
    new message_log(MESSAGE_DEBUG0,"text_menu destroyed, id:`"+id_type+"`");
    /*for (unsigned int i=0; i < menu_text_objects.size();i++)
    {
        gm_engine->remove_object(menu_text_objects.at(i));
    }*/
}
