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

	string enter_password()
	{
		string password;
		do
		{
			password = Tools::input_str();
			if (password.length() <= 4)
			{
				cout << "!!Password can't be less than 5 characters. Enter other one:" << endl;
				continue;
			}
			break;

		} while (true);
		return password;
	}
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
