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
Commit's plan:
	1. finish 3rd lab
	2. separate interfaces
	3. This is bad plan
*/

#include "AuthScreen.h"
#include "db.cpp"

using namespace std;

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

int main()
{
	// auth_db has a straight access to files
	// AuthScreen* auth = new AuthScreen(new DataBase("auth.txt"));
	AuthScreen* auth = new AuthScreen(new DataBase("auth.txt"));
	// there is logic in run that works with auth_db field;
	User* user = auth->run();
	// the end of auth;

	//// collection gotta take the data from files(dataBase) that are related with user
	//// soo, we can make the name of the db as "db_"+"username"

	//Collection* collection = new Collection(new DataBase("task.txt"), user);
	//

	//MainScreen mainScreen = new MainScreen(collection, user);
	//// collection has access to dataBase which has access to files
	//mainScreen->run();

	/*
	Collection
	Task
	DataBase
	User
	Admin
	Auth
	*/


	



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




	return 0;
}