#include "config_manager.h"
#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <sstream>

config_manager::config_manager(string filename_)
{
    filename=filename_;

	rows=0;
	
	error=false;
    char *error_message = 0;
    int rc;

    rc = sqlite3_open(filename.c_str(), &db);
    if( rc )
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
		error=true;
        return ;
    }
	
	rc = sqlite3_exec(db,"\
	CREATE TABLE IF NOT EXISTS Settings\
	(\
		'Name' VARCHAR PRIMARY KEY UNIQUE,\
		'Value' VARCHAR\
	)", NULL, NULL, &error_message);
	
    if( rc!=SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", error_message);
        sqlite3_free(error_message);
		error=true;
    }
}

int config_manager::get_setting_int(string name, string table)
{
	if (error)
		return 0;
	
    char *error_message = 0;
    int rc;
	
	string sql="SELECT Name, Value FROM "+table+" WHERE Name='"+name+"'";
	
    rc = sqlite3_exec(db, sql.c_str() , settings_callback_c, this, &error_message);
    if( rc!=SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", error_message);
        sqlite3_free(error_message);
		return 0;
    }
	
    return temp_int_setting;
}

string config_manager::get_setting_string(string name, string table)
{
	if (error)
		return "";
	
    char *error_message = 0;
    int rc;
	
	string sql="SELECT Name, Value FROM "+table+" WHERE Name='"+name+"';";
	
    rc = sqlite3_exec(db, sql.c_str() , settings_callback_c, this, &error_message);
    if( rc!=SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", error_message);
        sqlite3_free(error_message);
    }
	
    return temp_str_setting;
}

void config_manager::set_setting_int(string name, string table, int value)
{
    char *error_message = 0;
    int rc;
	
	string val=int_to_string(value);
	string sql="SELECT * FROM "+table+" WHERE Name='"+name+"';";
	//Default callback increments rows for each result returned
	rows=0;
    rc = sqlite3_exec(db, sql.c_str() , default_callback_c, this, &error_message);
    if( rc!=SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", error_message);
        sqlite3_free(error_message);
    }
	
	if (rows)
	{
		sql="UPDATE "+table+" SET Value='"+val+"' WHERE Name='"+name+"';";
		rc = sqlite3_exec(db, sql.c_str() , NULL, NULL, &error_message);
		if( rc!=SQLITE_OK )
		{
			fprintf(stderr, "SQL error: %s\n", error_message);
			sqlite3_free(error_message);
		}
	}
	else
	{
		sql="INSERT INTO "+table+" (Name, Value) VALUES ('"+name+"','"+val+"');";
		rc = sqlite3_exec(db, sql.c_str() , NULL, NULL, &error_message);
		if( rc!=SQLITE_OK )
		{
			fprintf(stderr, "SQL error: %s\n", error_message);
			sqlite3_free(error_message);
		}
	}
}

void config_manager::set_setting_string(string name, string table, string value)
{
    char *error_message = 0;
    int rc;
	
	string sql="SELECT * FROM "+table+" WHERE Name='"+name+"';";
	//Default callback increments rows for each result returned
	rows=0;
    rc = sqlite3_exec(db, sql.c_str() , default_callback_c, this, &error_message);
    if( rc!=SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", error_message);
        sqlite3_free(error_message);
    }
	
	printf("%d rows returned\n", rows);
	
	if (rows)
	{
		sql="UPDATE "+table+" SET Value='"+value+"' WHERE Name='"+name+"';";
		rc = sqlite3_exec(db, sql.c_str() , NULL, NULL, &error_message);
		if( rc!=SQLITE_OK )
		{
			fprintf(stderr, "SQL error: %s\n", error_message);
			sqlite3_free(error_message);
		}
	}
	else
	{
		sql="INSERT INTO "+table+" (Name, Value) VALUES ('"+name+"','"+value+"');";
		cout << sql << "\n";
		rc = sqlite3_exec(db, sql.c_str() , NULL, NULL, &error_message);
		if( rc!=SQLITE_OK )
		{
			fprintf(stderr, "SQL error: %s\n", error_message);
			sqlite3_free(error_message);
		}
	}
}

void config_manager::settings_callback_cpp(char * value)
{
	
	if (value!=0)
	{
		temp_str_setting=value;
		
		string str=value;
		istringstream buf(str);
		buf >> temp_int_setting;
		
		//temp_int_setting=atoi(value);

	}
	else
	{
		temp_str_setting="";
		temp_int_setting=0;
	}
}

void config_manager::default_callback_cpp(int value)
{
	//If more than one col was returned then it returned a result
	if (value)
		rows++;
}

int config_manager::settings_callback_c(void* data,int argc,char** argv,char** ColName)
{
    // We are simply passing the data back to the class
    // (this is a static function, as required by sqlite)
    ((config_manager*) data)->settings_callback_cpp(argv[1]);
	
    return 0;
}

int config_manager::default_callback_c(void* data,int argc,char** argv,char** ColName)
{
    // We are simply passing the number of cols returned back to the class
    // (this is a static function, as required by sqlite)
    ((config_manager*) data)->default_callback_cpp(argc);

    return 0;
}

string config_manager::int_to_string(int number)
{
   std::stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

config_manager::~config_manager()
{
    sqlite3_close(db);
}
