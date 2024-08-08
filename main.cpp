#include <iostream> 
#include <fstream>

#include "map.h"
#include "enemy.h"
#include "player.h"

using namespace std;

/*
    clear; g++ -o main.exe main.cpp map.cpp enemy.cpp player.cpp; ./main.exe
*/

struct gameAssets{
    vector<Player> players;
    vector<Enemy> enemies;
};

gameAssets getAssets(const string& revealMap, int numOfPlayers);
bool move(Map& currMap, Player& currPlayer);
void currPrint(const Map& currMap, const gameAssets&);

int main()
{
    // cout << "TESTING enemy ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    // vector<Enemy> enemies;
    // vector<string> rewards = {"gold", "item"};
    // int health = 100;

    // Enemy enemy1("enemy1", '*', health, rewards, -1, -1);
    // enemies.push_back(enemy1);

    // Enemy enemy2;
    // enemy2.setName("enemy2");
    // enemy2.setSymbol('*');
    // enemy2.setHealth(health);
    // enemy2.setReward(rewards);
    // enemy2.setX(-1);
    // enemy2.setY(-1);
    // enemies.push_back(enemy2);

    // vector<Enemy> enemies = makeEnemy("reveal3.txt");
    // for (Enemy enemy : enemies)
    //     enemy.printEnemy();
    // cout << endl;

    // cout << "TESTING player ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    // vector<Player> players;
    // vector<string> items ({"gun", "taxes", "loan"});

    // Player player1("Player 1", '%', 69, items, 1, 1);
    // player1.printPlayer();
    // players.push_back(player1);
    // cout << endl;
    // players.push_back(player1);

    // Player player2;
    // player2.setName("Player 2");
    // player2.setSymbol('$');
    // player2.setScore(1);
    // player2.setPlayerItems(items);
    // player2.setX(1);
    // player2.setY(1);
    // player2.removeItems("gun");
    // player2.addItems("depressed");
    // player2.printPlayer();
    // players.push_back(player2);
    // cout << endl;
    // players.push_back(player2);

    // cout << "TESTING map ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    // Map myMap("Le map", 3, "map1.txt");
    // myMap.printMap();
    // cout << endl;

    // myMap.loadMap("map2.txt");
    // myMap.printMap();
    // cout << endl;
    
    // myMap.loadMap("map3.txt");
    // myMap.printMap();
    // cout << endl;

    // cout << "TESTING movement ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    Map myMap("Le map", 1, "map1.txt");
    gameAssets assets = getAssets("reveal1.txt", 2);
    bool done = false;
    while (!done)
    {
        int choice = -1;
        for (Player& p : assets.players)
        {
            cout << p.getName() <<"'s turn [" << p.getSymbol() << "]" << endl;
            bool moved = false;
            while (!moved)
            {
                currPrint(myMap, assets);
                if (move(myMap, p))
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

gameAssets getAssets(const string& revealMap, int numOfPlayers)
{
    ifstream file(revealMap);

    vector<Player> players;
    int score = 0;
    vector<string> items = {"gun", "taxes", "loan"};

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
                Enemy newEnemy("wack", '*', health, rewards, x, y);
                enemies.push_back(newEnemy);
            }
            else if (c == '1' || c == '2' || c == '3' || c == '4')
            {
                int num = c - '0';
                if (numOfPlayers >= num)
                {
                    Player newPlayer("name", c, score, items, x, y);
                    players.push_back(newPlayer);
                }
            }
            x += 1;
        }
        y += 1;
        x = 0;
    }

    gameAssets asset = {players, enemies};
    return asset;
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

void currPrint(const Map& currMap, const gameAssets& assets)
{
    int map_y = currMap.getLengthY();
    int map_x = currMap.getWidthX();
    vector<vector<char>> tempData = currMap.getMapData();

    vector<Player> players = assets.players;
    vector<Enemy> enemies = assets.enemies;

    for(Player p : players)
        tempData[p.getY()][p.getX()] = p.getSymbol();

    for(Enemy e : enemies)
        tempData[e.getY()][e.getX()] = e.getSymbol();

    for (int i = 0; i < map_y; i++)
    {
        for (int j = 0; j < map_x; j++)
        {
            cout << tempData[i][j] << " ";
        }
        cout << endl;
    }
}