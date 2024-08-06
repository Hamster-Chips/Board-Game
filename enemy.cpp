#include "enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy() : name(""), health(0), x(-1), y(-1) {}
Enemy::Enemy(const std::string& name, int health, vector<string>& reward, int x, int y)
    : name(name), health(health), reward(reward), x(x), y(y) {}
Enemy::~Enemy(){}

string Enemy::getName() { return name; }
int Enemy::getHealth() { return health; }
std::vector<std::string> Enemy::getReward() { return reward; }
int Enemy::getX() { return x; } 
int Enemy::getY() { return y; }

void Enemy::setName(const string& name) {this->name = name;}
void Enemy::setHealth(int health) { this->health = health; }
void Enemy::setReward(std::vector<std::string> reward) { this->reward = reward; }
void Enemy::setX(int x) { this->x = x; }
void Enemy::setY(int y) { this->y = y; }

void Enemy::printEnemy()
{
    cout << name << endl; 
    cout << "   health: " << health << endl;

    cout << "   rewards: ";
    for(int i = 0; i < reward.size(); i++)
    {
        cout << reward[i] << " ";
    }
    cout << endl;

    cout << "   location (x, y) -> ";
    cout << "(" << x << ", " << y << ")" << endl;
    
}