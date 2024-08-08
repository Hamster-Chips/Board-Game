#ifndef CHECK_INPUT_H
#define CHECK_INPUT_H

#include <string>

//Check input 
    class CheckInput{

        public:

            CheckInput();
            ~CheckInput();

            int rangeInt(const std::string& text, int min, int max) const;
            bool yesNo(const std::string& text) const;
    };

#endif 