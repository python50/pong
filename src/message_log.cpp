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
#include "message_log.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//using namespace std;

message_log::message_log(message_level level,std::string message)
{

    if (level==MESSAGE_FATAL_ERROR)
    {
        message="FATAL ERROR: "+message;
        log(message);
    }

    if (level==MESSAGE_WARNING)
    {
        message="WARNING: "+message;
        log(message);
    }

    if (level==MESSAGE_EVENT)
    {
        message="Event: "+message;
        log(message);
    }

    if (level==MESSAGE_DEBUG0)
    {
        message="Debug0: "+message;
        log(message);
    }

    if (level==MESSAGE_DEBUG1)
    {
        message="Debug1: "+message;
        log(message);
    }

    if (level==MESSAGE_DEBUG2)
    {
        message="Debug2: "+message;
        log(message);
    }

    if (level==MESSAGE_DEBUG3)
    {
        message="Debug3: "+message;
        log(message);
    }

    if (level==MESSAGE_DEBUG4)
    {
        message="Debug4: "+message;
        log(message);
    }

    if (level==MESSAGE_DEBUG5)
    {
        message="Debug5: "+message;
        log(message);
    }

    if (level==MESSAGE_DEBUG6)
    {
        message="Debug6: "+message;
        log(message);
    }

    if (level==MESSAGE_DEBUG7)
    {
        message="Debug7: "+message;
        log(message);
    }
}


/*
*/
void message_log::log(std::string message)
{
    // Format Time String

    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    strftime (buffer,80,"%H:%M:%S",timeinfo);

    std::string time=buffer;

    // [12:30:02] FATAL_ERROR: Resource Not Found
    message="["+time+"] "+message+"\n";

    // Write to log

    FILE *log;
    log=fopen("error.log", "a");
    fprintf(log,message.c_str());// "Hello\ns", message.c_str());
    printf("%s",message.c_str());
    fclose(log);
}

message_log::~message_log()
{
    //dtor
}
