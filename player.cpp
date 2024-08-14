#include "player.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include "map.h"

using namespace std; 

Player::Player() : name(""), score(0), playerItems(), playerLoc({0,0}), x(), y(){};

Player::Player(const string& name, int score, const vector<string>& playerItems, int x, int y)
       : name(name), score(score), playerItems(playerItems), x(x), y(y) 
    {
        //added for map class functionality
        this->playerLoc = {0,0};
    };

Player::~Player() {}

string Player::getName() const { return name; }
int Player::getScore() const { return score; }
vector<string> Player::getPlayerItems() const { return playerItems; }
int Player::getX() { return x; } 
int Player::getY() { return y; }



void Player::setName(const string& name) { this->name = name; }
void Player::setScore(int score) { this->score = score; }
void Player::setPlayerItems(const vector<string>& items) { this-> playerItems = items;}
void Player::setX(int x) { this->x = x; }
void Player::setY(int y) { this->y = y; }

void Player::addItems(const string& PlayerItems){
    playerItems.push_back(PlayerItems);
}

void Player::removeItems(const string& items){
    auto it = std::find(playerItems.begin(), playerItems.end(), items);
    if (it != playerItems.end()) {
        playerItems.erase(it);
    }
}

void Player::printItems() const{
    for (const string items: getPlayerItems()){
        cout<< items << " ";
    }
    cout << "\n";
}


// int main()
// {
//     vector<string> lays ({"BOO", "hi"});
//     Player player1;
//     player1.setName("Jorge");
//     player1.setScore(0);
//     player1.setPlayerItems(lays);
//     player1.addItems("doo");
//     player1.removeItems("hi");
//     player1.printItems();

//     cout << "player Name: " << player1.getName() << endl;
//     cout << "player score: " << player1.getScore() << endl;
//     cout << "player items: ";
//     //for (const string items: player1.getPlayerItems()){
//     //    cout<< items << " ";
//     //}




//     return 0; 

// }

//added for map class functionality
std::vector<int> Player::getPlayerLoc(){
    return playerLoc;
}

//added for map class functionality
void Player::setPlayerLoc(std::vector<int> newLoc){
    this-> playerLoc = newLoc;
    std::cout << "playerLoc[1]: " << playerLoc[1] << endl;
}
