#pragma once
#include "User.h"
#include "EventTreeCollection.h"
#include "UserTreeCollection.h"
#include "Tools.h"
#include "sha256.h"

class MainScreen
{
private:
	EventTreeCollection* event_collection;
	UserTreeCollection* user_collection;
	User* user;

	void add_user(string username, string password);
	void print_users();
	void delete_user(string username);
	void change_access_level(string username);

	void add_admin(string username, string password);
	void print_admins();

	void add_event(string day, string time,
		string event, string name, string number);
	void change_event(Event* event);
	void delete_event(string event_name);

	void save_users();
	void save_events();

	void print_events();
	void print_events_by_day(string day);
	void print_events_by_event_name(string event);

	void user_screen();
	void admin_screen();

public:
	MainScreen() {};
	void run();
};

