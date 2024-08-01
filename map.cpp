#include "map.h"
#include <iostream>
#include <fstream>

using namespace std;

Map::Map() : name (""), mapNum(0) {}

Map::Map(const string& name, int mapNum, const std::string& filename)
    : name(name), mapNum(mapNum) { loadMap(filename); }

Map::~Map() {}

string Map::getName() const { return name; }
int Map::getMapNum() const { return mapNum; }
vector<vector<char>> Map::getMapData() const { return mapData; }
int Map::getWidthX() const { return widthX; }
int Map::getLengthY() const { return lengthY; }

void Map::setName(const string& name) { this->name = name; }
void Map::setMapNum(int mapNum) { this->mapNum = mapNum; }
void Map::setDimension(const vector<vector<char>> mapData) { this->mapData = mapData; }

void Map::printMap() const
{
    cout << widthX << ", " << lengthY << endl;
    for (const vector<char>& row : mapData)
    {
        for (const char& cell : row)
        {
            cout << cell;
        }
        cout << endl;
    }
}

bool Map::loadMap(const string& filename)
{
    widthX= 0;
    lengthY = 0;

    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << filename << endl;
        return false;
    }

    string line;
    vector<vector<char>> tempMap;
    while (getline(file, line))
    {
        vector<char> row;
        for (char c : line)
        {
            row.push_back(c);
            widthX += 1;
        }
        lengthY += 1;
        tempMap.push_back(row);
    }
    
    widthX /= lengthY;
    mapData = tempMap;
    file.close();
    return true;
}