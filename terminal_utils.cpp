#include <iostream>
#include "terminal_utils.h"
#include <windows.h>
#include <chrono>

using namespace std;


void clearTerminal() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    cout << "Press Enter to continue...\n" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void delayPrint(const string& text, double delayTime) {
    for (const char& c : text) {
        cout << c << flush;
        Sleep(static_cast<int>(delayTime * 1000));

    }
    cout << endl;
}

string delayInput(const string& text, double delayTime) {
    delayPrint(text, delayTime);
    string input;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);
    return input;
}

void delay(double delayTime) {
    Sleep(static_cast<int>(delayTime * 1000));
}