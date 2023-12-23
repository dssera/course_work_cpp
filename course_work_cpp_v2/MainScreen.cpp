#include "MainScreen.h"
#include "Auth.h"


void MainScreen::run()
{
	do
	{
		UserDataBase* user_db = new UserDataBase("auth.txt");
		Auth* auth = new Auth(user_db);
		User* user = auth->run_auth_menu();

		UserTreeCollection* user_collection = new UserTreeCollection(user_db);
		EventTreeCollection* event_collection = new EventTreeCollection(user->get_username());

		// is it okey??
		this->user_collection = user_collection;
		this->event_collection = event_collection;
		this->user = user;

		if (user->is_admin()) admin_screen();
		else user_screen();

	} while (true);
}


// u did changes in collection and then save it
void MainScreen::save_users()
{
	this->user_collection->save_in_file();
}
void MainScreen::save_events()
{
	this->event_collection->save_in_file();
}
// отмена изменений??
// use hash_table or array to do sort in tree not by .length() but by index of day
// "monday" : 1, ...




