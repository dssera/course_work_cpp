#pragma once
#include "Constants.h"
#include "User.h"
#include "db.h"
#include <string>
using namespace std;

#pragma once


class Auth
{
private:
	UserDataBase* db;
	string usernmae;
	string password;
	

public:
	Auth(UserDataBase* db)
	{
		this->db = db;
	}
	User* run_auth_menu();
protected:
	string identificate(string username);

	User* auth(string username, string password);
	
};
