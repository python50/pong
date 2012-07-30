#ifndef MESSAGE_LOG_H
#define MESSAGE_LOG_H


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
        message_log(message_level level , std::string message);
        virtual ~message_log();
    protected:
    private:
        void log(std::string message);
};

#endif // MESSAGE_LOG_H
