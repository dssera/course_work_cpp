#include "MainScreen.h"

// create
void MainScreen::add_task(string day, string time, 
	string event, string name, string number)
{

}

// read
void MainScreen::print_tasks()
{
	collection->print(); 
}

void MainScreen::print_events_by_day(string day)
{

	bool no_data = true;

	list<Event*> tasks = collection->get_tasks();
	for (Event* task : tasks)
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

	Event* match = this->collection->find(event);

	if (match)
	{
		cout << "It's found" << endl << match->get_day() << endl;
	}
	else
	{
		cout << "not found" << endl;
	}
}

// update
void MainScreen::change_task(int id)
{

}

// delete
void MainScreen::delete_task(int id)
{

}