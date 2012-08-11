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
 
Creation SQL:
	CREATE TABLE IF NOT EXISTS Settings
	(
		"Name" VARCHAR PRIMARY KEY UNIQUE,
		"Value" VARCHAR
	)

Set SQL: 
	--not valid in sqlite
	IF EXISTS (SELECT * FROM Settings WHERE Name='varname')
		UPDATE Settings SET (Value='1') WHERE Name='varname'
	ELSE
		INSERT INTO Settings ('Name', 'Value') VALUES ('varname','1');
	--valid in sqlite
	CASE (SELECT var FROM table)
		WHEN NULL THEN INSERT INTO Settings ('Name', 'Value') VALUES ('varname','1')
		ELSE UPDATE Settings SET (Value='1') WHERE Name='varname'
	END

 	CASE (SELECT var FROM table) WHEN NULL THEN INSERT INTO Settings ('Name', 'Value') VALUES ('varname','1') ELSE UPDATE Settings SET (Value='1') WHERE Name='varname' END
 
Get SQL:
	Select * FROM Settings WHERE Name='varname'
 
 */

class config_manager
{
    public:
        /** Default constructor */
        config_manager(string filename_);
        /** Default destructor */
        virtual ~config_manager();

        int     get_setting_int(string name, string table);
        string  get_setting_string(string name, string table);

        void    set_setting_int(string name, string table, int value);
        void    set_setting_string(string name, string table, string value);

        static int settings_callback_c(void* data,int argc,char** argv,char** ColName);
		static int default_callback_c(void* data,int argc,char** argv,char** ColName);
    protected:
    private:
        void settings_callback_cpp(char * value);
		void default_callback_cpp(int value);
		string int_to_string(int value);

        sqlite3 *db;
        string filename; //!< Member variable "filename"
		bool error;
		
		string temp_str_setting;
		int temp_int_setting;
		int rows;
};

#endif // CONFIG_MANAGER_H
