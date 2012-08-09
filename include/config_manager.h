#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include <iostream>
// project includes
extern "C" {
#include "sqlite3.h"
}

using namespace std;

/*
settings.sqlite
CREATE  TABLE "main"."Settings" ("Name" VARCHAR PRIMARY KEY UNIQUE , "Value" VARCHAR)
*/

class config_manager
{
    public:
        /** Default constructor */
        config_manager(string filename_);
        /** Default destructor */
        virtual ~config_manager();

        int     get_setting_int(string name);
        string  get_setting_string(string name);

        void    set_setting_int(string name, int value);
        void    set_setting_string(string name, string value);

        static int settings_callback_c(void* data,int argc,char** argv,char** ColName);
    protected:
    private:
        void settings_callback_cpp(string name, char * value);

        sqlite3 *db;
        string filename; //!< Member variable "filename"
        string foo;
};

#endif // CONFIG_MANAGER_H
