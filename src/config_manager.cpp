#include "config_manager.h"
#include "stdio.h"

config_manager::config_manager(string filename_)
{
    filename=filename_;

    char *error_message = 0;
    int rc;

    rc = sqlite3_open(filename.c_str(), &db);
    if( rc )
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return ;
    }

    rc = sqlite3_exec(db, "SELECT * FROM Settings", settings_callback_c, this, &error_message);
    if( rc!=SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", error_message);
        sqlite3_free(error_message);
    }

    return ;
}

int config_manager::get_setting_int(string name)
{

    return 0;
}

string config_manager::get_setting_string(string name)
{
    if (name=="foo")
        return foo;

    return 0;
}

void config_manager::set_setting_int(string name, int value)
{

}

void config_manager::set_setting_string(string name, string value)
{

}

void config_manager::settings_callback_cpp(string name, char * value)
{
    if (name=="foo")
    {
        foo=value;
        printf("Got foo: %s",value);
    }
}

int config_manager::settings_callback_c(void* data,int argc,char** argv,char** ColName)
{
    // We are simply passing the data back to the class
    // (this is a static function, as required by sqlite)
    ((config_manager*) data)->settings_callback_cpp(argv[0],argv[1]);

    return 0;
}

config_manager::~config_manager()
{
    sqlite3_close(db);
}
