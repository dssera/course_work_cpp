#include "Auth.h"
#include "MainScreen.h"

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
			if (username.find(" "))
			{
				cout << "Invalid name. You can't use spaces." << endl;
				break;
			}
			cout << "Enter paswword" << endl;
			password = enter_password();
			
			user = register_user(username, password);
			// add this new user in tree and in file!!!!
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

void MainScreen::user_screen()
{
	int choice;
	do
	{
		cout << "1.Print My Tasks" << endl;
		cout << "2.Add Task" << endl;
		cout << "3.Change Task" << endl;
		cout << "4.Delete Task" << endl;
		cout << "5.Print Events for Day" << endl;
		cout << "6.Find by Event" << endl;
		cout << "7.Log out" << endl;
		cout << "0.Exit" << endl;

		choice = Tools::input_int();

		Event* event;
		string day;
		string time;
		string event_name;
		string name;
		string number;

		int buffer;

		switch (choice)
		{
		case 1:
			system("cls");
			print_events();
			break;

		case 2:
			system("cls");
			cout << "Add Task" << endl;
			cout << "Enter event" << endl;
			event_name = Tools::input_str();
			event = event_collection->get_by_event_name(event_name);
			if (event)
			{
				cout << "You've already have event with this name" << endl;
				break;
			}
			cout << "Enter day" << endl;
			day = Tools::enter_day();
			cout << "Enter time" << endl;
			time = Tools::enter_time();
			cout << "Enter name" << endl;
			name = Tools::input_str();
			cout << "Enter number" << endl;
			number = Tools::enter_number();
			add_event(day, time, event_name, name, number);
			break;
		case 3:
			system("cls");
			cout << "Enter which task you want to change(event name): ";
			// cin >> event_name;
			event_name = Tools::input_str();
			event = event_collection->get_by_event_name(event_name);
			if (!event)
			{
				cout << "There are no events with name like this." << endl;
				break;
			}
			event->print();
			cout << "Enter field which you want to change: " << endl;
			cout << "1.Day" << endl << "2.Time" << endl << "3.Event" << endl
				<< "4.Name" << endl << "5.Number" << endl << "0.Back" << endl;
			change_event(event);
			break;
		case 4:
			system("cls");
			cout << "Enter event name which you want to delete: ";
			// cin >> event_name;
			event_name = Tools::input_str();
			event = event_collection->get_by_event_name(event_name);
			delete_event(event_name);
			if (event) cout << "Event was deleted." << endl;
			else cout << "Event wasn't deleted. Check event name" << endl;
			// to make this possible you need to add id in each task
			break;
		case 5:
			cout << "Enter day: ";
			//cin >> day;
			day = Tools::enter_day();
			system("cls");
			print_events_by_day(day);
			break;
		case 6:
			system("cls");
			cout << "Enter event for search: ";
			// cin >> event_name;
			event_name = Tools::input_str();
			print_events_by_event_name(event_name);
			break;
		case 7:
			delete this->user;
			delete this->event_collection;
			system("cls");
			return;
		case 0:
			system("pause");
			exit(0);
		default:
			cout << "Wrong enter." << endl;
		}
		system("pause");
		system("cls");
	} while (true);
}
void MainScreen::admin_screen()
{
	int choice;
	do
	{
		cout << "1.Print Users" << endl;
		cout << "2.Add User" << endl;
		cout << "3.Change User Status" << endl;
		cout << "4.Delete User" << endl;
		cout << "5.Add Admin" << endl;
		cout << "6.Print Admins" << endl;
		cout << "7.Delete Admin" << endl;
		cout << "8.Log out" << endl;
		cout << "0.Exit" << endl;

		choice = Tools::input_int();

		string username;
		string password;
		int access_level;

		int buffer;

		switch (choice)
		{
		case 1:
			system("cls");
			print_users();
			break;
		case 2:
			cout << "Add new user: " << endl;
			cout << "Enter username: ";
			// cin >> username;
			username = Tools::input_str();
			if (username.find(" "))
			{
				cout << "Invalid name. You can't use spaces." << endl;
				break;
			}
			cout << "Enter password: ";
			// cin >> password;
			password = Tools::input_str();
			add_user(username, password);
			cout << "User was added!!" << endl;
			break;
		case 3:
			cout << "Enter username to change level access: ";
			//cin >> username;
			username = Tools::input_str();
			cout << "Set new level access(admin: 1, user: 0):" << endl;
			// cin >> access_level;
			access_level = Tools::input_int();
			change_access_level(access_level, username);
			break;
		case 4:
			cout << "Delete User:" << endl;
			cout << "Eneter username: ";
			// add current_user == username validation
			//cin >> username;
			username = Tools::input_str();
			delete_user(username);
			break;
		case 5:
			cout << "Add new admin: " << endl;
			cout << "Enter username: ";
			// cin >> username;
			username = Tools::input_str();
			if (username.find(" "))
			{
				cout << "Invalid name. You can't use spaces." << endl;
				break;
			}
			cout << "Enter password: ";
			//cin >> password;
			password = Tools::input_str();
			add_admin(username, password);
			cout << "Admin was added!!" << endl;
			break;
		case 6:
			cout << "Print Admins: " << endl;
			print_admins();
			break;
		case 7:
			cout << "Delete Admin: " << endl;
			cout << "Enter username: ";
			// add current_user == username validation

			//cin >> username;
			username = Tools::input_str();
			delete_admin(username);

			break;
		case 8:
			delete this->user;
			delete this->event_collection;
			delete this->user_collection;
			system("cls");
			return;
		case 0:
			system("pause");
			exit(0);
		default:
			cout << "Wrong enter." << endl;
		}
		system("pause");
		system("cls");
	} while (true);
}