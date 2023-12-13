#include "MainScreen.h"
#include "Auth.h"


void MainScreen::run()
{
	do
	{
		Auth* auth = new Auth(new UserDataBase("auth.txt"));
		User* user = auth->run_auth_menu();
		EventTreeCollection* collection = new EventTreeCollection(user->get_username());

		// is it okey??
		this->collection = collection;
		this->user = user;

		if (user->is_admin()) admin_screen();
		else user_screen();

	} while (true);
}


// u did changes in collection and then save it
void MainScreen::save_in_file()
{

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

		cin >> choice;
		
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
				cin >> day;
				cout << "Enter time" << endl;
				cin >> time;
				cout << "Enter event" << endl;
				cin >> event_name;
				cout << "Enter name" << endl;
				cin >> name;
				cout << "Enter number" << endl;
				cin >> number;
				add_event(day, time, event_name, name, number);
				break;
			case 3:
				system("cls");
				cout << "Enter which task you want to change(event name): ";
				cin >> event_name;
				cout << "Enter field which you want to change: " << endl;
				cout << "1.Day" << endl << "2.Time" << endl << "3.Event" << endl
					<< "4.Name" << endl << "5.Number" << endl;
				cin >> buffer;
				change_event(event_name, buffer);
				// to make this possible you need to add id in each task
				break;
			case 4:
				system("cls");
				cout << "Enter event name which you want to delete: ";
				cin >> event_name;
				delete_event(event_name);
				// to make this possible you need to add id in each task
				break;
			case 5:
				cout << "Enter day: ";
				cin >> day;
				system("cls");
				print_events_by_day(day);
				break;
			case 6:
				system("cls");
				cout << "Enter event for search: ";
				cin >> event_name;
				print_events_by_event_name(event_name);
				break;
			case 7:
				delete this->user;
				delete this->collection;
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
		cout << "3.Add User" << endl;
		cout << "4.Change User" << endl;
		cout << "2.Print Admins" << endl;
		cout << "4.Add Admin" << endl;
		cout << "0.Exit" << endl;

		cin >> choice;
		string event;
		string day;


		switch (choice)
		{
		case 1:
			system("cls");
			print_events();
			break;
		case 2:
			cout << "Enter day: ";
			cin >> day;
			system("cls");
			print_events_by_day(day);
			break;
		case 3:
			system("cls");
			cout << "Enter event for search: ";
			cin >> event;
			print_events_by_event_name(event);
			break;
		case 4:
			delete this->user;
			delete this->collection;
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
