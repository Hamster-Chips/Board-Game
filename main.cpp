#include <iostream> 
#include <fstream>
#include "map.h"
#include "player.h"
#include "enemy.h"

using namespace std;

/*
    Notes for myself:
    To run put in the cmd like: g++ -o main.exe map.h map.cpp enemy.h enemy.cpp main.cpp (enter) ./main.exe
*/

int main()
{

    Player exodus;
    exodus.setName("Exodus");
    exodus.setScore(0);
    exodus.add_items("hi");

    Map playerMap(exodus.getCurMapNum());
    playerMap.printMap(exodus.getPlayerLoc());
    //exodus.moveDown();

    std::cout << '\n' << endl;
    int input = 0;
    while (input != 5){
        std::cout << "1. To move up " << '\n' << "2. To move down" << '\n'<< "3. To move right" << '\n'<< "4. To move left" << '\n'<< "-1 to quit\n" << endl;
        cin >> input;
        if (input == 1){
            exodus.moveUp();
            
        }else if(input == 2){
            exodus.moveDown();
            
        }else if(input == 3){
            exodus.moveRight();
            
        }else if(input == 4){
            exodus.moveLeft();
        }
        std::cout << endl;
    }
    


}

/*void setMap(const string& name, int mapNum, const string& pathMap)
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

}*/