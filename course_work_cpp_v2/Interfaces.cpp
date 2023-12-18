#include "Auth.h"
#include "Tools.h"

User* Auth::run_auth_menu()
{
	User* user = nullptr;

	do
	{
		int enter;
		string username, password;
		SHA256 sha256;


		cout << "Auth Menu" << endl << "1.Sign In" << endl
			<< "2.Sign Up" << endl << "0.Exit" << endl;


		cout << "Your enter: ";
		// cin >> enter;
		// cin.ignore();
		enter = Tools::input_int();
		cin.ignore();
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
			if (username == NO_MATCH)
			{
				cout << "Entered name is reserved!!" << endl;
				break;
			}
			cout << "Enter paswword" << endl;
			password = enter_password();
			cout <<"Entered password: "<< password << endl;
			
			password = sha256(password);

			if (db->add_user(username, password))
			{
				cout << "User was added!!" << endl;
				user = new User(username, password);
			}
			// вынести регистрацию в отдельный файл

			//add user in db or raise an error
			//and then retutn pointer on gotten user
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