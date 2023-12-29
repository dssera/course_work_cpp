#pragma once
#include <iostream>
#include <string>
#include <regex>

using namespace std;

namespace Tools
{
    static int input_int()
    {
        string input;
        int value;
        while (true) {
            cin >> input;
            cin.ignore();

            try {
                value = stoi(input);
                break;
            }
            catch (invalid_argument) {
                cout << "Invalid input. Please enter an integer: ";
            }
            catch (out_of_range) {
                cout << "Input out of range. Please enter an integer: ";
            }
        }
        return value;
    }
    static string input_str()
    {
        string var;
        getline(cin, var);
        return var;
    }
    static string enter_day()
    {
        string input;
        while (true) {
            cin >> input;
            cin.ignore();
            string days[14] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday",
                                "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
            int isDay = false;
            for (int i = 0; i < 14; i++)
            {
                if (input == days[i]) isDay = true;
            }
            if (isDay) break;
            cout << "Invalid input. Enter day: ";
        }
        return input;
    }
    static string enter_time()
    {
        string input;
        while (true) {
            cin >> input;
            cin.ignore();
            regex rx{ R"(^(?:[01]\d|2[0-3]):[0-5]\d$)" };
            if (regex_match(input, rx)) break;
            cout << "Invalid input. Enter time as HH:MM: ";
        }
        return input;
    }
    static string enter_number()
    {
        string input;
        while (true) {
            cin >> input;
            cin.ignore();
            regex rx{ R"(^\+\d{1,3}(?:[-\s]?\d{2,3}){3}(?:[-\s]?\d{2})$)" };
            if (regex_match(input, rx)) break;
            cout << "Invalid input. Enter valid number: ";
        }
        return input;
    }
    static string enter_names()
    {
        string input;
        while (true) {
            cin >> input;
            cin.ignore();
            regex rx("^([a-zA-Z]+)(,[a-zA-Z]+)*$");
            if (regex_match(input, rx)) break;
            cout << "Invalid input. Enter valid name(s): ";
        }
        return input;
    }
    static string enter_event_name()
    {
        string input;
        while (true) {
            cin >> input;
            cin.ignore();
            regex rx("^[a-zA-Z]+$");
            if (regex_match(input, rx)) break;
            cout << "Invalid input. Enter valid event name: ";
        }
        return input;
    }
    static string enter_username()
    {
        string input;
        while (true) {
            cin >> input;
            cin.ignore();
            std::regex rx("^[a-zA-Z0-9_-]+$");
            if (regex_match(input, rx)) break;
            cout << "Invalid input. Enter valid username: ";
        }
        return input;
    }
    static string enter_password()
    {
        string password;
        do
        {
            password = Tools::input_str();
            if (password.length() <= 4)
            {
                cout << "!!Password can't be less than 5 characters. Enter other one:" << endl;
                continue;
            }
            break;

        } while (true);
        return password;
    }
}