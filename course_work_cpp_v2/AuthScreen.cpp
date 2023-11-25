#include "AuthScreen.h"


User* AuthScreen::run()
{
	User* user = nullptr;
	do
	{
		user = auth_menu();
	} while (user == nullptr);

	return user;
}

// delete sign_up and sign_in - they're a part of interface auth_menu()
User* AuthScreen::sign_in()
{
	cout << "Sign In: " << endl;
	string username, password;
	cout << "Enter username" << endl;
	cin >> username;
	cout << "Enter paswword" << endl;
	cin >> password;

	User* user = auth(username, password);
	return user;
}

User* AuthScreen::sign_up()
{
	cout << "Create a new user:" << endl;
	string username, password;
	cout << "Enter username" << endl;
	cin >> username;
	cout << "Enter paswword" << endl;
	cin >> password;
	//password validation

	User* user_from_db = new User("user1", "password");

	//add user in db or raise an error
	//and then retutn pointer on gotten user
	return user_from_db;
}

void AuthScreen::identificate(string username)
{
	// вообще то здесь мы должны чекнуть есть ли наше имя в БД
	// get_username

	// видит ли эта функция this?
	// if (PLUG != username)
	if ("dssera" != username)
		throw exception("identification error: \
bool identificate(string username)");
}

User* AuthScreen::auth(string username, string password)
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
User* AuthScreen::auth_menu()
{
	bool authenticated;
	int enter;
	User* user = nullptr;
	cout << "Auth Menu" << endl << "1.Sign In" << endl
		<< "2.Sign Up" << endl << "0.Exit" << endl;


	cout << "Your enter: ";
	cin >> enter;

	switch (enter)
	{
	case(1):
		cout << SIGN_IN << endl;
		// user = sign_in();
		user = sign_in();
		break;
	case(2):
		cout << SIGN_UP << endl;
		user = sign_up();
		break;
	case(0):
		system("pause");
		exit(0);
		break;
	default:
		break;
	}
	return user;
}