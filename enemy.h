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
    int x;
    int y;

public:
    Enemy();
    Enemy(const std::string& name, int health, std::vector<std::string>& reward, int x, int y);
    ~Enemy();

    std::string getName();
    int getHealth();
    std::vector<std::string> getReward();
    int getX();
    int getY();

    void setName(const std::string& name);
    void setHealth(int health);
    void setReward(std::vector<std::string> reward);
    void setX(int X);
    void setY(int Y);

    void printEnemy();
};

#endif