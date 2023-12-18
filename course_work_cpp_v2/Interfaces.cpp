#include "Auth.h"

User* Auth::run_auth_menu()
{
	User* user = nullptr;
	do
	{
		int enter;
		string username, password;

		cout << "Auth Menu" << endl << "1.Sign In" << endl
			<< "2.Sign Up" << endl << "0.Exit" << endl;

		cout << "Your enter: ";
		enter = Tools::input_int();
		switch (enter)
		{
		case(1):
			cout << SIGN_IN << endl;
			cout << "Sign In: " << endl;
			cout << "Enter username" << endl;
			username = Tools::input_str();
			cout << "Enter paswword" << endl;
			password = Tools::input_str();

			user = auth(username, password);
			break;
		case(2):
			cout << SIGN_UP << endl;
			cout << "Create a new user:" << endl;
			cout << "Enter username" << endl;
			username = Tools::input_str();
			cout << "Enter paswword" << endl;
			password = enter_password();
			
			user = register_user(username, password);
			if (!user) break;
			break;
		case(0):
			system("pause");
			exit(0);
			break;
		default:
			cout << "Wrong input!!" << endl;
			break;
		}
	} while (user == nullptr);
	return user;
}