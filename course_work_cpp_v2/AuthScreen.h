#pragma once
#include "Constants.h"
#include "User.h"
#include "db.h"
using namespace std;

#pragma once


class AuthScreen
{
private:
	DataBase* db;
public:
	User* run();
	AuthScreen(DataBase* db)
	{
		this->db = db;
	}
protected:
	User* sign_in();

	User* sign_up();

	void identificate(string username);

	User* auth(string username, string password);
	User* auth_menu();
};
