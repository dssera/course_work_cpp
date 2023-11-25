#pragma once
#include <string>

#pragma once
#include <iostream>

using namespace std;


class DataBase
{
protected:
	string filename;
	string data;

public:
	DataBase(string filename)
	{
		this->filename = filename;
	}

	string get_filename()
	{
		return this->filename;
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