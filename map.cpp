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
   // : name(name), mapNum(mapNum) { loadMap(filename); }

Map::~Map() {}

string Map::getName() const { return name; }

//int Map::getMapNum() const { return mapNum; }
vector<vector<char>> Map::getMapData() const { return mapData; }

void Map::setName(const string& name) { this->name = name; }
//void Map::setMapNum(int mapNum) { this->mapNum = mapNum; }
//void Map::setDimension(const vector<vector<char>> mapData) { this->mapData = mapData; }




bool Map::loadMap(int fileNum)
{
    widthX= 0;
    lengthY = 0;
    string _fileNum = to_string(fileNum);


    ifstream file("map"+_fileNum+".txt");
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << "file"+_fileNum+".txt" << endl;
        return false;
    }

    string line;
    vector<vector<char>> tempMap;
    while (getline(file, line))
    {
        widthX = 0;
        vector<char> row;
        for (char c : line)
        {
            if (c == '.' || c == 'O' || c == 'E'||c == 'P')
            {
                widthX += 1;
                row.push_back(c);
            }
            else if(c=='S'){
                this->StartLoc = {widthX, lengthY};
                widthX += 1;
                row.push_back(c);

                
            } else if (c == 'F'){
                this->FinishLoc = {widthX, lengthY};
                widthX += 1;
                row.push_back(c);
                
            }else{
                cerr << "Unexpected character in map file: " << c << endl;
                return false;
            }
        }
        lengthY += 1;
        tempMap.push_back(row);
    }
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

void Map::printMap(const std::vector<int>& p_loc){

//Change map to show path player can move (O's where player can move)
    //cout << widthX << ", " << lengthY << endl;
    for (int row = 0; row < mapData.size(); row++)
    {
        for (int col = 0; col < mapData[0].size();col++)
        {
            if (col == p_loc[0] && row == p_loc[1]){
                cout << '*';
                continue;
            }
            if (mapData[row][col] == 'S'|| mapData[row][col] == 'E'|| mapData[row][col] == 'P' ||mapData[row][col] == '.')
            {
                cout << '.';
            }else if ( mapData[row][col] == 'O'||mapData[row][col] == 'F'){
                cout << 'O';
            }
        }
        cout << endl;
    }
}


vector<int> Map::getStartLoc(){
    return StartLoc;
}
vector<int> Map::getFinishLoc(){
    return FinishLoc;
}


int Map::getWidthX () const{
    return widthX;
    
}
int Map::getLengthY() const{
    return lengthY;
}


