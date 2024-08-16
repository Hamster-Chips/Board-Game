#include "movement.h"
#include <iostream>

using namespace std;

Movement::Movement() {}
Movement::Movement(Player& curr_player, Map& playingMap, RollDie& dice) : curr_player(curr_player), playingMap(playingMap), dice(dice) {}
Movement::~Movement() {}

Player Movement::getPlayers() const { return curr_player; }
Map Movement::getPlayingMap() const { return playingMap; }
int Movement::getMove() const { return move; }

void Movement::setPlayers(const Player& player) { this->curr_player = player; }
void Movement::setPlayingMap(const Map& newMap) { this->playingMap = newMap; } 
void Movement::setMove(int num) { this->move = num; }

void Movement::direction()
{
    vector<vector<char>> mapData = playingMap.getMapData();
    int curr_Y = curr_player.getY();
    int curr_X = curr_player.getX();

    if (mapData[--curr_Y][curr_X] == 'O')
        checkAround[0] = true;
    else
       checkAround[0] = false; 
    ++curr_Y;

    if (mapData[++curr_Y][curr_X] == 'O')
        checkAround[1] = true;
    else
       checkAround[1] = false; 
    --curr_Y;

    if (mapData[curr_Y][--curr_X] == 'O')
        checkAround[2] = true;
    else
       checkAround[2] = false; 
    ++curr_X;

    if (mapData[curr_Y][++curr_X] == 'O')
        checkAround[3] = true;
    else
       checkAround[3] = false; 
    --curr_X;

}

int Movement::pickDirection()
{
    int choice = -1;
    bool check = false;
    while (!check)
    {
        checkAround[0] ? cout << "1. Up" : cout << "\n1. Cannot go there (X)";
        checkAround[1] ? cout << "\n2. Down" : cout << "\n2. Cannot go there (X)";
        checkAround[2] ? cout << "\n3. Left" : cout << "\n3. Cannot go there (X)";
        checkAround[3] ? cout << "\n4. Right" : cout << "\n4. Cannot go there (X)";

        cout << "\nchoice: ";
        cin >> choice;
        cout << endl;

        if (checkAround[--choice])
        {
            check = true;
        }
        else
        {
            cout << "You cannot go that direction" << endl;
            choice = -1;
        }

    }
    return ++choice;
}

// bool move(Map& currMap, Player& currPlayer, gameAssets& assets, int movement)
// {
//     /*
//         1. Up
//         2. Down
//         3. Left
//         4. Right
//     */
//     vector<vector<char>> mapData = currMap.getMapData();
//     int curr_X = currPlayer.getX();
//     int curr_Y = currPlayer.getY();

//     bool curr_dir[4] = {false, false, false, false};
//     currPrint(currMap, assets);
//     bool* checkAround = direction(curr_dir, mapData, curr_X, curr_Y);
//     int choice = pickDirection(checkAround);
//     bool doneMoving = false;
//     bool forceTurn = false;
//     while (!doneMoving)
//     {
//         cout << "Movement: " << movement << endl;
//         if (movement <= 1)
//         {
//             doneMoving = true;
//         }

//         switch (choice)
//         {
//             case 1:
//                 if (mapData[--curr_Y][curr_X] == '.')
//                 {
//                     ++curr_Y;
//                     forceTurn = true;
//                 }
//                 else
//                 {
//                     currPlayer.setY(curr_Y);
//                     --movement;
//                 }
//                 break;
//             case 2:
//                 if (mapData[++curr_Y][curr_X] == '.')
//                 {
//                     --curr_Y;
//                     forceTurn = true;
//                 }
//                 else
//                 {
//                     currPlayer.setY(curr_Y);
//                     --movement;
//                 }
//                 break;
//             case 3:
//                 if (mapData[curr_Y][--curr_X] == '.')
//                 {
//                     ++curr_X;
//                     forceTurn = true;
//                 }
//                 else
//                 {
//                     currPlayer.setX(curr_X);
//                     --movement;
//                 }
//                 break;
//             case 4:
//                 if (mapData[curr_Y][++curr_X] == '.')
//                 {
//                     --curr_X;
//                     forceTurn = true;
//                 }
//                 else
//                 {
//                     currPlayer.setX(curr_X);
//                     --movement;
//                 }
//                 break;
//         }

//         currPrint(currMap, assets);
//         checkAround = direction(curr_dir, mapData, curr_X, curr_Y);
//         int count = 0;
//         for (int i = 0; i < 4; i++)
//         {
//             if (checkAround[i])
//                 count++;
//         }

//         if (count >= 3 || forceTurn)
//         {
//             currPrint(currMap, assets);
//             choice = pickDirection(checkAround);
//             forceTurn = false;
//         }
//     }
//     return true;
// }


// void Movement::printMove() const
// {
//     cout << "Rolled " << move << endl;
// }
