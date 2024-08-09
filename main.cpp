#include <iostream> 
#include <fstream>
#include "map.h"
#include "enemy.h"
#include "minigames/minigames.h"
#include "player.h"
#include "terminal_utils.h"
using namespace std;

/*
    Notes for myself:
    To run put in the cmd like: g++ -o main.exe map.h map.cpp enemy.h enemy.cpp main.cpp player.h player.cpp terminal_utils.h terminal_utils.cpp minigames/minigames.cpp minigames/minigames.h (enter) ./main.exe
*/

int main()
{
    Minigames rollndie;
    cout << "Hello World!" << endl;
    vector<string> lays ({"BOO", "hi"});
    vector<int> score ({10, 0, 30, 50});
    Player player1("jorge", 0, lays);
    Player player2("brain", 0, lays);
    Player player3("brain", 0, lays);
    Player player4("Dave", 0, lays);
    vector<Player> player ({player1,player2,player3,player4});
    rollndie.printResult(score, player);
    
    

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
                Enemy newEnemy("wack", 10, rewards, x, y);
                enemies.push_back(newEnemy);
            }
            x += 1;
        }
        y += 1;
        x = 0;
    }
    
}