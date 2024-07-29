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
    int startX;
    int startY;


public:
    Enemy();
    Enemy(const std::string& name, int health, std::vector<std::string>& reward, int startX, int startY);
    ~Enemy();

    std::string getName();
    int getHealth();
    std::vector<std::string> getReward();
    int getStartX();
    int getStartY();

    void setName(const std::string& name);
    void setHealth(int health);
    void setReward(std::vector<std::string> reward);
    void setX(int startX);
    void setY(int startY);

    void printEnemy();
};

#endif