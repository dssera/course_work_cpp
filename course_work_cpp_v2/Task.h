#pragma once
#include <string>

using namespace std;

class Task
{
private:
	string day;
	string time;
	string event;
	string name;
	string number;
public:
	Task() {}
	Task(string day)
	{
		this->day = day;
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

