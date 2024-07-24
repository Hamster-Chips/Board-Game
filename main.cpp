#include <iostream> 
#include <fstream>
#include "map.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    // Map(const std::string& name, int mapNum, const std::string& filename);
    Map map1("Wack name", 1, "map1.txt");
    map1.printMap();
}