#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "Constants.h"

using namespace std;

class BaseDataBase
{
protected:
public:
	string filename;
	string data;


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
	const int username_index = 2;
	const int password_index = 3;

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
};


class TaskDataBase : BaseDataBase
{
	// this class will work with collection
public:
	TaskDataBase(string filename) : BaseDataBase(filename)
	{

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