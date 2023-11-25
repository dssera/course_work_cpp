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
	DataBase* db;
	string usernmae;
	string password;
	

public:
	Auth(DataBase* db)
	{
		this->db = db;
	}
	User* run_auth_menu();
protected:
	void identificate(string username);

	User* auth(string username, string password);
	
};
