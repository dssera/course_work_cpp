#include "User.h"

using namespace std;

BaseUser::BaseUser(string username, string password)
{

	this->username = username;
	this->password = password;
}


User::User(string username, string password, int _is_admin)
	: BaseUser(username, password)
{
	this->_is_admin = _is_admin;
}
void User::print()
{
	cout << "Username: " << this->username << endl;
	if (this->is_admin()) cout << "Access-level: admin" << endl;
	else cout << "Access-level: user" << endl;
	cout << "Password: " << this->password << endl;
}
int BaseUser::is_admin()
{
	return this->_is_admin;
}
void BaseUser::set_access_level(int access_level)
{
	this->_is_admin = access_level;
}

