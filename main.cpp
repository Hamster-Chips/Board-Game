#include <iostream> 
#include <fstream>
#include "map.h"
#include "enemy.h"

using namespace std;

/*
    Notes for myself:
    To run put in the cmd like: g++ -o main.exe map.h map.cpp enemy.h enemy.cpp main.cpp (enter) ./main.exe
*/

int main()
{
    cout << "Hello World!" << endl;

    Map map1("Wack name", 0, "map1.txt");
    map1.printMap();
    map1.loadMap("map2.txt");
    map1.printMap();

    Enemy wack;
    wack.setName("Wawaawa");
    wack.setHealth(69);
    vector<string> wack2Stuff = {"sad", "depressed"};
    wack.setReward(wack2Stuff);
    Enemy wack2("Nabu", 100, wack2Stuff);

    wack.printEnemy();
    wack2.printEnemy();


}

void setMap(const string& name, int mapNum, const string& pathMap)
{
    Map myMap(name, 3, "map3.txt");

    ifstream file(pathMap);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << pathMap << endl;
        return;
    }

    string line;
    vector<vector<char>> tempMap;
    vector<Enemy> enemies;
    vector<string> rewards = {"gold", "item"};
    int x = 0;
    int y = 0;
    while (getline(file, line))
    {
        vector<char> row;
        for (char c : line)
        {
            if (c == '@')
            {
                Enemy newEnemy("wack", 10, rewards);
                enemies.push_back(newEnemy);
            }
            x += 1;
        }
        y += 1;
        x = 0;
    }

    // Maybe create a struct to hold all info of the map or store it in the enemy and/or map class
    
}