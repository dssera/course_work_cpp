#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

#include "Constants.h"
#include "User.h"
#include "Task.h"

using namespace std;

class BaseDataBase
{
protected:
public:
	string filename;


	BaseDataBase(string filename)
	{
		this->filename = filename;
	}

	string get_filename()
	{
		return this->filename;
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

	list<string> tokenize_string(string line, char token)
	{
		// read about stringstream
		list<string> tokens;
		
		stringstream ss(line);
		string item;

		ss.clear();
		ss.seekg(0, ios::beg);

		while (getline(ss, item, token)) 
		{
			tokens.push_back(item);
		}

		return tokens;
	}
};

class UserDataBase : public BaseDataBase
{
private:
	const int username_index = 1;
	const int password_index = 2;
	const int access_level_index = 3;

public:
	UserDataBase(string filename) : BaseDataBase(filename) {}

	list<string> get_usernames()
	{
		// Если в файлике написан бред то приложение крашится
		ifstream file(this->filename);
		if (!file.is_open()) {
			cout << "Error opening file: " << this->filename << endl;
			throw exception();
		}
		list<string> usernames;
		// list<string> file_lines;

		string line;
		while (getline(file, line)) 
		{
			//file_lines.push_back(line);
			list<string> tokens = tokenize_string(line, ';');
			string username;
			int i = 0;
			for (auto iter = tokens.begin(); i < username_index; iter++)
			{
				if (i++ == username_index - 1)
				{
					username = *iter;
					usernames.push_back(username);
				}
			}
		}

		file.close();

		return usernames;
	}

	list<string> get_passwords()
	{
		// Если в файлике написан бред то приложение крашится
		ifstream file(this->filename);
		if (!file.is_open()) {
			cout << "Error opening file: " << this->filename << endl;
			throw exception();
		}
		list<string> passwords;
		// list<string> file_lines;

		string line;
		while (getline(file, line))
		{
			//file_lines.push_back(line);
			list<string> tokens = tokenize_string(line, ';');
			string password;
			int i = 0;
			for (auto iter = tokens.begin(); i < password_index; iter++)
			{
				if (i++ == password_index - 1)
				{
					password = *iter;
					passwords.push_back(password);
				}
			}
		}

		file.close();

		return passwords;

	}


	bool add_user(string username, string password)
	{
		// u can make "bool add_line() func which add any data
		// and placed in base class. 
		// CRUD operations can be placed in BaseDataBase

		// this function can be modified to add_admin
		// + one optional parameter bool is_admin

		ofstream file;
		file.open(this->filename, ios::app);
		if (!file.is_open()) {
			cout << "Error opening file: " << this->filename << endl;
			return false;
		}
		file << '\n' << username << ';' << password << ';' << "0";
		file.close();

		return true;
	}

	int get_access_level(string username)
	{
		ifstream file(this->filename);
		if (!file.is_open()) {
			cout << "Error opening file: " << this->filename << endl;
			throw exception();
		}
		int access_level = 0;
		// list<string> file_lines;

		string line;
		while (getline(file, line))
		{
			//file_lines.push_back(line);
			list<string> tokens = tokenize_string(line, ';');
			int i = 0;
			bool user_is_found = 0;
			for (string token : tokens)
			{
				if (i == 0 && token == username)
				{
					user_is_found = 1;
					break;
				}
				i++;
			}
			if (user_is_found)
			{
				access_level = atoi(tokens.back().c_str());
			}
		}
		file.close();
		return access_level;
	}
};


class TaskDataBase : BaseDataBase
{
	// this class will work with collection
public:
	TaskDataBase(string filename, string username) : BaseDataBase(filename)
	{
		this->filename = username + '_' + filename;

		ifstream i_file(this->filename);
		if (!i_file.is_open())
		{
			ofstream file(this->filename);
			file.close();
		}
		i_file.close();
	}

	list<Task*> get_tasks()
	{
		ifstream file(this->filename);
		if (!file.is_open()) {
			cout << "Error opening file: " << this->filename << endl;
			throw exception();
		}
		list<Task*> tasks;
		// list<string> file_lines;

		string line;
		while (getline(file, line))
		{
			list<string> tokens = tokenize_string(line, ';');
			Task* task = new Task(tokens);
			tasks.push_back(task);
		}

		file.close();

		return tasks;

	}



};
//DataBase::DataBase(string filename)
//{
//	this->filename = filename;
//}
//
//string DataBase::get_filename()
//{
//	return this->filename;
//}