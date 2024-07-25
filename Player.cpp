
#include <iostream> 
using namespace std;
#include "Player.h"
#include <string>
using namespace std;



//default constructor
Player::Player(){
    _name = "";
    _score = 0;
    _items = {};
}

//setter & getter for player name
void Player:: set_name(string name){
    _name = name;
}

string Player::get_name(){
    return _name;
}


//setter & getter for player score
void Player::set_score(int score){
    _score = score;
}

int Player::get_score(){
    return _score;
}

void Player::add_items(string item){
    _items.push_back(item);
}

ostream& operator<<(ostream& out, Player P1){
    //cout << "YOOOOO" << endl;
    out << "Player: " << P1._name << "\n"<< "Score: " << P1._score << "\n" << "Items: ";

    //cout << P1._items.size() << endl;
    for (int i = 0; i < P1._items.size(); i++){
        
        if (i < P1._items.size()-1){
            out << P1._items[i] << ", " ;
        } else {
            out << P1._items[i] << endl;
        }
    }

    return out;
    }






//FIX CODE SO IT CAN PRINT MULTIPLE PLAYERS and print items from item vector






int main(){
    //test
    Player mclaren = Player();
    mclaren.set_name("Mac");
    mclaren.set_score(1000);
    mclaren.add_items("MP4-12C");
    
    Player lebron = Player();
    lebron.set_name("James");
    lebron.set_score(23);

    
    lebron.add_items("legoat");
    lebron.add_items("BRONBRON");


    //cout << mclaren << endl;
    cout << lebron << endl;
    cout << mclaren << endl;
}