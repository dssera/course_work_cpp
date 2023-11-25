#include "Auth.h"

// delete sign_up and sign_in - they're a part of interface auth_menu()


string Auth::identificate(string username)
{
	string* usernames = this->db->get_usernames();
	
	for (int i = 0; i < usernames->length(); i++)
	{
		if (username == usernames[i])
		{
		 return username;
		}
	}
	return NO_MATCH;
	// + ADD THE EXCEPTION FOR USERNAME "NO MATCH"

}

User* Auth::auth(string username, string password)
{
	User* user_from_db = nullptr;

	if (identificate(username) == NO_MATCH)
	{
		cout << "There is no user with login like this" << endl;
		return nullptr;
	}


	string* passwords = this->db->get_passwords();
	/*for (int i = 0; i < passwords.length(); i++)
	{
		if (password == passwords[i])
		{
			user_from_db = new User("name1", "password");

		}
	}*/
	if (user_from_db == nullptr)
	{
		cout << "There is no user with login and password like these" << endl;
		return nullptr;
	}

	return user_from_db;
	// this->is_authenticated = true;
}
