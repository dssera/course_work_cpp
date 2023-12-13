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

	string get_filename()
	{
		return this->filename;
	}
	void set_filename(string filename)
	{
		this->filename = filename;
	}

	string read_file()
	{
		ifstream file(this->filename);
		if (!file.is_open()) {
			cout << "Error opening file: " << this->filename << endl;
			return NO_DATA_STR;
		}

		string file_contents;
		string line;
		while (getline(file, line)) {
			file_contents += line + "\n";
		}

		file.close();

		return file_contents;
	}

	string* tokenize_string(string line, char token)
	{
		// read about stringstream
		int size = 5;
		string* tokens = new string[size];

		stringstream ss(line);
		string item;

		ss.clear();
		ss.seekg(0, ios::beg);

		for (size_t i = 0; i < size; i++)
		{
			getline(ss, item, token);
			tokens[i] = item;
		}
		return tokens;
	}
};

class UserDataBase : public BaseDataBase
{
private:
	const int username_index = 0;
	const int password_index = 1;
	const int access_level_index = 2;

public:
	UserDataBase(string filename) : BaseDataBase(filename) {}

	string** get_usernames()
	{
		ifstream file(this->get_filename());
		if (!file.is_open()) {
			cout << "Error opening file: " << this->get_filename() << endl;
			throw exception();
		}

		string** usernames = nullptr;
		int length = 0;

		string line;
		while (getline(file, line))
		{
			string* tokens = tokenize_string(line, ';');
			string username = tokens[username_index];

			string** temp = new string * [length + 2]; // Увеличиваем размер на 2 для добавления nullptr
			for (int i = 0; i < length; i++)
			{
				temp[i] = usernames[i];
			}
			temp[length] = new string(username);
			temp[length + 1] = nullptr; // Добавляем nullptr в конец массива

			delete[] usernames;
			usernames = temp;
			// cout << *usernames[length]<< usernames[length] << endl;
			length++;
		}

		file.close();

		return usernames;
	}

	string get_password(string username)
	{
		ifstream file(this->get_filename());
		if (!file.is_open()) {
			cout << "Error opening file: " << this->get_filename() << endl;
			throw exception();
		}
		string password = NO_MATCH;
		// list<string> file_lines;

		string line;
		while (getline(file, line))
		{
			string* tokens = tokenize_string(line, ';');
			if (username == tokens[username_index])
			{
				return tokens[password_index];
			}
		}

		file.close();

		return password;
	}
	bool add_user(string username, string password)
	{
		// u can make "bool add_line() func which add any data
		// and placed in base class. 
		// CRUD operations can be placed in BaseDataBase

		// this function can be modified to add_admin
		// + one optional parameter bool is_admin

		ofstream file;
		file.open(this->get_filename(), ios::app);
		if (!file.is_open()) {
			cout << "Error opening file: " << this->get_filename() << endl;
			return false;
		}
		file << '\n' << username << ';' << password << ';' << "0";
		file.close();

		return true;
	}

	int get_access_level(string username)
	{
		ifstream file(this->get_filename());
		if (!file.is_open()) {
			cout << "Error opening file: " << this->get_filename() << endl;
			throw exception();
		}

		int access_level = 0;
		string line;

		while (getline(file, line))
		{
			string* tokens = tokenize_string(line, ';');
			if (username == tokens[username_index])
			{
				return stoi(tokens[access_level_index]);
			}
		}
		file.close();
		return access_level;
	}
	int get_user_count()
	{
		ifstream file(this->get_filename());
		if (!file.is_open()) {
			cout << "Error opening file: " << this->get_filename() << endl;
			throw exception();
		}
		string line;
		int count = 0;
		while (getline(file, line))
		{
			count++;
		}
		return count;
	}
	User* get_users()
	{
		ifstream file(this->get_filename());
		if (!file.is_open()) {
			cout << "Error opening file: " << this->get_filename() << endl;
			throw exception();
		}
		User* users = new User[get_user_count()];

		string line;
		int i = 0;
		while (getline(file, line))
		{
			string* tokens = tokenize_string(line, ';');
			users[i].set_username(tokens[username_index]);
			users[i].set_password(tokens[password_index]);
			users[i].set_access_level(stoi(tokens[access_level_index]));
			cout << "username: "<< users[i].get_username() << endl;
			i++;
		}
		file.close();
		return users;
	}
};

class EventDataBase : public BaseDataBase
{
	// this class will work with collection
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

	int get_event_count()
	{
		ifstream file(this->get_filename());
		if (!file.is_open()) {
			cout << "Error opening file: " << this->get_filename() << endl;
			throw exception();
		}
		int count = 0;
		string line;
		while (getline(file, line))
		{
			count++;
		}
		return count;
	}
	Event* get_tasks()
	{
		ifstream file(this->get_filename());
		if (!file.is_open()) {
			cout << "Error opening file: " << this->get_filename() << endl;
			throw exception();
		}
		Event* events = new Event[get_event_count()];
		// list<string> file_lines;

		string line;
		int i = 0;
		while (getline(file, line))
		{
			string* tokens = tokenize_string(line, ';');
			events[i].set_day(tokens[day_index]);
			events[i].set_time(tokens[time_index]);
			events[i].set_event_name(tokens[event_name_index]);
			events[i].set_name(tokens[name_index]);
			events[i].set_number(tokens[number_index]);
			i++;

		}
		file.close();
		return events;
	}


};