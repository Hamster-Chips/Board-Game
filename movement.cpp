#include "movement.h"
#include <iostream>

using namespace std;

Movement::Movement() {}
Movement::Movement(Player& curr_player, Map& playingMap, RollDie& dice) : curr_player(curr_player), playingMap(playingMap), dice(dice) {}
Movement::~Movement() {}

Player Movement::getPlayers() const { return curr_player; }
Map Movement::getPlayingMap() const { return playingMap; }
int Movement::getMoves() const { return moves; }

void Movement::setPlayers(const Player& player) { this->curr_player = player; }
void Movement::setPlayingMap(const Map& newMap) { this->playingMap = newMap; } 
void Movement::setMoves(int num) { this->moves = num; }

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

void Movement::go()
{
    vector<vector<char>> mapData = playingMap.getMapData();
    int curr_X = curr_player.getX();
    int curr_Y = curr_player.getY();
    int movement = moves;
    playingMap.printMap();
    direction();
    int choice = pickDirection();
    bool doneMoving = false;
    bool forceTurn = false;
    while (!doneMoving)
    {
        cout << "Movement: " << movement << endl;
        if (movement <= 1)
        {
            doneMoving = true;
        }

        switch (choice)
        {
            case 1:
                if (mapData[--curr_Y][curr_X] == '.')
                {
                    ++curr_Y;
                    forceTurn = true;
                }
                else
                {
                    curr_player.setY(curr_Y);
                    --movement;
                }
                break;
            case 2:
                if (mapData[++curr_Y][curr_X] == '.')
                {
                    --curr_Y;
                    forceTurn = true;
                }
                else
                {
                    curr_player.setY(curr_Y);
                    --movement;
                }
                break;
            case 3:
                if (mapData[curr_Y][--curr_X] == '.')
                {
                    ++curr_X;
                    forceTurn = true;
                }
                else
                {
                    curr_player.setX(curr_X);
                    --movement;
                }
                break;
            case 4:
                if (mapData[curr_Y][++curr_X] == '.')
                {
                    --curr_X;
                    forceTurn = true;
                }
                else
                {
                    curr_player.setX(curr_X);
                    --movement;
                }
                break;
        }

        playingMap.printMap();
        direction();
        int count = 0;
        for (int i = 0; i < 4; i++)
        {
            if (checkAround[i])
                count++;
        }

        if (count >= 3 || forceTurn)
        {
            playingMap.printMap();
            pickDirection();
            forceTurn = false;
        }
    }

}

void Movement::printMove() const
{
    cout << "Rolled " << moves << endl;
}
