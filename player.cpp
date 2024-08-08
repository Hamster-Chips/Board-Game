#include "player.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std; 

Player::Player() : name(""), score(0), items(), x(0), y(0) {}

Player::Player(const string& name, char symbol, int score, const vector<string>& playerItems, int x, int y)
       : name(name), symbol(symbol), score(score), items(playerItems), x(x), y(y) {};

Player::~Player() {}

string Player::getName() const { return name; }
char Player::getSymbol() const { return symbol; }
int Player::getScore() const { return score; }
vector<string> Player::getItems() const { return items; }
int Player::getX() const { return x; }
int Player::getY() const { return y; }

void Player::setName(const string& name) { this->name = name; }
void Player::setSymbol(const char symbol) { this->symbol = symbol; }
void Player::setScore(int score) { this->score = score; }
void Player::setPlayerItems(const vector<string>& items) { this->items = items;}
void Player::setX(int x) { this->x = x; }
void Player::setY(int y) { this->y = y; }

void Player::addItems(const string& item)
{
    items.push_back(item);
}

void Player::removeItems(const std::string& removedItem)
{
    auto it = std::find(items.begin(), items.end(), removedItem);
    if (it != items.end())
        items.erase(it);
}

void Player::printItems() const
{
    for (const string items: getItems())
        cout<< items << " ";
    cout << "\n";
}

void Player::printPlayer() const
{
    cout << name << " (" << symbol << ")" << endl; 
    cout << "   score: " << score << endl;

    cout << "   items: ";
    for(int i = 0; i < items.size(); i++)
    {
        cout << items[i] << " ";
    }
    cout << endl;

    cout << "   location (x, y) -> ";
    cout << "(" << x << ", " << y << ")" << endl;
}