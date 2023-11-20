#include <iostream>
#include <fstream>
#include <string>
#include "Constants.h"

using namespace std;

class Task
{
private:
	string day;
	string time;
	string event;
	string fullname;
	string phone_number;
public:
	Task(string day, string time, string event,
		string fullname, string phone_number)
	{
		this->day = day;
		this->time = time;
		this->event = event;
		this->fullname = fullname;
		this->phone_number = phone_number;
	}
	string getDay()
	{
		return this->day;
	}
	void setDay(string day)
	{
		this->day = day;
	}
};



class DataBase
{
	string filename;

	void write_to_file()
	{
		ofstream file;
		file.open(this->filename);

		string data;
		cout << "Enter data" << endl;
		cin >> data;

		if (file.is_open())
		{
			file << data;
		}

		file.close();
	}

	string read_file()
	{
		/*ifstream file;
		file.open(this->filename);

		string line;
		if (file.is_open())
		{
			while (file)
			{
				getline(file, line);
				cout << line<<'\n';
			}
		}
		file.close();*/
		std::ifstream file;
		string data;
		file.open(this->filename);
		std::string line;
		if (file.is_open()) {
			while (getline(file, line)) { // equivalent to myfile.good()
				//std::cout << line << endl;
				data.append(line+'\n');
			}
		}
		else {
			std::cout << "Couldn't open file\n";
		}
		return data;
	}

	string* get_fields(string line)
	{
		string* fields = new string[5];

		size_t startPos_for_line = 0;
		size_t endPos_for_line = 0;
		int fieldIndex = 0;

		while ((endPos_for_line = line.find(';', startPos_for_line)) != std::string::npos && fieldIndex < 5)
		{
			std::string token = line.substr(startPos_for_line, endPos_for_line - startPos_for_line);
			fields[fieldIndex++] = token;
			startPos_for_line = endPos_for_line + 1;
		}
		return fields;
	}

	static string csv_to_verbose(string line)
	{
		// from CSV to verbose
		size_t pos;
		// .find() returns npos if there is no match
		while ((pos = line.find(';')) != std::string::npos) {
			line.replace(pos, 1, " ");
		}	
		return line;
	}
	// we have 2 ways to search
	// 1. Search in the file(iterate throw file)
	// 2. Search in string(itrate throw string)


	string search_by_criteria(string data, bool (*criteria)(string, string), int index, string pattern)
	{
		int const phone_field_index = index;
		int startPos = 0;
		int endPos = 0;
		string match = NO_MATCH;

		while ((endPos = data.find('\n', startPos)) != std::string::npos)
		{
			std::string line = data.substr(startPos, endPos - startPos);
			//std::cout << line << std::endl; 

			string* fields = get_fields(line);

			if (criteria(fields[index], pattern))
			{
				match = line;
				return csv_to_verbose(match);
			}

			startPos = endPos + 1;
		}
		return match;
	}

	static bool criteria_by_phone(string field, string phone_number)
	{
		if (phone_number == field) return true;
		else return false;
	}

	static bool criteria_by_event(string field, string event)
	{
		if (field.find(event) != string::npos) return true;
		else return false;
	}


	string search_by_event(string data)
	{
		return "";
		//int const phone_field_index = 2;
		//int startPos = 0;
		//int endPos = 0;
		//string match = NO_MATCH;

		//while ((endPos = data.find('\n', startPos)) != std::string::npos)
		//{
		//	std::string line = data.substr(startPos, endPos - startPos);
		//	// work with line

		//	string* fields = get_fields(line);

		//	if (phone_number == fields[phone_field_index])
		//	{
		//		match = csv_to_verbose(line);
		//	}
		//	//
		//	startPos = endPos + 1;
		//}
		//return match;
	}
	string search_by_secondname(string data)
	{
		return "";
	}
	string search_by_time(string data)
	{
		return "";
	}
	string search_by_day(string data)
	{
		return "";
	}
	string search_in_file()
	{
		int choice;
		string pattern;
		string buffer = NONE_DATA_STR;
		do
		{
			cout << "1.Search by phone number" << endl; // совпадение
			cout << "2.Search by event" << endl; // вхождение
			cout << "3.Search by secondname" << endl; // принадлежность к диапазону
			cout << "4.Search by time" << endl; // реализую как хочу
			cout << "5.Search by day" << endl; // принадлежность к диапазону
			cout << "0.Exit" << endl;

			cin >> choice;
			
			buffer = read_file();
			switch (choice)
			{
				case(1):
					cout << "Write a phone number" << endl;
					cin >> pattern;
					buffer = search_by_criteria(buffer, criteria_by_phone, 4, pattern);
					cout << "Matched data: " << endl << buffer << endl;
					break;
				case(2):
					cout << "Write an event" << endl;
					cin >> pattern;
					buffer = search_by_criteria(buffer, criteria_by_event, 2, pattern);
					cout << "Matched data: " << endl << buffer << endl;

					break;
				case(3):
					buffer = search_by_secondname(buffer);
					break;
				case(4):
					buffer = search_by_time(buffer);
					break;
				case(5):
					buffer = search_by_day(buffer);
					break;
				case(0):
					system("pause");
					exit(0);
					break;
				default:
					break;
			}
		} while (choice);
		return buffer;
	}

	//string* split_by_ch(string str, int fields)
	//{
	//	// 5 quantity of fields for Task class
	//	string* arr = new string[fields];
	//	string tmp;
	//	int start = 0;
	//	
	//	
	//}
public:
	DataBase(string filename)
	{
		this->filename = filename;
	}

	void initTask(Task* task)
	{

	}
	void menu()
	{
		int choice;
		do
		{
			cout << "1.Write to file" << endl;
			cout << "2.Read from file" << endl;
			cout << "3.Search in file" << endl;
			cout << "0.Exit" << endl;
			
			cin >> choice;
			// while ((getchar()) != '\n');
			string buffer;
		
			switch (choice)
			{
				case(1):
					write_to_file();
					break;
				case(2):
					buffer = read_file();
					cout << buffer << endl;
					break;
				case(3):
					buffer = search_in_file();
					cout << "Found data: \n" << buffer << endl;
					break;
				case(0):
					system("pause");
					exit(0);
					break;
				default:
					break;
			}
		} while (choice);
	}
};

