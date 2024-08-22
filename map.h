#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "player.h"
#include "enemy.h"

class Map 
{
private:
    std::string name;
    int mapNum;
    int widthX;
    int lengthY;
    std::vector<std::vector<char>> mapData;
    std::vector<Player>& players;
    std::vector<Enemy>& enemies;

public:
    // Map();
    Map(const std::string& name, int mapNum, const std::string& filename, std::vector<Player>& players, std::vector<Enemy>& enemies);
    ~Map();

    std::string getName() const;
    int getMapNum() const;
    int getWidthX() const;
    int getLengthY() const;
    std::vector<std::vector<char>> getMapData() const;
    std::vector<Player> getPlayers() const;
    std::vector<Enemy> getEnemy() const;

    void setName(const std::string& name);
    void setMapNum(int mapNum);
    void setMapData(const std::vector<std::vector<char>>& mapData);
    void setPlayers(const std::vector<Player>& newPlayers);
    void setEnemies(const std::vector<Enemy>& newEnemies);

    void getAssets(int numOfPlayers, std::string fileName);

    void printMap() const;
    bool loadMap(const std::string& filename);
};


#endif