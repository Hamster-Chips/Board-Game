#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <vector>
#include "player.h"
#include "map.h"


class Enemy
{
private:
    std::string name;
    char symbol;
    int health;
    std::vector<std::string> reward;
    int x;
    int y;

public:
    Enemy();
    Enemy(const std::string& name, const char symbol, int health, std::vector<std::string>& reward, int x, int y);
    ~Enemy();

    std::string getName();
    char getSymbol();
    int getHealth();
    std::vector<std::string> getReward();
    int getX();
    int getY();

    void setName(const std::string& name);
    void setSymbol (const char symbol);
    void setHealth(int health);
    void setReward(std::vector<std::string>& reward);
    void setX(int X);
    void setY(int Y);

    void printEnemy();
    void bfs(const std::vector<std::vector<char>>& mapData ,const std::vector<Player>& player);
    void targetPlayer(const std::vector<Player>& players);
};

#endif