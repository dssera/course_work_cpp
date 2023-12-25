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
	BaseUser() {}
	
	string get_username()
	{
		return this->username;
	}
	void set_username(string username)
	{
		this->username = username;
	}
	string get_password()
	{
		return this->password;
	}
	void set_password(string password)
	{
		this->password = password;
	}
	int is_admin();
	void set_access_level(int access_level);
};

class User : public BaseUser
{
public:
	User(string username, string password, int _is_admin=0);
	User() {}
};



