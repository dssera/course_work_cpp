#include "MainScreen.h"
#include "Auth.h"


void MainScreen::run()
{
	do
	{
		UserDataBase* user_db = new UserDataBase("auth.txt");
		Auth* auth = new Auth(user_db);
		User* user = auth->run_auth_menu();

		UserTreeCollection* user_collection = new UserTreeCollection(user_db);
		EventTreeCollection* event_collection = new EventTreeCollection(user->get_username());

		// is it okey??
		this->user_collection = user_collection;
		this->event_collection = event_collection;
		this->user = user;

		if (user->is_admin()) admin_screen();
		else user_screen();

	} while (true);
}


// u did changes in collection and then save it
void MainScreen::save_users()
{
	this->user_collection->save_in_file();
}
void MainScreen::save_events()
{
	this->event_collection->save_in_file();
}
// отмена изменений??
// use hash_table or array to do sort in tree not by .length() but by index of day
// "monday" : 1, ...



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
				cout << "Enter day" << endl;
				day = Tools::input_str();
				cout << "Enter time" << endl;
				// cin >> time;
				time = Tools::input_str();
				cout << "Enter event" << endl;
				//cin >> event_name;
				event_name = Tools::input_str();
				cout << "Enter name" << endl;
				//cin >> name;
				name = Tools::input_str();
				cout << "Enter number" << endl;
				//cin >> number;
				number = Tools::input_str();
				add_event(day, time, event_name, name, number);
				break;
			case 3:
				system("cls");
				cout << "Enter which task you want to change(event name): ";
				// cin >> event_name;
				event_name = Tools::input_str();
				cout << "Enter field which you want to change: " << endl;
				cout << "1.Day" << endl << "2.Time" << endl << "3.Event" << endl
					<< "4.Name" << endl << "5.Number" << endl;
				// cin >> buffer;
				buffer = Tools::input_int();
				change_event(event_name, buffer);
				// to make this possible you need to add id in each task
				break;
			case 4:
				system("cls");
				cout << "Enter event name which you want to delete: ";
				// cin >> event_name;
				event_name = Tools::input_str();
				delete_event(event_name);
				// to make this possible you need to add id in each task
				break;
			case 5:
				cout << "Enter day: ";
				//cin >> day;
				day = Tools::input_str();
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
			cout << "Eneter username: ";
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
