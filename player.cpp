#include "player.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include "map.h"

using namespace std; 

Player::Player() : name(""), score(0), playerItems(), playerLoc({0,0}), curMapNum(1) {}

Player::Player(const string& name, int score, const vector<string>& playerItems)
       : name(name), score(score), playerItems(playerItems) 
    {
        //added for map class functionality
        this->curMapNum = 1;
        this->playerLoc = {0,0};
    };

Player::~Player() {}

string Player::getName() const { return name; }
int Player::getScore() const { return score; }
vector<string> Player::getPlayerItems() const { return playerItems; }

void Player::setName(const string& name) { this->name = name; }
void Player::setScore(int score) { this->score = score; }
void Player::setPlayerItems(const vector<string>& items) { this-> playerItems = items;}

void Player::add_items(const string& PlayerItems){
    playerItems.push_back(PlayerItems);
}

void Player::remove_items(const std::string& items){
    auto it = std::find(playerItems.begin(), playerItems.end(), items);
    if (it != playerItems.end()) {
        playerItems.erase(it);
    }
}

/*void Player::print_items() const{
    for (const string items: getPlayerItems()){
        std::cout<< items << " ";
    }
    std::cout << "\n";
}*/


//added for map class functionality
std::vector<int> Player::getPlayerLoc(){
    return playerLoc;
}

//added for map class functionality
void Player::setPlayerLoc(std::vector<int> newLoc){
    this-> playerLoc = newLoc;
}

int Player::getCurMapNum(){
    return curMapNum;
}

void Player::setCurMapNum(int tempNum){
    this->curMapNum = tempNum;
    
}


char Player::moveDown(){
    Map tempMap(curMapNum);
    std::cout << playerLoc[1] << endl;
    if (playerLoc[1] +1 <= tempMap.getLengthY()-1){ //if player next move is within bounds
        int futureYLoc = playerLoc[1] +1;
        char charAtLoc = tempMap.getMapData()[futureYLoc][playerLoc[0]]; // get char at the future location
        
        if (charAtLoc == 'F'){
            return charAtLoc;

//can either do the code below or return 'F' to the main function and change to the nextmap there
            /*this->curMapNum += 1;
            Map tempMap(curMapNum);
            this->playerLoc = tempMap.getStartLoc();*/
            
        }else if(charAtLoc == 'O') {
            this->playerLoc[1] +=1;
            std::cout << '\n' << endl;
            tempMap.printMap(playerLoc);
            

            }else{
            std::cout<< "You cannot move there."<<endl;
            tempMap.printMap(playerLoc);
        }
        
    }else{
        std::cout<< "You cannot move there."<<endl;
        tempMap.printMap(playerLoc);

    }
    return '0';
}

char Player::moveUp(){
    Map tempMap(curMapNum);


    if (playerLoc[1] -1 >= 0){ //if player next move is within bounds
        int futureYLoc = playerLoc[1] -1;
        char charAtLoc = tempMap.getMapData()[futureYLoc][playerLoc[0]]; // get char at the future location

        if (charAtLoc == 'F'){
            return charAtLoc;

//can either do the code below or return 'F' to the main function and change to the nextmap there
            /*this->curMapNum += 1;
            Map tempMap(curMapNum);
            this->playerLoc = tempMap.getStartLoc();*/

        }else if(charAtLoc == 'O') {
            this->playerLoc[1] -=1;
            std::cout << '\n' << endl;
            tempMap.printMap(playerLoc);
            
        }else{ 
            std::cout<< "You cannot move there."<<endl;
            tempMap.printMap(playerLoc);
        }

    }else{ 
        std::cout<< "You cannot move there."<<endl;
        tempMap.printMap(playerLoc);

    }
    //std::cout << "lebron" << endl;
    return '0';
}

char Player::moveLeft(){
    Map tempMap(curMapNum);

    if (playerLoc[0] -1 >= 0){ //if player next move is within bounds
        int futureXLoc = playerLoc[0] -1;
        char charAtLoc = tempMap.getMapData()[playerLoc[1]][futureXLoc]; // get char at the future location

        if (charAtLoc == 'F'){
            return charAtLoc;

//can either do the code below or return 'F' to the main function and change to the nextmap there
            /*this->curMapNum += 1;
            Map tempMap(curMapNum);
            this->playerLoc = tempMap.getStartLoc();*/

        }else if(charAtLoc == 'O') {
            this->playerLoc[0] -=1;
            std::cout << '\n' << endl;
            tempMap.printMap(playerLoc);

        }else{ 
            std::cout<< "You cannot move there."<<endl;
            tempMap.printMap(playerLoc);
        }

    }else{
        std::cout<< "You cannot move there."<<endl;
        tempMap.printMap(playerLoc);

    }
    return '0';
}


char Player::moveRight(){
    Map tempMap(curMapNum);

    if (playerLoc[0] +1 <= tempMap.getWidthX()-1){ //if player next move is within bounds
        int futureXLoc = playerLoc[0] +1;
        char charAtLoc = tempMap.getMapData()[playerLoc[1]][futureXLoc]; // get char at the future location

        if (charAtLoc == 'F'){
            return charAtLoc;

//can either do the code below or return 'F' to the main function and change to the nextmap there
            /*this->curMapNum += 1;
            Map tempMap(curMapNum);
            this->playerLoc = tempMap.getStartLoc();*/

        }else if(charAtLoc == 'O') {
            this->playerLoc[0] +=1;
            std::cout << '\n' << endl;
            tempMap.printMap(playerLoc);


            }else{
            std::cout<< "You cannot move there."<<endl;
            tempMap.printMap(playerLoc);
        }

    }else{
        std::cout<< "You cannot move there."<<endl;
        tempMap.printMap(playerLoc);

    }
    return '0';
}