#include "User.h"

using namespace std;

BaseUser::BaseUser(string username, string password)
{
	this->username = username;
	this->password = password;
}


User::User(string username, string password, bool is_admim)
	: BaseUser(username, password)
{
	this->_is_admin = is_admin;
}


