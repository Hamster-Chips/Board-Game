#include "player.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std; 

Player::Player() : name(""), score(0), playerItems(), locX(0), locY(0) {}

Player::Player(const string& name, int score, const vector<string>& playerItems)
       : name(name), score(score), playerItems(playerItems) {};

Player::~Player() {}

string Player::getName() const { return name; }
int Player::getScore() const { return score; }
vector<string> Player::getPlayerItems() const { return playerItems; }

void Player::setName(const string& name) { this->name = name; }
void Player::setScore(int score) { this->score = score; }
void Player::setPlayerItems(const vector<string>& items) { this->playerItems = items;}

void Player::addItems(const string& PlayerItems)
{
    playerItems.push_back(PlayerItems);
}

void Player::removeItems(const std::string& items)
{
    auto it = std::find(playerItems.begin(), playerItems.end(), items);
    if (it != playerItems.end())
        playerItems.erase(it);
}

//  bool Player::move(Map currMap, const int direction)
//  {
//     /*
//         1. Move Up
//         2. Move Down
//         3. Move Left
//         4. Move Right
//     */
//     int maxX = currMap.getWidthX();
//     int maxY = currMap.getLengthY();

//     switch (direction)
//     {
//         case 1:
//             if (locY == 0)
//                 return false;
//             --locY;
//             break;
//         case 2:
//             if (locY == maxY)
//                 return false;
//             ++locY;
//             break;
//         case 3:
//             if (locX == 0)
//                 return false;
//             --locX;
//             break;
//         case 4:
//             if (locX == maxX)
//                 return false;
//             ++locX;
//             break;
//     }

//     cout << locX << ", " << locY << endl;
//     return true;

//  }

void Player::printItems() const
{
    for (const string items: getPlayerItems())
        cout<< items << " ";
    cout << "\n";
}
