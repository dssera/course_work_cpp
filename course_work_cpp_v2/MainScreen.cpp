#include "MainScreen.h"

void MainScreen::run()
{
	int choice;
	do
	{
		cout << "Your enter: ";
		cin >> choice;

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

}
void MainScreen::print_events_by_day()
{

}
void MainScreen::search_by_event()
{

}


void MainScreen::print_user_menu()
{

}
void MainScreen::print_admin_menu()
{

}

void MainScreen::user_screen()
{
	int choice;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			break;
		default:
			break;
		}
	} while (true);
}
void MainScreen::admin_screen()
{
	int choice;
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			break;
		default:
			break;
		}
	} while (true);
}
