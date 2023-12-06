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

	void add_user();
	void print_users();
	void delete_user();
	void change_user();

	void add_admin();
	void print_admins();
	void delete_admin();

	void add_task();
	void change_task();
	void delete_task();

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

