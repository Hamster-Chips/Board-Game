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

gameAssets getAssets(const Map& revealMap, int numOfPlayers);
bool move(Map& currMap, Player& currPlayer);
void currPrint(const Map& currMap, const gameAssets& assets);
int rollDie(int sides, int quantity);
bool* direction(bool checkAround[4], vector<vector<char>>& mapData, int curr_X, int curr_Y);

// Testing Functions
Map testMap()
{
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

    myMap.loadMap("map1.txt");

    return myMap;
}
vector<Enemy> testEnemy()
{
    cout << "TESTING enemy ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    vector<Enemy> enemies;
    vector<string> rewards = {"gold", "item"};
    int health = 100;

    Enemy enemy1("enemy1", '*', health, rewards, -1, -1);
    enemies.push_back(enemy1);

    Enemy enemy2;
    enemy2.setName("enemy2");
    enemy2.setSymbol('*');
    enemy2.setHealth(health);
    enemy2.setReward(rewards);
    enemy2.setX(-1);
    enemy2.setY(-1);
    enemies.push_back(enemy2);

    return enemies;
}
vector<Player> testPlayer()
{
    cout << "TESTING player ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    vector<Player> players;
    vector<string> items ({"gun", "taxes", "loan"});

    Player player1("Player 1", '%', 69, items, 1, 1);
    player1.printPlayer();
    players.push_back(player1);
    cout << endl;
    players.push_back(player1);

    Player player2;
    player2.setName("Player 2");
    player2.setSymbol('$');
    player2.setScore(1);
    player2.setPlayerItems(items);
    player2.setX(1);
    player2.setY(1);
    player2.removeItems("gun");
    player2.addItems("depressed");
    player2.printPlayer();
    players.push_back(player2);
    cout << endl;
    players.push_back(player2);

    return players;
}
void testGameAsset(gameAssets assets)
{
    cout << "Players: " << endl;
    for (Player p : assets.players)
    {
        p.printPlayer();
    }
    cout << endl;

    cout << "Enemies: " << endl;
    for (Enemy e : assets.enemies)
    {
        e.printEnemy();
    }
    cout << endl;
}
void testMovement(Map myMap, gameAssets assets)
{
    cout << "TESTING movement ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
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
void testDie()
{
    for (int i = 0; i < 100; i++)
    {
        cout << rollDie(6, 1) << " ";
    }
}

int main()
{
    int numOfPlayers = 2;
    Map myMap("Le map", 3, "map1.txt");
    Map revealMap("NO ONE SEE", 3, "reveal1.txt");
    gameAssets assets = getAssets(revealMap, numOfPlayers);
    srand(time(0));

}

gameAssets getAssets(const Map& revealMap, int numOfPlayers)
{
    vector<Player> players;
    int score = 0;
    vector<string> items = {"gun", "taxes", "loan"};

    vector<Enemy> enemies;
    int health = 10;
    vector<string> rewards = {"gold", "item"};

    int x = 0;
    int y = 0;

    vector<vector<char>> mapData = revealMap.getMapData();

    for (int i = 0; i < revealMap.getLengthY(); i++)
    {
        for (int j = 0; j < revealMap.getWidthX(); j++)
        {
            if (mapData[i][j] == '@')
            {
                Enemy newEnemy("wack", '*', health, rewards, x, y);
                enemies.push_back(newEnemy);
            }
            else if (mapData[i][j] == '1' || mapData[i][j] == '2' || mapData[i][j] == '3' || mapData[i][j] == '4')
            {
                int num = mapData[i][j] - '0';
                if (numOfPlayers >= num)
                {
                    Player newPlayer("name", mapData[i][j], score, items, x, y);
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

bool* direction(bool checkAround[4], vector<vector<char>>& mapData, int curr_X, int curr_Y)
{
    if (mapData[--curr_Y][curr_X] == 'O')
        checkAround[0] = true;
    else
       checkAround[0] = false; 

    if (mapData[++curr_Y][curr_X] == 'O')
        checkAround[1] = true;
    else
       checkAround[1] = false; 

    if (mapData[curr_Y][--curr_X] == 'O')
        checkAround[2] = true;
    else
       checkAround[2] = false; 

    if (mapData[curr_Y][++curr_X] == 'O')
        checkAround[3] = true;
    else
       checkAround[3] = false; 

    return checkAround;
}

bool move(Map& currMap, Player& currPlayer)
{
    /*
        1. Up
        2. Down
        3. Left
        4. Right

        1̶.̶ ̶U̶p (X)
        2̶.̶ ̶D̶o̶w̶n (X)
        3̶.̶ ̶L̶e̶f̶t (X)
        4̶.̶ ̶R̶i̶g̶h̶t (X)
    */
    vector<vector<char>> mapData = currMap.getMapData();
    int curr_X = currPlayer.getX();
    int curr_Y = currPlayer.getY();

    int movement = rollDie(6, 1);


    bool checkAround[4]; // {Up, Down, Left, Right}
    direction(checkAround, mapData, curr_X, curr_Y);

    int choice = 0;
    cout << "choice: ";
    cin >> choice;
    cout << endl;

    switch (choice)
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

int rollDie(int sides, int quantity)
{
    int result = 0;
    for (int i = 0; i < quantity; i++)
    {
        result += rand() % sides + 1;
    }

    return result;
}

