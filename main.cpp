#include <iostream> 
#include <fstream>

#include "map.h"
#include "enemy.h"
#include "player.h"

using namespace std;

/*
    Notes for myself:
    To run put in the cmd like: g++ -o main.exe main.cpp map.h map.cpp enemy.h enemy.cpp player.h player.cpp (enter) ./main.exe
*/

vector<Enemy> makeEnemy(const string& revealMap);

int main()
{
    cout << "TESTING\n" << endl;

    // Testing enemy
    vector<string> rewards = {"gold", "item"};
    int health = 100;

    Enemy enemy1("enemy1", health, rewards, -1, -1);

    Enemy enemy2;
    enemy2.setName("enemy2");
    enemy2.setHealth(health);
    enemy2.setReward(rewards);
    enemy2.setX(-1);
    enemy2.setY(-1);

    vector<Enemy> enemies = makeEnemy("reveal3.txt");
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

    // Testing map
    Map myMap("Le map", 3, "map2.txt");
    myMap.printMap();
    cout << endl;
    Map revealMap("NO ONE SEE", 3, "reveal3.txt");
    revealMap.printMap();
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