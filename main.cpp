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

    Map myMap("Le map", 3, "map3.txt");
    vector<Enemy> enemies = makeEnemy("path3.txt");
    
}

void printCurrMap(const string& map, const string& revealMap, vector<Enemy>& enemies)
{
    ifstream fileMap(map);
    ifstream fileReveal(revealMap);
    string line;
    vector<vector<char>> tempMap;
    
    while (getline(fileReveal, line))
    {
        for (char c : line)
        {
            if (c != '@')
            {
                
            }

        }
    }

}

vector<Enemy> makeEnemy(const string& revealMap)
{
    ifstream file(revealMap);
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << revealMap << endl;
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

    return enemies;
}