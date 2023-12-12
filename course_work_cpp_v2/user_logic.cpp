#include "MainScreen.h"

// create
void MainScreen::add_task(string day, string time, 
	string event, string name, string number)
{
	Event* event_obj = new Event(day, time, event, name, number);

	collection->insert(event_obj);
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
			cout << task->get_event_name() << endl;
			no_data = false;
		}
	}
	if (no_data) cout << "There are no data" << endl;
}

void MainScreen::search_by_event(string event)
{

	Event* match = this->collection->find_by_event(event);

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
void MainScreen::change_task(int id, int choice)
{
	Event* event = collection->find_by_id(id);
	string new_data;
	cout << "Enter new value for field: ";
	cin >> new_data;
	switch (choice)
	{
	case 1:
		event->set_day(new_data);
		break;
	case 2:
		event->set_time(new_data);
		break;
	case 3:
		event->set_event_name(new_data);
		break;
	case 4:
		event->set_name(new_data);
		break;
	case 5:
		event->set_number(new_data);
		break;
	default:
		break;
	}
}

// delete
void MainScreen::delete_task(string event_name)
{
	this->collection->delete_by_name(event_name);
}