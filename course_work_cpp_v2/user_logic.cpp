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
	collection->print_by_day(day);
}

void MainScreen::search_by_event(string event_name)
{
	this->collection->find_by_event_name(event_name);
}

// update
void MainScreen::change_task(string event_name, int choice)
{
	Event* event = collection->get_by_event_name(event_name);
	event->print();
	system("pause");
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
	this->collection->delete_by_event_name(event_name);
}