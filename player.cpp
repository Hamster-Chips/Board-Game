#include "player.h"
#include <iostream>
#include <fstream>

using namespace std; 

Player::Player() : name(""), score(0), playerItems() {}

Player::Player(const string& name, int score, const std::vector<std::string>& playerItems)
       : name(name), score(score), playerItems(playerItems) {};

Player::~Player() {}

string Player::getName() const { return name; }
int Player::getScore() const { return score; }
vector<string> Player::getPlayerItems() const { return playerItems; }

void Player::setName(const string& name) { this->name = name; }
void Player::setScore(int score) { this->score = score; }
void Player::setPlayerItems(const vector<string>& items) { playerItems = playerItems;}

