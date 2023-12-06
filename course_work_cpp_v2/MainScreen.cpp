#include "MainScreen.h"
#include "Auth.h"


void MainScreen::run()
{
	do
	{
		Auth* auth = new Auth(new UserDataBase("auth.txt"));
		User* user = auth->run_auth_menu();
		TreeCollection* collection = new TreeCollection(user->get_username());

		// is it okey??
		this->collection = collection;
		this->user = user;

		if (user->is_admin()) admin_screen();
		else user_screen();

	} while (true);
}




// u did changes in collection and then save it
void MainScreen::save_file()
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
		cout << "2.Print Events for Day" << endl;
		cout << "3.Find by Event" << endl;
		cout << "4.Log out" << endl;
		cout << "0.Exit" << endl;

		cin >> choice;
		string event;
		string day;


		switch (choice)
		{
			case 1:
				system("cls");
				print_tasks();
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
				search_by_event(event);
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
void MainScreen::admin_screen()
{
	int choice;
	do
	{
		cout << "1.Print My Tasks" << endl;
		cout << "2.Print Events for Day" << endl;
		cout << "3.Find by Event" << endl;
		cout << "0.Exit" << endl;

		cout << "Your enter: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				break;
			case 0:
				exit(0);
				break;
			default:
				cout << "Wrong enter." << endl;
				

		}
		system("pause");
		system("cls");
	} while (true);
}
