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

public:
    
    Map();
    Map(const std::string& name, int mapNum, const std::string& filename);
    ~Map();

    std::string getName() const;
    int getMapNum() const;
    int getWidthX() const;
    int getLengthY() const;
    std::vector<std::vector<char>> getMapData() const;

    void setName(const std::string& name);
    void setMapNum(int mapNum);
    void setDimension(const std::vector<std::vector<char>> mapData);
    
    void printMap() const;
    bool loadMap(const std::string& filename);
};

#endif