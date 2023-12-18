#include "MainScreen.h"

// create
void MainScreen::add_event(string day, string time, 
	string event, string name, string number)
{
	Event* event_obj = new Event(day, time, event, name, number);

	event_collection->insert(event_obj);

	save_events();
}

// read
void MainScreen::print_events()
{
	event_collection->print(); 
}

void MainScreen::print_events_by_day(string day)
{
	event_collection->print_by_day(day);
}

void MainScreen::print_events_by_event_name(string event_name)
{
	this->event_collection->find_by_event_name(event_name);
}

// update
void MainScreen::change_event(string event_name, int choice)
{
	Event* event = event_collection->get_by_event_name(event_name);
	event->print();
	system("pause");
	string new_data;
	cout << "Enter new value for field: ";
	new_data = Tools::input_str();
	// cin >> new_data;

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
	save_events();
}

// delete
void MainScreen::delete_event(string event_name)
{
	this->event_collection->delete_by_event_name(event_name);
	save_events();
}