#include "map.h"
#include <iostream>
#include <fstream>

using namespace std;


Map::Map(){
    this->loadMap(1);
}
Map::Map(int mapNum){
    this->loadMap(mapNum);
}

//Map::Map(const string& name, int mapNum, const std::string& filename)
    //: name(name), mapNum(mapNum) { loadMap(filename); }

Map::~Map() {}

//string Map::getName() const { return name; }
//int Map::getMapNum() const { return mapNum; }
vector<vector<char>> Map::getMapData() const { return mapData; }

//void Map::setName(const string& name) { this->name = name; }
//void Map::setMapNum(int mapNum) { this->mapNum = mapNum; }
//void Map::setDimension(const vector<vector<char>> mapData) { this->mapData = mapData; }

void Map::printMap(const std::vector<int>& p_loc){
    
    
    //cout << widthX << ", " << lengthY << endl;
    for (int x = 0; x < mapData.size(); x++)
    {
        for (int y = 0; y < mapData[1].size();y++)
        {
            if (x == p_loc[0] && y == p_loc[1]){
                cout << '*';
                continue;
            }
            if (mapData[x][y] == '@'|| mapData[x][y] == 'P')
            {
                cout << '.';
            }else{
                
            cout << mapData[x][y];
            }
        cout << endl;
        }
    }
}

/*void Map::printMap() const
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
}*/



bool Map::loadMap(int fileNum)
{
    widthX= 0;
    lengthY = 0;
    string _fileNum = to_string(fileNum);


    ifstream file("file"+_fileNum+".txt");
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << "file"+_fileNum+".txt" << endl;
        return false;
    }

    string line;
    vector<vector<char>> tempMap;
    while (getline(file, line))
    {
        vector<char> row;
        for (char c : line)
        {
            if (c == '.' || c == 'O' || c == '@'||c == 'P')
            {
                widthX += 1;
                row.push_back(c);
            }
            else
            {
                cerr << "Unexpected character in map file: " << c << endl;
                return false;
            }
        }
        lengthY += 1;
        tempMap.push_back(row);
    }
    
    widthX /= lengthY;
    mapData = tempMap;
    file.close();
    return true;
}

/*bool Map::loadMap(const string& filename)
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
            if (c == '.' || c == 'O' || c == '@')
            {
                widthX += 1;
                row.push_back(c);
            }
            else
            {
                cerr << "Unexpected character in map file: " << c << endl;
                return false;
            }
        }
        lengthY += 1;
        tempMap.push_back(row);
    }
    
    widthX /= lengthY;
    mapData = tempMap;
    file.close();
    return true;
}*/