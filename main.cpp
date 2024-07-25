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

    Map map1("Wack name", 0, "map1.txt");
    map1.printMap();
    map1.loadMap("map2.txt");
    map1.printMap();

    Enemy wack;
    wack.setName("Wawaawa");
    wack.setHealth(69);
    vector<string> wack2Stuff = {"sad", "depressed"};
    wack.setReward(wack2Stuff);
    Enemy wack2("Nabu", 100, wack2Stuff);

    wack.printEnemy();
    wack2.printEnemy();


}