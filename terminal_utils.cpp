#include "terminal_utils.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

TerminalUtils::TerminalUtils() {}
TerminalUtils::~TerminalUtils() {}

void TerminalUtils::clearTerminal() const {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void TerminalUtils::pause() const {
    cout << "Press Enter to continue..." << endl;
    cin.get();
}

void TerminalUtils::delayPrint(const string& text, double delay = 0.04) const{
    for (const char& c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(static_cast<int>(delay * 1000)));

    }
    cout << endl;
}

string TerminalUtils::delayInput(const string& text, double delay = 0.04) const{
    delayPrint(text, delay);
    string input;
    getline(std::cin, input);
    return input;
}

void TerminalUtils::delay(double delay) const {
    this_thread::sleep_for(chrono::milliseconds(static_cast<int>(delay * 1000)));
}