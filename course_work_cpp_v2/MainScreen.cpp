#include "MainScreen.h"

void MainScreen::run()
{
	int choice;
	do
	{
		if (user->is_admin()) admin_screen();
		else user_screen();

	} while (true);
}

MainScreen::MainScreen(TreeCollection* collection, User* user)
{
	this->collection = collection;
	this->user = user;
}


void MainScreen::add_user()
{

}
void MainScreen::delete_user()
{

}
void MainScreen::change_user()
{
	/*user = getUser();
	user.set_status(0|1, current_user);
	void set_status()
	{
		if (current_user.status == "admin")
		{
			set
		}
		else throw exception();
	}*/
}
void MainScreen::add_admin()
{

}
void MainScreen::delete_admin()
{

}

void MainScreen::add_task()
{

}
void MainScreen::change_task()
{

}
void MainScreen::delete_task()
{

}
// u did changes in collection and then save it
void MainScreen::save_file()
{

}
// отмена изменений??
// use hash_table or array to do sort in tree not by .length() but by index of day
// "monday" : 1, ...
void MainScreen::print_tasks()
{
	collection->print();
}
void MainScreen::print_events_by_day(string day)
{
	
	bool no_data = true;

	list<Task*> tasks = collection->get_tasks();
	for (Task* task : tasks)
	{
		if (task->get_day() == day)
		{
			cout << task->get_event() << endl;
			no_data = false;
		}
	}
	if (no_data) cout << "There are no data" << endl;
}
void MainScreen::search_by_event(string event)
{
	
	Task* match = this->collection->find(event);
	
	if (match)
	{
		cout << "It's found" << endl << match->get_day() << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
}


void MainScreen::user_screen()
{
	
	int choice;
	do
	{
		cout << "1.Print My Tasks" << endl;
		cout << "2.Print Events for Day" << endl;
		cout << "3.Find by Event" << endl;
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
