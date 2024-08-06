#include <iostream> 
#include <fstream>

#include "map.h"
#include "enemy.h"
#include "player.h"

using namespace std;

/*
    Notes for myself:
    To run put in the cmd like: g++ -o main.exe map.h map.cpp enemy.h enemy.cpp main.cpp player.h player.cpp (enter) ./main.exe
*/

vector<Enemy> makeEnemy(const string& revealMap);

int main()
{
    cout << "TESTING\n" << endl;

    // Testing map
    Map myMap("Le map", 3, "map3.txt");
    Map revealMap("NO ONE SEE", 3, "reveal3.txt");
    vector<Enemy> enemies = makeEnemy("reveal3.txt");

    myMap.printMap();
    cout << endl;

    revealMap.printMap();
    cout << endl;

    // Testing enemy
    for (Enemy enemy : enemies)
        enemy.printEnemy();
    cout << endl;

    // Testing player
    vector<string> lays ({"BOO", "hi"});
    Player player1;
    player1.setName("Jorge");
    player1.setScore(0);
    player1.setPlayerItems(lays);
    player1.addItems("doo");
    player1.removeItems("hi");
    player1.printItems();

    cout << "player Name: " << player1.getName() << endl;
    cout << "player score: " << player1.getScore() << endl;
    cout << "player items: ";
    
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