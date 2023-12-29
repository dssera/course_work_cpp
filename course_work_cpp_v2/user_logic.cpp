#include "MainScreen.h"

// create
void MainScreen::add_event(string day, string time, 
	string event_name, string name, string number)
{
	Event* event_from_db = event_collection->get_by_event_name(event_name);
	if (event_from_db)
	{
		cout << "You've already have event with this name" << endl;
		system("pause");
		return;
	}
	Event* event_obj = new Event(day, time, event_name, name, number);

	event_collection->insert(event_obj);
	cout << "Event was successfully added!" << endl;
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
void MainScreen::change_event(Event* event)
{
	int choice;
	string new_data;
	bool flag = true;
	while (flag)
	{
		cout << "Enter: ";
		choice = Tools::input_int();
		switch (choice)
		{
			case 1:
				cout << "Enter new day: ";
				new_data = Tools::enter_day();
				event->set_day(new_data);
				flag = false;
				break;
			case 2:
				cout << "Enter new time: ";
				new_data = Tools::enter_time();
				event->set_time(new_data);
				flag = false;
				break;
			case 3:
				cout << "Enter new name: ";
				new_data = Tools::enter_event_name();
				event->set_event_name(new_data);
				flag = false;
				break;
			case 4:
				cout << "Enter new event name: ";
				new_data = Tools::enter_names();
				event->set_name(new_data);
				flag = false;
				break;
			case 5:
				cout << "Enter new number: ";
				new_data = Tools::enter_number();
				event->set_number(new_data);
				flag = false;
				break;
			case 0:
				return;
			default:
				cout << "Wrong enter!!!" << endl;
		}
	}
	save_events();
}

// delete
void MainScreen::delete_event(string event_name)
{
	this->event_collection->delete_by_event_name(event_name);
	save_events();
}