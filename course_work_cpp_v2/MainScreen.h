#pragma once
#include "User.h"
#include "Container.h"

class MainScreen
{
private:
	TreeCollection* collection;
	User* user;
	// buffer field

	// a lot of methods

	void add_user(string username, string password);
	void print_users();
	void delete_user(string username);
	void change_user_status();

	void add_admin(string username, string password);
	void print_admins();
	void delete_admin(string username);

	void add_task(string day, string time,
		string event, string name, string number);
	void change_task(int id);
	void delete_task(int id);

	void save_file();

	// use hash_table or array to do sort in tree not by .length() but by index of day
	// "monday" : 1, ...
	void print_tasks();
	void print_events_by_day(string day);
	void search_by_event(string event);


	void user_screen();
	void admin_screen();
public:
	MainScreen() {};
	void run();
};

