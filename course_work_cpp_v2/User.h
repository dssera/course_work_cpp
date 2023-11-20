#pragma once
#include "Constants.h"
#include <iostream>
using namespace std;


class BaseUser
{
public:
	string username;
	string password;
	bool is_authenticated;

protected:
	BaseUser(string username, string password);
};

class User : public BaseUser
{
	string access_level;

	void set_access_level(string access_level);
public:
	User(string username, string password, string access_level = USER_ACCESS_LEVEL);

	string get_access_level();

};

