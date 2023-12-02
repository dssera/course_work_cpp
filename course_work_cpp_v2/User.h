#pragma once
#include "Constants.h"
#include <iostream>
using namespace std;


class BaseUser
{
protected:
	BaseUser(string username, string password);
	string username;
	string password;
	int _is_admin;
public:
	bool is_admin()
	{
		return this->_is_admin;
	}
	string get_username()
	{
		return this->username;
	}
};

class User : public BaseUser
{
public:
	User(string username, string password, int _is_admin=0);
};



