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

#include <iostream>

#define MENU_STRING "todo-app menu"
#define SIGN_UP "sign up"
#define SIGN_IN "sign in"

#define PLUG "plug"

#define ADMIN_ACCESS_LEVEL "admin_level"
#define USER_ACCESS_LEVEL "user_level"

using namespace std;

class BaseUser
{
public:
	string username;
	string password;
	bool is_authenticated;

protected:
	BaseUser(string username, string password)
	{
		// add validation
		this->username = username;
		this->password = password;
	}
};

class User : public BaseUser
{
	string access_level;

	void set_access_level(string access_level)
	{
		this->access_level = access_level;
	}
public:
	User(string username, string password, string access_level = USER_ACCESS_LEVEL)
		: BaseUser(username, password)
	{
		this->access_level = access_level;
	}

	string get_access_level()
	{
		return this->access_level;
	}
};


class AuthScreen
{
public:
	User* run()
	{
		User* user = nullptr;
		do
		{
			user = auth_menu();
		} while (user == nullptr);

		return user;
	}
protected:
	User* sign_in()
	{
		string username;
		string password;
		cout << "Enter username" << endl;
		cout << "Enter paswword" << endl;
		cin >> username;
		cin >> password;

		User* user = auth(username, password);
		return user;
	}

	User* sign_up()
	{
		cout << "Create new user" << endl;
		string username, password;
		cout << "Enter username" << endl;
		cin >> username;
		cout << "Enter paswword" << endl;
		cin >> password;
		//password validation

		User* user_from_db = new User("user1", "password");

		//add user in db or raise an error
		//and then retutn pointer on gotten user
		return user_from_db;
	}

	void identificate(string username)
	{
		// вообще то здесь мы должны чекнуть есть ли наше имя в БД
		// get_username

		// видит ли эта функция this?
		// if (PLUG != username)
		if ("dssera" != username)
			throw exception("identification error: \
				bool identificate(string username)");
	}

	User* auth(string username, string password)
	{
		// signature will be changed when you add try-catch, you need to return smth to show that user is not authenticated 
		// but you don't want to close all application
		identificate(username);
		// get_password
		//string password_from_db = PLUG;
		string password_from_db = "12345";
		if (password_from_db != password)
		{
			// this->is_authenticated = false;
			throw exception("auth error : \
				bool auth(string username, string password)");
		}
		
		User* user_from_db = new User("name1", "password");
		return user_from_db;
		// this->is_authenticated = true;
	}
	User* auth_menu()
	{
		bool authenticated;
		int enter;
		User* user = nullptr;
		cout << "Auth Menu" << endl << "1.Sign In" << endl 
			<< "2.Sign Up" << endl << "0.Exit" << endl;
		

		cout << "Your enter: ";
		cin >> enter;

		switch (enter)
		{
		case(1):
			cout << SIGN_IN << endl;
			// user = sign_in();
			user = sign_in();
			break;
		case(2):
			cout << SIGN_UP << endl;
			user = sign_up();
			break;
		case(0):
			system("exit");
			break;
		default:
			break;
		}
		return user;
	}
};



int main()
{
	/*
	AuthScreen obj;
	obj.CheckOut(); 
	*/
	// сейчас у меня эта тема рабоатет череез функцию auth_menu
	AuthScreen* auth_obj = new AuthScreen();;
	User* user = auth_obj->run();

	if (user->get_access_level() == ADMIN_ACCESS_LEVEL)
	{
		cout << ADMIN_ACCESS_LEVEL << endl;
	}
	else if (user->get_access_level() == USER_ACCESS_LEVEL)
	{
		cout << USER_ACCESS_LEVEL << endl;

	}


	return 0;
}