#ifndef MOVEMENT_H
#define MOVEMNT_H

#include "player.h"
#include "map.h"
#include "rolldie.h"

#include <vector>

class Movement
{
private:
    Player& curr_player;
    Map& playingMap;
    RollDie& dice;
    int moves;
    bool checkAround [4];

public:
    Movement(Player& player, Map& playingMap, RollDie& dice);
    ~Movement();

    Player getPlayer() const;
    Map getPlayingMap() const;
    int getMoves() const;

    void setPlayer(const Player& players);
    void setPlayingMap(const Map& newMap);
    void setMoves(int num);

    void direction();
    int pickDirection();
    void go();

    void printMove() const;
};

#endif