#ifndef TERMINAL_UTILS_H
#define TERMINAL_UTILS_H


#include <vector>
#include <string>

//terminal utils
    class TerminalUtils{

        public:

            TerminalUtils();
            ~TerminalUtils();

            void clear_terminal() const ;
            void pause() const ;
            void delay_print(const std::string& text, double delay = 0.04) const;
            std::string delay_input(const std::string& text, double delay = 0.04) const;
            void delay(double delay = 0.01) const; 
    };

#endif