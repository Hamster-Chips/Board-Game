#include "map.h"
#include <iostream>
#include <fstream>



using namespace std;


Map::Map(){
    this->loadMap(1);
}
Map::Map(int mapNum){
    this->loadMap(mapNum);
}

Map::Map(const string& name, int mapNum)
    : name(name) { loadMap(mapNum); }

    /*ask brian if he still wants to loadmap by name or by number: Map(const string& name, int mapNum, const std::string& filename)
    : name(name) { loadMap(mapNum);  or Map::Map(const string& name, int mapNum, const std::string& filename)
    : name(name) { loadMap(filename); }*/

Map::~Map() {}

string Map::getName() const { return name; }

vector<vector<char>> Map::getMapData() const { return mapData; }

void Map::setName(const string& name) { this->name = name; }





bool Map::loadMap(int fileNum)
{
    widthX= 0;
    lengthY = 0;
    string _fileNum = to_string(fileNum);


    ifstream file("map"+_fileNum+".txt");
    if (!file.is_open())
    {
        cerr << "Failed to open file: " << "file"+_fileNum+".txt" << endl;
        return false;
    }

    string line;
    vector<vector<char>> tempMap;
    while (getline(file, line))
    {
        widthX = 0;
        vector<char> row;
        for (char c : line)
        {
            if (c == '.' || c == 'O' || c == 'E'||c == 'P')
            {
                widthX += 1;
                row.push_back(c);
            }
            else if(c=='S'){
                this->StartLoc = {widthX, lengthY};
                widthX += 1;
                row.push_back(c);

                
            } else if (c == 'F'){
                this->FinishLoc = {widthX, lengthY};
                widthX += 1;
                row.push_back(c);
                
            }else{
                cerr << "Unexpected character in map file: " << c << endl;
                return false;
            }
        }
        lengthY += 1;
        tempMap.push_back(row);
    }
    mapData = tempMap;
    file.close();
    return true;
}

void Map::printMap(std::vector<Player>& Players, Enemy& evil){


    for (int row = 0; row < mapData.size(); row++){
        for (int col = 0; col < mapData[0].size();col++){
            bool flag = false;
            bool once = true; 

            for (int i = 0; i < Players.size(); i++){
                vector<int> p_loc = Players[i].getPlayerLoc();
                
                if (col == p_loc[0] && row == p_loc[1]){ //get each player loc, each player associated with an ascii value,

                    std::cout << char(i+42);                 // if both players land on same spot print both players locations
                    flag = true;
                }
            }

            if (!flag && col == evil.getX() && row == evil.getY()) {
                std::cout << '$';  // Print enemy symbol
                flag = true;
            }

            if ((mapData[row][col] == 'S'|| mapData[row][col] == 'E'|| mapData[row][col] == 'P' ||mapData[row][col] == '.') && !flag){
                std::cout << '.';
            }else if (( mapData[row][col] == 'O'||mapData[row][col] == 'F')&& !flag){
                std::cout << 'O';
                }

        }
        
        std::cout << endl;

    }
            
       std::cout << endl;
    }


vector<int> Map::getStartLoc(){
    return StartLoc;
}
vector<int> Map::getFinishLoc(){
    return FinishLoc;
}


int Map::getWidthX () const{
    return widthX;
    
}
int Map::getLengthY() const{
    return lengthY;
}




char Map::moveDown(Player& tempPlayer){

    vector<int> playerLoc_ = tempPlayer.getPlayerLoc();

    
    if (playerLoc_[1] +1 <= lengthY-1){ //if player next move is within bounds
        int futureYLoc = playerLoc_[1] +1;
        char charAtLoc = mapData[futureYLoc][playerLoc_[0]]; // get char at the future location
        
        if (charAtLoc == 'F'){
            return charAtLoc;


        }else if(charAtLoc == 'O') {
            playerLoc_[1] +=1;
            tempPlayer.setPlayerLoc(playerLoc_);
            //std::cout << exodus.getPlayerLoc()[1] << endl;
            std::cout << '\n' << endl;

            

        }else{
            std::cout<< "You cannot move there."<<endl;
        }
        
    }else{
        std::cout<< "You cannot move there."<<endl;

    }
    return '0';
}

char Map::moveUp(Player& tempPlayer){

    vector<int> playerLoc_ = tempPlayer.getPlayerLoc();


    if (playerLoc_[1] -1 >=0){ //if player next move is within bounds
        int futureYLoc = playerLoc_[1] -1;
        char charAtLoc = mapData[futureYLoc][playerLoc_[0]]; // get char at the future location
        
        if (charAtLoc == 'F'){
            return charAtLoc;


        }else if(charAtLoc == 'O') {
            playerLoc_[1] -=1;
            tempPlayer.setPlayerLoc(playerLoc_);
            std::cout << '\n' << endl;

            

        }else{
            std::cout<< "You cannot move there."<<endl;
        }
        
    }else{
        std::cout<< "You cannot move there."<<endl;

    }
    return '0';
}

char Map::moveLeft(Player& tempPlayer){

    vector<int> playerLoc_ = tempPlayer.getPlayerLoc();

    if (playerLoc_[0] -1 >= 0){ //if player next move is within bounds
        int futureXLoc = playerLoc_[0] -1;
        char charAtLoc = mapData[playerLoc_[1]][futureXLoc]; // get char at the future location

        if (charAtLoc == 'F'){
            return charAtLoc;


        }else if(charAtLoc == 'O') {
            playerLoc_[0] -=1;
            tempPlayer.setPlayerLoc(playerLoc_);
            std::cout << '\n' << endl;

        }else{ 
            std::cout<< "You cannot move there."<<endl;
        }

    }else{
        std::cout<< "You cannot move there."<<endl;

    }
    return '0';
}

char Map::moveRight(Player& tempPlayer){

    vector<int> playerLoc_ = tempPlayer.getPlayerLoc();

    if (playerLoc_[0] +1 <= widthX){ //if player next move is within bounds
        int futureXLoc = playerLoc_[0] +1;
        char charAtLoc = mapData[playerLoc_[1]][futureXLoc]; // get char at the future location

        if (charAtLoc == 'F'){
            return charAtLoc;


        }else if(charAtLoc == 'O') {
            playerLoc_[0] +=1;
            tempPlayer.setPlayerLoc(playerLoc_);
            std::cout << '\n' << endl;

        }else{ 
            std::cout<< "You cannot move there."<<endl;
        }

    }else{
        std::cout<< "You cannot move there."<<endl;

    }
    return '0';
}

