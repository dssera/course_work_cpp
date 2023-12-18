#include "Auth.h"

string Auth::identificate(string username)
{
	string** usernames = this->db->get_usernames();
	int i = 0;
	while (usernames[i] != nullptr)
	{
		if (username == *usernames[i++])
		{
			return username;
		}
	}
	return NO_MATCH;
}

User* Auth::auth(string username, string password)
{
	User* user = nullptr;
	// identification
	if (identificate(username) == NO_MATCH)
	{
		cout << "There is no user with login like this" << endl;
		return nullptr;
	}
	// auth
	string password_from_db = this->db->get_password(username);
	SHA256 sha256;
	if (sha256(password) == password_from_db)
	{
		user = new User(username, password, this->db->get_access_level(username));
	}
	else
	{
		cout << "There is no user with login and password like these" << endl;
		return user;
	}
	return user;
}

User* Auth::register_user(string username, string password)
{
	SHA256 sha256;
	User* new_user = nullptr;
	// validations
	string** usernames = this->db->get_usernames();
	if (username == NO_MATCH)
	{
		cout << "Entered name is reserved!!" << endl;
		return new_user;
	}
	int i = 0;
	bool flag = false;
	while (usernames[i] != nullptr)
	{
		if (username == *usernames[i++])
		{
			cout << "Entered name is reserved!!" << endl;
			flag = true;
		}
	}
	if (flag) return new_user;
	// registration
	password = sha256(password);
	if (db->add_user(username, password))
	{
		cout << "User was added!!" << endl;
		new_user = new User(username, password);
	}
	return new_user;
}


