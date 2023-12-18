#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace Tools
{
    static int input_int()
    {
        string input;
        int value;
        while (true) {
            cin >> input;

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
}