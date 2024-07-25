#ifndef PLAYER_H
#define PLAYER_H


#include <vector>
#include <string>
using namespace std;


// create 
    class Player{

        public:
            Player();
            void set_name(string n);
            string get_name();
            void set_score(int score);
            int get_score();
            void add_items(string item);

            friend ostream& operator<<(ostream&, Player P1);



        private:
            string _name;
            int _score;
            vector <string> _items;    

    };






#endif