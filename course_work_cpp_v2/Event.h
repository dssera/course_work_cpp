#pragma once
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Event
{
private:
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
		if (list.size() != 5) cout << "Error in Task constructor" << endl;
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

	string get_day()
	{
		return this->day;
	}
	string get_time()
	{
		return this->time;
	}
	string get_event()
	{
		return this->event;
	}
	string get_name()
	{
		return this->name;
	}
	string get_number()
	{
		return this->number;
	}
};

