#ifndef _ALEYNIK_FUNCTION_H_
#define _ALEYNIK_FUNCTION_H_

#include <string>
#include <iostream>
using namespace std;

int a = 0, b = 0;

bool userInput(string input, const int& min, const int& max) {
    if (input.empty()) return false;
    for (char ch : input) {
        if (!isdigit(ch)) return false;
    }
    try {
        int number = stoi(input);
        if (number < min) {
            cout << "Minimum valid number is " << min << endl;
            return false;
        } else if (number > max) {
            cout << "Maximum valid number is " << max << endl;
            return false;
        }
    } catch (const exception& e) {return false;};
    return true;
}

void enterNumber(int& variable, const string& prompt, const int& min, const int& max) {
    string input;
    cout << prompt;
    getline(cin, input);

    while(!(userInput(input, min, max))) {
        cout << prompt;
        getline(cin, input);
    }
    variable = stoi(input);
}

void enterA() {
    enterNumber(a, "Enter x: ", 0, 1000);
}

void enterB() {
    enterNumber(b, "Enter n: ", 0, 1000);
}

void addition() {
    int result;
    result = a + b;
    cout << "Result: " << result << endl;
}

void subtraction() {
    int result;
    result = a - b;
    cout << "Result: " << result << endl;
}

#endif //ALEYNIK_FUNCTION_H_
