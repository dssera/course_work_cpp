#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Constants.h"
#include "User.h"
#include "Event.h"

using namespace std;

class BaseDataBase
{
private:
	string filename;
public:
	BaseDataBase(string filename)
	{
		this->filename = filename;
	}

	string get_filename();
	void set_filename(string filename);
	string read_file();
	string* tokenize_string(string line, char token);
};

class UserDataBase : public BaseDataBase
{
private:
	const int username_index = 0;
	const int password_index = 1;
	const int access_level_index = 2;

public:
	UserDataBase(string filename) : BaseDataBase(filename) {}

	string** get_usernames();
	string get_password(string username);
	bool add_user(string username, string password);
	int get_access_level(string username);
	int get_user_count();
	User* get_users();
};

class EventDataBase : public BaseDataBase
{
	const int day_index = 0;
	const int time_index = 1;
	const int event_name_index = 2;
	const int name_index = 3;
	const int number_index = 4;

public:
	EventDataBase(string filename, string username) : BaseDataBase(filename)
	{
		this->set_filename(username + '_' + filename);

		ifstream i_file(this->get_filename());
		if (!i_file.is_open())
		{
			ofstream file(this->get_filename());
			file.close();
		}
		i_file.close();
	}
	int get_event_count();
	Event* get_tasks();
};