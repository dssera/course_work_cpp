#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class BaseDataBase
{
protected:
public:
	string filename;
	string data;

	static int get_string_arr_length(const std::string* array) 
	{
		return 0;
	}
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
			return "";
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
		return nullptr;
		//std::stringstream ss(line);
		//std::string item;
		//int tokenCount = 0;

		//// Count the number of tokens
		//while (std::getline(ss, item, token)) {
		//	tokenCount++;
		//}

		//// Create an array of strings
		//std::string* tokens = new std::string[tokenCount];

		//// Reset the stringstream
		//ss.clear();
		//ss.seekg(0, std::ios::beg);

		//// Populate the array with tokens
		//int i = 0;
		//while (std::getline(ss, item, token)) {
		//	tokens[i++] = item;
		//}

		//return tokens;
	}
};

class UserDataBase : public BaseDataBase
{

public:
	UserDataBase(string filename) : BaseDataBase(filename)
	{

	}
	string* get_usernames()
	{
		return nullptr;
	}
	string* get_passwords()
	{
		return nullptr;

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