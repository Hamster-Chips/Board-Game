#include "map.h"
#include <iostream>
#include <fstream>

using namespace std;

// Map::Map() : name(""), mapNum(0), widthX(0), lengthY(0) {}

Map::Map(const string& name, int mapNum, const std::string& filename, vector<Player>& players, vector<Enemy>& enemies)
    : name(name), mapNum(mapNum), players(players), enemies(enemies)
    { 
        loadMap(filename);
    }

Map::~Map() {}

string Map::getName() const { return name; }
int Map::getMapNum() const { return mapNum; }
vector<vector<char>> Map::getMapData() const { return mapData; }
int Map::getWidthX() const { return widthX; }
int Map::getLengthY() const { return lengthY; }
std::vector<Player> Map::getPlayers() const { return players; }
std::vector<Enemy> Map::getEnemy() const { return enemies; } 

void Map::setName(const string& name) { this->name = name; }
void Map::setMapNum(int mapNum) { this->mapNum = mapNum; }
void Map::setMapData(const vector<vector<char>>& mapData) { this->mapData = mapData; }
void Map::setPlayers(const vector<Player>& newPlayers) { this->players = newPlayers; }
void Map::setEnemies(const vector<Enemy>& newEnemies) { this->enemies = newEnemies; }

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

void Map::getAssets(int numOfPlayers, string fileName)
{
    ifstream file(fileName);
    string line;
    vector<vector<char>> revealData;
    while (getline(file, line))
    {
        vector<char> row;
        for (char c : line)
        {
            row.push_back(c);
        }
        revealData.push_back(row);
    }

    // Player dummy value
    int score = 0;
    vector<string> items = {"gun", "taxes", "loan"};

    // Enemy dummy value
    int health = 10;
    vector<string> rewards = {"gold", "item"};

    int x = 0;
    int y = 0;

    for (int i = 0; i < lengthY; i++)
    {
        for (int j = 0; j < widthX; j++)
        {
            if (revealData[i][j] == '@')
                {
                    Enemy newEnemy("wack", '@', health, rewards, x, y);
                    enemies.push_back(newEnemy);
                    // cout << "Added new enemy\n" << endl; // Test
                }
            else if (revealData[i][j] == '1' || revealData[i][j] == '2' || revealData[i][j] == '3' || revealData[i][j] == '4')
            {
                int num = revealData[i][j] - '0';
                if (numOfPlayers >= num)
                {
                    Player newPlayer("name", revealData[i][j], score, items, x, y);
                    players.push_back(newPlayer);
                    // cout << "Added new player\n" << endl; // Test
                }
            }
            x += 1;
        }
        y += 1;
        x = 0;
    }
}

void Map::printMap() const
{
    vector<vector<char>> tempData = mapData;

    for(Player p : players)
        tempData[p.getY()][p.getX()] = p.getSymbol();

    for(Enemy e : enemies)
        tempData[e.getY()][e.getX()] = e.getSymbol();

    for (int i = 0; i < lengthY; i++)
    {
        for (int j = 0; j < widthX; j++)
        {
            cout << tempData[i][j] << " ";
        }
        cout << endl;
    }
}
