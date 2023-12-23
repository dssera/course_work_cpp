#pragma once
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Event
{
private:
	const int fields_count = 5;

	string day;
	string time;
	string event_name;
	string name;
	string number;
public:
	Event() {}
	Event(string day)
	{
		this->day = day;
	}
	Event(string day, string time,
		string event_name, string name, string number)
	{
		this->day = day;
		this->time = time;
		this->event_name = event_name;
		this->name = name;
		this->number = number;
	}
	string get_day();
	void set_day(string day);
	string get_time();
	void set_time(string time);
	string get_event_name();
	void set_event_name(string event_name);
	string get_name();
	void set_name(string name);
	string get_number();
	void set_number(string number);
	void print();
};

