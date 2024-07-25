#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <vector>

class Enemy
{
private:
    std::string name;
    int health;
    std::vector<std::string> reward;

public:
    Enemy();
    Enemy(const std::string& name, int health, std::vector<std::string>& reward);
    ~Enemy();

    std::string getName();
    int getHealth();
    std::vector<std::string> getReward();

    void setName(const std::string& name);
    void setHealth(int health);
    void setReward(std::vector<std::string> reward);

    void printEnemy();

};

#endif