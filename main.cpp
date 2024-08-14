#include <iostream> 
#include <fstream>
#include "map.h"
#include "player.h"
#include "enemy.h"
#include "minigames/minigames.h"
#include "player.h"
#include "check_input.h"
#include "terminal_utils.h"
using namespace std;

/*
    Notes for myself:
    To run put in the cmd like: g++ -o main.exe map.h map.cpp enemy.h enemy.cpp main.cpp player.h player.cpp check_input.h check_input.cpp terminal_utils.h terminal_utils.cpp minigames/minigames.cpp minigames/minigames.h (enter) ./main.exe
*/

int main()
{
    Minigames rollndie;
    cout << "Hello World!" << endl;

    vector<string> lays ({"BOO", "hi"});
    vector<int> score ({10, 0, 30, 50});
    Player player1("jorge", 0, lays,0,0);
    Player player2("brain", 0, lays,0,0);
    Player player3("brain", 0, lays,0,0);
    Player player4("Dave", 0, lays,0,0);
    vector<Player> player ({player1,player2,player3,player4});
    rollndie.printResult(score, player);
    


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
            cout << "1. To move up " << '\n' << "2. To move down" << '\n'<< "3. To move right" << '\n'<< "4. To move left" << '\n'<< "5 To move to next players turn\n" << endl;
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
            cout << endl;
        }
        cout <<'\n'<< endl;
        playerMap.printMap(ListOfPlayers);

    }
}
    