#include "MainScreen.h"

// create
void MainScreen::add_user(string username, string password)
{
	User* user = new User(username, password);
	this->user_collection->insert(user);
}

// read
void MainScreen::print_users()
{
	this->user_collection->print();
}

// update
void MainScreen::change_access_level(int access_level, string username)
{
	User* user = this->user_collection->find(username);
	if (access_level == 1)
	{
		if (user->is_admin() == 1) cout << "This user is already an admin" << endl;
		else user->set_access_level(1);
	}
	else if (access_level == 0)
	{
		if (user->is_admin() == 0) cout << "This user is already not an admin" << endl;
		else user->set_access_level(0);
	}
}

// delete
void MainScreen::delete_user(string username)
{
	this->user_collection->remove(username);
}

void MainScreen::add_admin(string username, string password)
{
	User* user = new User(username, password, 1);
	this->user_collection->insert(user);
}
void MainScreen::print_admins()
{
	this->user_collection->print_admins();
}
void MainScreen::delete_admin(string username)
{
	// add validations
	this->user_collection->remove(username);
}