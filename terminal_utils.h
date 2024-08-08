#ifndef TERMINAL_UTILS_H
#define TERMINAL_UTILS_H


#include <string>

//terminal utils
    class TerminalUtils{

        public:

            TerminalUtils();
            ~TerminalUtils();

            void clearTerminal() const ;
            void pause() const ;
            void delayPrint(const std::string& text, double delay = 0.04) const;
            std::string delayInput(const std::string& text, double delay = 0.04) const;
            void delay(double delay = 0.01) const; 
    };

#endif