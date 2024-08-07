#include <iostream> 
#include <fstream>

#include "map.h"
#include "enemy.h"
#include "player.h"

using namespace std;

/*
    clear; g++ -o main.exe main.cpp map.cpp enemy.cpp player.cpp; ./main.exe
*/

vector<Enemy> makeEnemy(const string& revealMap);
bool move(Map& currMap, Player& currPlayer);
void currPrint(const Map& currMap, const vector<Player>& players, const vector<Enemy>& enemies);

int main()
{
    cout << "TESTING enemy ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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

    cout << "TESTING player ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    vector<Player> players;
    vector<string> items ({"gun", "taxes", "loan"});

    Player player1("Player 1", '%', 69, items, 1, 1);
    player1.printPlayer();
    players.push_back(player1);
    cout << endl;

    Player player2;
    player2.setName("Player 2");
    player2.setIdentifier('$');
    player2.setScore(1);
    player2.setPlayerItems(items);
    player2.setX(1);
    player2.setY(1);
    player2.removeItems("gun");
    player2.addItems("depressed");
    player2.printPlayer();
    players.push_back(player2);
    cout << endl;

    cout << "TESTING map ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    Map myMap("Le map", 3, "map1.txt");
    myMap.printMap();
    cout << endl;

    myMap.loadMap("map2.txt");
    myMap.printMap();
    cout << endl;
    
    myMap.loadMap("map3.txt");
    myMap.printMap();
    cout << endl;

    cout << "TESTING movement ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    bool done = false;
    Map temp = myMap;
    temp.loadMap("map2.txt");
    while (!done)
    {
        int choice = -1;
        for (Player& p : players)
        {
            cout << p.getName() <<"'s turn [" << p.getIdentifier() << "]" << endl;
            bool moved = false;
            while (!moved)
            {
                currPrint(temp, players, enemies);
                if (move(temp, p))
                {
                    cout << p.getX() << ", " << p.getY() << endl;
                    moved = true;
                }
                else
                {
                    cout << "You cannot go that way... Try again" << endl;
                }
            }
        }

        // done = true;
    }
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

bool move(Map& currMap, Player& currPlayer)
{
    /*
        1. Up
        2. Down
        3. Left
        4. Right
    */

    int direction = 0;
    cout << "1. Up\n2. Down\n3. Left\n4. Right" << endl;
    cout << "choice: ";
    cin >> direction;
    cout << endl;

    vector<vector<char>> mapData = currMap.getMapData();
    int curr_X = currPlayer.getX();
    int curr_Y = currPlayer.getY();

    switch (direction)
    {
        case 1:
            if (mapData[--curr_Y][curr_X] == '.')
                return false;
            currPlayer.setY(curr_Y);
            break;
        case 2:
            if (mapData[++curr_Y][curr_X] == '.')
                return false;
            currPlayer.setY(curr_Y);
            break;
        case 3:
            if (mapData[curr_Y][--curr_X] == '.')
                return false;
            currPlayer.setX(curr_X);
            break;
        case 4:
            if (mapData[curr_Y][++curr_X] == '.')
                return false;
            currPlayer.setX(curr_X);
            break;
    }

    return true;
}

void currPrint(const Map& currMap, const vector<Player>& players, const vector<Enemy>& enemies)
{
    int map_y = currMap.getLengthY();
    int map_x = currMap.getWidthX();
    vector<vector<char>> tempData = currMap.getMapData();
    for(Player p : players)
    {
        tempData[p.getY()][p.getX()] = p.getIdentifier();
    }

    for (int i = 0; i < map_y; i++)
    {
        for (int j = 0; j < map_x; j++)
        {
            cout << tempData[i][j] << " ";
        }
        cout << endl;
    }

}