#include "Auth.h"

string Auth::identificate(string username)
{
	string** usernames = this->db->get_usernames();

	/*for (string username_ : usernames)
	{
		if (username == username_)
		{
			return username;
		}
	}*/
	int i = 0;
	while (usernames[i] != nullptr)
	{
		if (username == *usernames[i++])
		{
			return username;
		}
	}
	
	return NO_MATCH;
	// + ADD THE EXCEPTION FOR USERNAME "NO MATCH"
}

User* Auth::auth(string username, string password)
{
	User* user = nullptr;

	if (identificate(username) == NO_MATCH)
	{
		cout << "There is no user with login like this" << endl;
		return nullptr;
	}

	string password_from_db = this->db->get_password(username);
	
	SHA256 sha256;
	if (sha256(password) == password_from_db)
	{
		user = new User(username, password, this->db->get_access_level(username));

	}
	if (user == nullptr)
	{
		cout << "There is no user with login and password like these" << endl;
		return nullptr;
	}

	return user;
	// this->is_authenticated = true;
}


