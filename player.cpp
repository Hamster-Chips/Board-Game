#include "player.h"
#include <iostream>
#include <fstream>

using namespace std; 

Player::Player() : name(""), score(0) {}

Player::Player(const string& name, int score, const std::string& playerItems)
       : name(name), score(score) {};

Player::~Player() {}

string Player::getName() const { return name; }
int Player::getScore() const { return score; }
//vector<vector<char>> Player::getPlayerItems() const { return playerItems; }

void Player::setName(const string& name) { this->name = name; }
void Player::setScore(int score) { this->score = score; }
//void Player::setDimension(const vector<vector<char>> playerItems) { this->playerItems = playerItems; }
