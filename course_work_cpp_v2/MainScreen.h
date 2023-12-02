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
	void delete_user();
	void add_admin();
	void delete_admin();

	void add_task();
	void change_task();
	void delete_task();
	// u did changes in collection and then save it
	void save_file();
	// отмена изменений??



	// use hash_table or array to do sort in tree not by .length() but by index of day
	// "monday" : 1, ...
	void print_tasks();
	void print_events_by_day();
	void search_by_event();


	void print_user_menu();
	void print_admin_menu();

	void user_screen();
	void admin_screen();


public:
	MainScreen(TreeCollection* collection, User* user);
	void run();
};

