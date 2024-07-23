#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

class Map 
{
private:
    std::string name;
    int mapNum;
    std::vector<std::vector<int>> mapData;

public:
    Map();
    Map(const std::string& name, int mapNum);
    ~Map();

    std::string getName() const;
    int getMapNum() const;
    std::vector<std::vector<int>> getMapData() const;

    void setName(const std::string& name);
    void setMapNum(int mapNum);
    void setDimension(const std::vector<std::vector<int>> mapData);

    void printMap() const;
    bool loadMap(const std::string& filename);


};

#endif