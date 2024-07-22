#include "map.h"
#include <iostream>

Map::Map() : name (""), mapNum(0) {}

Map::Map(const std::string& name, int mapNum)
    : name(name), mapNum(mapNum) {}
Map::~Map() {}

std::string Map::getName() const { return name; }
int Map::getMapNum() const { return mapNum; }
std::vector<std::vector<int>> Map::getMapData() const { return mapData; }

void Map::setName(const std::string& name) { this->name = name; }
void Map::setMapNum(int mapNum) { this->mapNum = mapNum; }
void Map::setDimension(const std::vector<std::vector<int>> mapData) {this->mapData = mapData;}

// void printMap() const;

// void loadMap(const std::string& filename);