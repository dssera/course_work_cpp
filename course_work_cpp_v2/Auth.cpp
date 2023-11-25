#include "Auth.h"

// delete sign_up and sign_in - they're a part of interface auth_menu()


void Auth::identificate(string username)
{
	// вообще то здесь мы должны чекнуть есть ли наше имя в БД
	// get_username

	// видит ли эта функция this?
	// if (PLUG != username)

	if ("dssera" != username)
		throw exception("identification error: \
bool identificate(string username)");
}

User* Auth::auth(string username, string password)
{
	// signature will be changed when you add try-catch, you need to return smth to show that user is not authenticated
	// but you don't want to close all application
	identificate(username);
	// get_password
	//string password_from_db = PLUG;
	string password_from_db = "12345";
	if (password_from_db != password)
	{
		// this->is_authenticated = false;
		throw exception("auth error : \
			bool auth(string username, string password)");
	}

	User* user_from_db = new User("name1", "password");
	return user_from_db;
	// this->is_authenticated = true;
}
