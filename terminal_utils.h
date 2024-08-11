#ifndef TERMINAL_UTILS_H
#define TERMINAL_UTILS_H

#include <string>

void clearTerminal();
void pause();
void delayPrint(const std::string& text, double delayTime = 0.04);
std::string delayInput(const std::string& text, double delayTime = 0.04);
void delay(double delayTime = 5);

#endif