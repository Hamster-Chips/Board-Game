#include <iostream> 
#include <fstream>
#include "map.h"
#include "enemy.h"
#include "player.h"

using namespace std;

/*
    Notes for myself:
    To run put in the cmd like: g++ -o main.exe map.h map.cpp enemy.h enemy.cpp main.cpp (enter) ./main.exe
*/

int main()
{
    cout << "Hello World!" << endl;
    
    vector<string> lays ({"BOO", "hi"});
    Player exodus;
    exodus.setName("Jorge");
    exodus.setScore(0);
    exodus.setPlayerItems(lays);
    exodus.add_items("hi");
    exodus.set_cur_map(4);

    Map* map1 = Map::getInstance();

    map1->loadMap(exodus.get_cur_map());
    map1->printMap(exodus.getLoc());


}

void setMap(const string& name, int mapNum, const string& pathMap)
{
    //Map myMap(name, 3, "map3.txt");

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
                Enemy newEnemy("wack", 10, rewards, x, y);
                enemies.push_back(newEnemy);
            }
            x += 1;
        }
        y += 1;
        x = 0;
    }
    
}