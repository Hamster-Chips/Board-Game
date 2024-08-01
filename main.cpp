#include <iostream> 
#include <fstream>
#include "map.h"
#include "enemy.h"

using namespace std;

/*
    Notes for myself:
    To run put in the cmd like: g++ -o main.exe map.h map.cpp enemy.h enemy.cpp main.cpp (enter) ./main.exe
*/

vector<Enemy> makeEnemy(const string& revealMap);

int main()
{
    cout << "Hello World!\n" << endl;

    Map myMap("Le map", 3, "map3.txt");
    Map revealMap("NO ONE SEE", 3, "reveal3.txt");
    vector<Enemy> enemies = makeEnemy("reveal3.txt");

    myMap.printMap();
    cout << endl;

    revealMap.printMap();
    cout << endl;

    for (Enemy enemy : enemies)
        enemy.printEnemy();
    cout << endl;
    
}

vector<Enemy> makeEnemy(const string& revealMap)
{
    ifstream file(revealMap);

    vector<Enemy> enemies;
    int health = 10;
    vector<string> rewards = {"gold", "item"};

    int x = 0;
    int y = 0;
    string line;
    while (getline(file, line))
    {
        for (char c : line)
        {
            if (c == '@')
            {
                Enemy newEnemy("wack", health, rewards, x, y);
                enemies.push_back(newEnemy);
            }
            x += 1;
        }
        y += 1;
        x = 0;
    }

    return enemies;
}