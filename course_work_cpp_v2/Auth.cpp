#include "Auth.h"

// delete sign_up and sign_in - they're a part of interface auth_menu()


string Auth::identificate(string username)
{
	list<string> usernames = this->db->get_usernames();

	
	for (string username_ : usernames)
	{
		if (username == username_)
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


	list<string> passwords = this->db->get_passwords();
	for (string password_ : passwords)
	{
		if (password == password_)
		{
			user = new User(username, password);

		}
	}
	if (user == nullptr)
	{
		cout << "There is no user with login and password like these" << endl;
		return nullptr;
	}

	return user;
	// this->is_authenticated = true;
}
