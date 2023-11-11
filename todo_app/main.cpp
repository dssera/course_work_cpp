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
private:
	string username;
	string password;
	bool is_authenticated;

	void identificate()
	{
		// вообще то здесь мы должны чекнуть есть ли наше имя в БД
		// get_username

		// видит ли эта функция this?
		if (PLUG != this->username)
			throw exception("identification error: \
				bool identificate(string username)");
	}
protected:
	BaseUser(string username, string password)
	{
		// add validation
		// add saving in file
		this->username = username;
		this->password = password;
	}

	
public:
	void auth()
	{
		// signature will be changed when you add try-catch, you need to return smth to show that user is not authenticated 
		// but you don't want to close all application
		identificate();
		// get_password
		string password_from_db = PLUG;
		if (password_from_db != this->password)
		{
			this->is_authenticated = false;
			throw exception("auth error : \
				bool auth(string username, string password)");
		}
		this->is_authenticated = true;
	}
	bool is_authenticated()
	{
		return this->is_authenticated;
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
	User(string username, string password, string access_level=USER_ACCESS_LEVEL)
		: BaseUser(username, password)
	{
		this->access_level = access_level;
	}

	string get_access_level()
	{
		return this->access_level;
	}

};

// should I make this func like bool sign_in() or void sign_in()
void sign_in()
{
	string username;
	string password;
	cout << "Enter username" << endl;
	cout << "Enter paswword" << endl;
	cin >> username;
	cin >> password;

	User user = User(username, password);
	user.auth();
}

void sign_up()
{
	cout << "Create new user" << endl;
	string username;
	string password;
	cout << "Enter username" << endl;
	cout << "Enter paswword" << endl;
	cin >> username;
	cin >> password;
	//password validation

	//add user in db or raise an error
}



void print_menu()
{
	cout << MENU_STRING << endl;
	cout << "1." << SIGN_UP << endl;
	cout << "2." << SIGN_IN << endl;
}


// можно завязать всю работу авторизации и регистрации на поинтере user 
void auth_menu(int enter)
{
	bool authenticated;
	User* user = nullptr;
	switch (enter)
	{
	case(1):
		cout << SIGN_IN << endl;
		// user = sign_in();
		sign_in();
		break;
	case(2):
		cout << SIGN_UP << endl;
		sign_up();
		break;
	case(0):
		system("exit");
		break;
	default:
		break;
	}
}

int main()
{
	int enter;
	do
	{
		print_menu();
		cout << "Your enter: ";
		cin >> enter;
		auth_menu(enter);

		system("cls");
	} while (enter);

	return 0;
}