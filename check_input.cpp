#include <iostream>
#include "check_input.h"
#include <limits>
#include <string>
#include <algorithm>


using namespace std;


int rangeInt(const string& text, int min, int max) {
    int num = 0;
    bool valid = false;

    while (!valid) {
        cout << text;
        cin >> num;

        if (cin.fail()) {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            cout << "Input should be an integer." << endl;
        } else if (num >= min && num <= max) {
            valid = true;
        } else {
            cout << "Invalid input - it should be within " << min << " - " << max << "." << endl;
        }
    }

    return num;
}

bool yesNo(const string& text) {
    string input;
    bool valid = false;

    while (!valid) {
        cout << text;
        getline(cin, input);

        transform(input.begin(), input.end(), input.begin(), ::toupper);

        if (input == "YES" || input == "Y") {
            return true;
        } else if (input == "NO" || input == "N") {
            return false;
        } else {
            cout << "Invalid input, should be `y` or `n`" << endl;
        }
    }
    return false;  
}
