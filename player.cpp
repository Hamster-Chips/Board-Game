#include "player.h"
#include <iostream>
#include <fstream>

using namespace std; 

Player::Player() : name(""), score(0), playerItems() {}

Player::Player(const string& name, int score, vector<int>& loc, const vector<string>& playerItems)
       : name(name), score(score), loc(loc), playerItems(playerItems) {};

Player::~Player() {}

string Player::getName() const { return name; }
int Player::getScore() const { return score; }
vector<string> Player::getPlayerItems() const { return playerItems; }
vector<int> Player::getLoc() const {return loc;}

void Player::setName(const string& name) { this->name = name; }
void Player::setScore(int score) { this->score = score; }
void Player::setPlayerItems(const vector<string>& items) { this-> playerItems = items;}
//void Player::setLoc(const vector<int>& _loc){this->loc = _loc;}

int Player::get_cur_map() const{
    return cur_map;
}

void Player::set_cur_map(int num){
    this->cur_map = num;
}

void Player::moveUp(){
    Map* map1 = Map::getInstance();
    if (loc[1]-1>=0)
    {
        this->loc[1] = loc[1]-1;
    }
    cout<< "You cannot go there."<<endl;

}


void Player::moveDown(){
    Map* map1 = Map::getInstance();
    if (loc[1]+1<=map1->getMapData().size()-1)
    {
        this->loc[1] = loc[1]+1;
    }
    cout<< "You cannot go there."<<endl;

}

void Player::moveLeft(){
    Map* map1 = Map::getInstance();
    if (loc[0]-1>=0)
    {
        this->loc[0] = loc[0]-1;
    }
    cout<< "You cannot go there."<<endl;

}
void Player::moveRight(){
    Map* map1 = Map::getInstance();
    if (loc[0]+1<=map1->getMapData().size()-1)
    {
        this->loc[1] = loc[1]+1;
    }
    cout<< "You cannot go there."<<endl;

}



void Player::add_items(const string& PlayerItems){


}


/*int main()
{
    vector<string> lays ({"BOO", "hi"});
    Player player1;
    player1.setName("Jorge");
    player1.setScore(0);
    player1.setPlayerItems(lays);
    player1.add_items("hi");

    cout << "player Name: " << player1.getName() << endl;
    cout << "player score: " << player1.getScore() << endl;
    cout << "player items: ";
    for (const string items: player1.getPlayerItems()){
        cout<< items << " ";
    }




    return 0; 

}*/