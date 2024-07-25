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

void Map::setName(const string& name) { this->name = name; }
void Map::setMapNum(int mapNum) { this->mapNum = mapNum; }
void Map::setDimension(const vector<vector<char>> mapData) { this->mapData = mapData; }

void Map::printMap() const
{
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
            if (c == '.' || c == 'O')
            {
                row.push_back(c);
            }
            else
            {
                cerr << "Unexpected character in map file: " << c << endl;
                return false;
            }
        }
        tempMap.push_back(row);
    }

    mapData = tempMap;
    file.close();
    return true;
}