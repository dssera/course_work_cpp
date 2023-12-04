#pragma once
#include "Constants.h"
#include "User.h"
#include "db.h"
#include "sha256.h"
#include <string>
using namespace std;

#pragma once


class Auth
{
private:
	UserDataBase* db;

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
