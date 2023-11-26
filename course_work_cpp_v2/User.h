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
	int access_level;

	void set_access_level(int access_level);
public:
	User(string username, string password, int access_level = 0);

	int get_access_level();

};

