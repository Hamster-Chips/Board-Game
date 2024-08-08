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
    Player MOP;
    Player Lebron;
    Player Jordan;
    MOP.setName("Movement of The People");
    exodus.setName("Exodus");

    vector<Player> ListOfPlayers = {exodus,MOP,Lebron,Jordan};
    
    
    Map playerMap("Lebron's World", 1);
    playerMap.printMap(ListOfPlayers);


    for (int i = 0; i < ListOfPlayers.size(); i ++){
        Player& tempPlayer = ListOfPlayers[i];
        int input = 0;
        while (input != 5){
            std::cout << "1. To move up " << '\n' << "2. To move down" << '\n'<< "3. To move right" << '\n'<< "4. To move left" << '\n'<< "5 To move to next players turn\n" << endl;
            cin >> input;
            if (input == 1){
                playerMap.moveUp(tempPlayer);
                playerMap.printMap(ListOfPlayers);
                
            }else if(input == 2){
                playerMap.moveDown(ListOfPlayers[i]);
                playerMap.printMap(ListOfPlayers);
                
            }else if(input == 3){
                playerMap.moveRight(tempPlayer);
                playerMap.printMap(ListOfPlayers);
                
            }else if(input == 4){
                playerMap.moveLeft(tempPlayer);
                playerMap.printMap(ListOfPlayers);
            }
            std::cout << endl;
        }
        std::cout <<'\n'<< endl;
        playerMap.printMap(ListOfPlayers);

    }
}
    