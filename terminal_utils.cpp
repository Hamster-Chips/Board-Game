#include <iostream>
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
    cout << "Press Enter to continue..." << endl;
    cin.get();
}

void delayPrint(const string& text, double delayTime = 0.04) {
    for (const char& c : text) {
        cout << c << flush;
        Sleep(static_cast<int>(delayTime * 1000));

    }
    cout << endl;
}

string delayInput(const string& text, double delayTime = 0.04) {
    delayPrint(text, delayTime);
    string input;
    getline(std::cin, input);
    return input;
}

void delay(double delayTime) {
    Sleep(static_cast<int>(delayTime * 1000));
}