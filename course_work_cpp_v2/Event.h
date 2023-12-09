#pragma once
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Event
{
private:
	const int fields_count = 5;

	int id;
	string day;
	string time;
	string event;
	string name;
	string number;
public:
	Event() {}
	Event(string day)
	{
		this->day = day;
	}
	Event(list<string> list)
	{
		if (list.size() != fields_count) cout << "Error in Task constructor: not " << 
			fields_count << " tokens are given" << endl;
		else
		{
			// переделай
			
			this->day = list.front();
			list.pop_front();
			this->time = list.front();
			list.pop_front();
			this->event = list.front();
			list.pop_front();
			this->name = list.front();
			list.pop_front();
			this->number = list.front();
			list.pop_front();
		}
	}
	Event(string day, string time,
		string event, string name, string number)
	{
		this->day = day;
		this->time = time;
		this->event = event;
		this->name = name;
		this->number = number;
	}
	int get_id()
	{
		return this->id;
	}
	void set_id(int id)
	{
		this->id = id;
	}
	string get_day()
	{
		return this->day;
	}
	void set_day(string day)
	{
		this->day = day;
	}
	string get_time()
	{
		return this->time;
	}
	void set_time(string time)
	{
		this->time = time;
	}
	string get_event()
	{
		return this->event;
	}
	void set_event(string event)
	{
		this->event = event;
	}
	string get_name()
	{
		return this->name;
	}
	void set_name(string name)
	{
		this->name = name;
	}
	string get_number()
	{
		return this->number;
	}
	void set_number(string number)
	{
		this->number = number;
	}
};

