#include "player.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include "map.h"

using namespace std; 

Player::Player() : name(""), score(0), playerItems(), playerLoc({0,0}){};

Player::Player(const string& name, int score, const vector<string>& playerItems)
       : name(name), score(score), playerItems(playerItems) 
    {
        //added for map class functionality
        this->playerLoc = {0,0};
    };

Player::~Player() {}

string Player::getName() const { return name; }
int Player::getScore() const { return score; }
vector<string> Player::getPlayerItems() const { return playerItems; }

void Player::setName(const string& name) { this->name = name; }
void Player::setScore(int score) { this->score = score; }
void Player::setPlayerItems(const vector<string>& items) { this-> playerItems = items;}

void Player::add_items(const string& PlayerItems){
    playerItems.push_back(PlayerItems);
}

void Player::remove_items(const std::string& items){
    auto it = std::find(playerItems.begin(), playerItems.end(), items);
    if (it != playerItems.end()) {
        playerItems.erase(it);
    }
}


//added for map class functionality
std::vector<int> Player::getPlayerLoc(){
    return playerLoc;
}

//added for map class functionality
void Player::setPlayerLoc(std::vector<int> newLoc){
    this-> playerLoc = newLoc;
    std::cout << "playerLoc[1]: " << playerLoc[1] << endl;
}