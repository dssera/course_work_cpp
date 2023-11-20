#include "User.h"

using namespace std;

BaseUser::BaseUser(string username, string password)
{
	this->username = username;
	this->password = password;
}

void User::set_access_level(string access_level)
{
	this->access_level = access_level;
}
User::User(string username, string password, string access_level) : BaseUser(username, password)
{
	this->access_level = access_level;
}

string User::get_access_level()
{
	return this->access_level;
}