#pragma once
#include "Constants.h"
#include "User.h"
#include <iostream>
using namespace std;




class AuthScreen
{
public:
	User* run();

protected:
	User* sign_in();

	User* sign_up();

	void identificate(string username);

	User* auth(string username, string password);
	User* auth_menu();
};
