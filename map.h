#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include "player.h"

class Map 
{
private:
    std::string name;
    //int mapNum;
    int widthX;
    int lengthY;
    std::vector<int> StartLoc;
    std::vector<int> FinishLoc;
    std::vector<std::vector<char>> mapData;
    std::vector<Player> Players;

public:
    
    Map();
    //Map(const std::string& name, int mapNum, const std::string& filename);
    Map(const std::string& name, int mapNum);
    Map(int mapNum);
    ~Map();

    std::vector<int> getStartLoc();
    std::vector<int> getFinishLoc();
    std::string getName() const;
    int getMapNum() const;
    int getWidthX() const;
    int getLengthY() const;
    std::vector<std::vector<char>> getMapData() const;

    void setName(const std::string& name);
    void setMapNum(int mapNum);
    


    void printMap(std::vector<Player>& Players);

    bool loadMap(int fileNum);
    char moveUp(Player& tempPlayer);
    char moveDown(Player& tempPlayer);
    char moveLeft(Player& tempPlayer);
    char moveRight(Player& tempPlayer);
};

#endif