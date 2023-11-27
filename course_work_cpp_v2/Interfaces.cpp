#include "Auth.h"
#include "User.h"

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
		cin >> enter;

		switch (enter)
		{
		case(1):
			cout << SIGN_IN << endl;
			// user = sign_in();
			cout << "Sign In: " << endl;
			cout << "Enter username" << endl;
			cin >> username;
			cout << "Enter paswword" << endl;
			cin >> password;

			user = auth(username, password);
			break;
		case(2):
			cout << SIGN_UP << endl;
			cout << "Create a new user:" << endl;
			cout << "Enter username" << endl;
			cin >> username;
			cout << "Enter paswword" << endl;
			cin >> password;
			//password validation
			
			if (db->add_user(username, password))
			{
				cout << "User was added!!" << endl;
				user = new User(username, password);
			}


			//add user in db or raise an error
			//and then retutn pointer on gotten user
			break;
		case(0):
			system("pause");
			exit(0);
			break;
		default:
			break;
		}
	} while (user == nullptr);
	return user;
}