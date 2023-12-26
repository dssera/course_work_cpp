#include "Event.h"

string Event::get_day()
{
	return this->day;
}
void Event::set_day(string day)
{
	this->day = day;
}
string Event::get_time()
{
	return this->time;
}
void Event::set_time(string time)
{
	this->time = time;
}
string Event::get_event_name()
{
	return this->event_name;
}
void Event::set_event_name(string event_name)
{
	this->event_name = event_name;
}
string Event::get_name()
{
	return this->name;
}
void Event::set_name(string name)
{
	this->name = name;
}
string Event::get_number()
{
	return this->number;
}
void Event::set_number(string number)
{
	this->number = number;
}
void Event::print()
{
	cout << "Event name: " << this->event_name << endl <<
		"Day: " << this->day << endl <<
		"Time: " << this->time << endl <<
		"Names: " << this->name << endl << 
		"Number: " << this->number << endl;
}