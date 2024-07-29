#include "enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy() : name (""), health (0), startX (-1), startY (-1) {}
Enemy::Enemy(const std::string& name, int health, vector<string>& reward, int startX, int startY)
    : name(name), health(health), reward(reward), startX(startX), startY(startY) {}
Enemy::~Enemy(){}

string Enemy::getName() { return name; }
int Enemy::getHealth() { return health; }
std::vector<std::string> Enemy::getReward() { return reward; }
int Enemy::getStartX() { return startX; } 
int Enemy::getStartY() { return startY; }

void Enemy::setName(const string& name) {this->name = name;}
void Enemy::setHealth(int health) { this->health = health; }
void Enemy::setReward(std::vector<std::string> reward) { this->reward = reward; }
void Enemy::setX(int startX) { this->startX = startX; }
void Enemy::setY(int startY) { this->startY = startY; }

void Enemy::printEnemy()
{
    cout << name << " health: " << health << endl;

    cout << "rewards: ";
    for(int i = 0; i < reward.size(); i++)
    {
        cout << reward[i] << " ";
    }
    cout << endl;
}