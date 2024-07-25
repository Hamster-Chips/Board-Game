#include <iostream> 
#include <fstream>
#include "map.h"

using namespace std;

/*
    Notes for myself:
    To run put in the cmd like: g++ -o main.exe map.h map.cpp main.cpp (enter) ./main.exe
*/

int main()
{
    cout << "Hello World!" << endl;

    Map map1("Wack name", 1, "map1.txt");
    map1.printMap();
    map1.loadMap("map2.txt");
    map1.printMap();
}