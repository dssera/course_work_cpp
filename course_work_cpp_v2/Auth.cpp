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
	// FIX BUG WITH LOGIN FOR ONE ACCOUNT AND USER FOR ANOTHER
	User* user = nullptr;

	if (identificate(username) == NO_MATCH)
	{
		cout << "There is no user with login like this" << endl;
		return nullptr;
	}

	string password_ = this->db->get_password(username);
	
	SHA256 sha256;
	if (sha256(password) == password_)
	{
		int access_level = this->db->get_access_level(username);
		user = new User(username, password, access_level);

	}
	if (user == nullptr)
	{
		cout << "There is no user with login and password like these" << endl;
		return nullptr;
	}

	return user;
	// this->is_authenticated = true;
}


