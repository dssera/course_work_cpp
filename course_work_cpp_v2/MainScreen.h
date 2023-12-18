#pragma once
#include "User.h"
#include "Container.h"
#include "UserTreeCollection.h"
#include "Tools.h"

class MainScreen
{
private:
	EventTreeCollection* event_collection;
	UserTreeCollection* user_collection;
	User* user;
	// buffer field

	// a lot of methods

	void add_user(string username, string password);
	void print_users();
	void delete_user(string username);
	void change_access_level(int access_level, string username);

	void add_admin(string username, string password);
	void print_admins();
	void delete_admin(string username);

	void add_event(string day, string time,
		string event, string name, string number);
	void change_event(string event_name, int choice);
	void delete_event(string event_name);

	void save_users();
	void save_events();

	// use hash_table or array to do sort in tree not by .length() but by index of day
	// "monday" : 1, ...
	void print_events();
	void print_events_by_day(string day);
	void print_events_by_event_name(string event);


	void user_screen();
	void admin_screen();
public:
	MainScreen() {};
	void run();
};

