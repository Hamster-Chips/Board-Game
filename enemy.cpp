#include "enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy() : name (""), health (0)  {}
Enemy::Enemy(const std::string& name, int health, vector<string>& reward)
    : name(name), health(health), reward(reward) {}
Enemy::~Enemy(){}

string Enemy::getName() { return name; }
int Enemy::getHealth() { return health; }
std::vector<std::string> Enemy::getReward() { return reward; }

void Enemy::setName(const string& name) {this->name = name;}
void Enemy::setHealth(int health) { this-> health = health; }
void Enemy::setReward(std::vector<std::string> reward) { this->reward = reward; }

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