#pragma once
#include "Constants.h"
#include "User.h"
#include "db.h"
#include "sha256.h"
#include <string>
#include "Tools.h"

using namespace std;

class Auth
{
private:
	UserDataBase* db;

	string identificate(string username);
	User* auth(string username, string password);
	User* register_user(string username, string password);

public:
	Auth(UserDataBase* db)
	{
		this->db = db;
	}
	User* run_auth_menu();

};
