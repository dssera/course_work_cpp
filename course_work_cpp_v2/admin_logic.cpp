#include "MainScreen.h"

// create
void MainScreen::add_user(string username, string password)
{
	User* user = new User(username, password);
	this->user_collection->insert(user);
	save_users();
}

// read
void MainScreen::print_users()
{
	this->user_collection->print();
}

// update
void MainScreen::change_access_level(string username)
{
	User* user = this->user_collection->find(username);
	if (!user)
	{
		cout << "User with this username doesn't exist" << endl;
		return;
	}
	cout << "Set new level access(admin: 1, user: 0):" << endl;
	int access_level = Tools::input_int();
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
	else
	{
		cout << "Wrong input!!" << endl;
		return;
	}
	save_users();
}

// delete
void MainScreen::delete_user(string username)
{
	this->user_collection->remove(username);
	save_users();
}

void MainScreen::add_admin(string username, string password)
{
	User* user = new User(username, password, 1);
	this->user_collection->insert(user);
	save_users();
}
void MainScreen::print_admins()
{
	this->user_collection->print_admins();
}
