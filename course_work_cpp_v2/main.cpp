/*
8. Разработка программы «Записная книжка-еженедельник»
Программа предоставляет возможность ведения записной книжки, в которой хранится информация о недельных мероприятиях. Наименование полей: день недели, время суток, название мероприятия, контактное лицо (Ф.И.О), телефон.
Реализовать авторизацию для входа в систему, функционал администратора и функционал пользователя.
Функционал администратора предусматривает возможность работы с пользователями, а также возможность редактирования данных (вставка новой записи, удаление заданной записи, редактирование заданной записи, сохранение изменений в файл, отмена изменений).
Функционал пользователя включает индивидуальное задание:
1.1 Вывести общую информацию, отсортированную по дням недели (тип сортировки - пузырьковая).
1.2 Вывести список мероприятий для заданного дня недели (вводится пользователем с клавиатуры).
1.3 Предусмотреть поиск информации по названию мероприятия (вхождение).
+архивация
+шифровка
*/

//classes
/*
Task-> TaskTree
adminScreen (<-)-> userScreen
Auth
User
Menu(screen)

1. Auth obj is created
2. User Screen or Admin Screen is created (Auth obj can be deleted)

Следи за временем жизни объектов

-> User - >work with tasks
start -> auth -|
-> Admin -> work with db + work with users


*/

/*
1. Auth [done]
2. File System [undone]
3. Container [undone]
4. Main Functionality [undone]
5. other [undone]
*/

/*
PLaaan::
	1.Fix user's access problem (1 in the file but it's not an admin)


	here you have finished auth and user_db
	other things:
	1) Tree: 30 minutes
	2) TaskDataaBase 2h
	3) MainScreen 2h
	// Получается за 4.5 часа можешь закончить


*/

#include "Auth.h"
#include "db.h"
#include "Container.h"
#include "MainScreen.h"
#include <iterator>

//void task_for_lab()
//{
//	string a = "ak";
//	string b = "dmsdsd";
//
//	string x = "b";
//	int x_len = 14;
//	string sub_a = a;
//	int a_len = 9;
//	cout << sub_a.length() << endl;
//	for (size_t i = 0; i < x_len - a_len; i++)
//	{
//		sub_a.append(" ");
//	}
//	cout << sub_a.length() << endl;
//
//	int count = 0;
//	for (size_t i = 0; i < x.length(); i++)
//	{
//		if (int(x[i]) > int(sub_a[i]) && int(x[i]) < int(b[i]))
//		{
//			count++;
//		}
//	}
//	cout << "count: " << count << endl;
//}

string* tokenize_string(string line, char token)
{
	// read about stringstream
	int size = 5;
	string* tokens = new string[size];

	stringstream ss(line);
	string item;

	ss.clear();
	ss.seekg(0, ios::beg);


	for (size_t i = 0; i < size; i++)
	{
		getline(ss, item, token);
		tokens[i] = item;
	}
	return tokens;
}
int main()
{
	// add user_logic.cpp and amdin_logic.cpp

	MainScreen* main_screen = new MainScreen();
	main_screen->run();
	/*TaskDataBase db("task_db.txt", "user");
	Event* events = db.get_tasks();
	
	for (size_t i = 0; i < db.get_event_count(); i++)
	{
		cout << events[i].get_day() << endl << events[i].get_event_name() << endl;
		system("pause");
	}*/

	/*string* arr = tokenize_string("123;123;124;34tgfd;34", ';');
	string* usernames = db.get_usernames();
	cout << usernames[0] << endl;*/
	// to iterate via this array u can add std::npos to the end
	/*for (size_t i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}*/
	//UserDataBase db("auth.txt");

	//std::string** arr = db.get_usernames(); // получение массива строк
	//cout << endl;
	//int i = 0;
	//while (arr[i] != nullptr)
	//{
	//	cout << *arr[i]<< arr[i]->size() << endl;
	//	i++;
	//}
    return 0;
}






/*setconsolecp(1251);
	setconsoleoutputcp(1251);
	tree* tree = new tree(task("12345"));
	task task("1234");
	tree->insert(task);
	cout << tree->root->left->data.get_day() << endl;
	cout << tree->root->right->data.get_day() << endl;*/




	// solve problem with giving amdin statuc
	// solve problem with registration 
	//		read how are registation and auth related


	//// auth_db has a straight access to files
	//Auth* auth = new Auth(new UserDataBase("auth.txt"));
	//
	//// there is logic in run that works with auth_db field;
	//User* user = auth->run_auth_menu();
	//cout << "Your username: " << user->username << endl <<
	//	"Your password: " << user->password<< endl;


	/*cout << user->get_access_level() << endl;
	if (user->get_access_level() == 1)
	{
		cout << "You are admin!" << endl;
	}
	else {
		cout << "You are not admin" << endl;
	}*/


	//// collection gotta take the data from files(dataBase) that are related with user
	//// soo, we can make the name of the db as "db_"+"username"

	//Container* collection = new Container(new TaskDataBase("task.txt"), user);


	//MainScreen mainScreen = new MainScreen(collection, user);
	//// collection has access to dataBase which has access to files
	//mainScreen->run();













	/*string str1 = "qwer";
	string str2 = "qwertyui";

	string* arr = new string[2];
	arr[0] = str1;
	arr[1] = str2;

	cout << arr[0] << endl << arr[1] << endl;*/






	/*
	AuthScreen obj;
	obj.CheckOut();
	*/

	/*AuthScreen* auth_obj = new AuthScreen();
	User* user = auth_obj->run();

	if (user->get_access_level() == ADMIN_ACCESS_LEVEL)
	{
		cout << ADMIN_ACCESS_LEVEL << endl;
	}
	else if (user->get_access_level() == USER_ACCESS_LEVEL)
	{
		cout << USER_ACCESS_LEVEL << endl;

	}*/



