#ifndef MESSAGE_LOG_H
#define MESSAGE_LOG_H

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
#include <stdlib.h>
#include <iostream>

enum message_level
{
    MESSAGE_FATAL_ERROR,
    MESSAGE_WARNING,
    MESSAGE_EVENT,
    MESSAGE_DEBUG0,
    MESSAGE_DEBUG1,
    MESSAGE_DEBUG2,
    MESSAGE_DEBUG3,
    MESSAGE_DEBUG4,
    MESSAGE_DEBUG5,
    MESSAGE_DEBUG6,
    MESSAGE_DEBUG7,
};


/**
 * Message/Error Reporting class for loging and handling
 * various messages/errors
 *
 * Error Levels:
 *
 *  Fatal Error - Fatal Errors
 *
 *  Warning - Recoverable Errors
 *
 *  Event - Events eg. file opened
 *
 *  Debug[0-7]:
 *
 *      Debug0 - File operations
 *
 *      Debug1 - Resource Operations
 *
 *      Debug2 - Sound Operations
 *
 *      Debug3 - Object Creation/Destruction With Params
 *
 *      Debug4 - Object Events
 *
 *      Debug5 - Map Info/Statistics
 *
 *      Debug6 - Crash Info, User Config, etc
 *
 *      Debug7 - Other
 *
 */
class message_log
{
    public:
		message_log(const char * type, const char * format, ...);
        message_log(message_level level , std::string message);
        virtual ~message_log();
    protected:
    private:
        void log(std::string message);
};

#endif // MESSAGE_LOG_H
