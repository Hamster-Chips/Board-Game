#ifndef MOVEMENT_H
#define MOVEMNT_H

#include "player.h"
#include "map.h"

#include <vector>

class Movement
{
private:
    std::vector<Player> players;
    Map playingMap;
    int moves;

public:
    Movement();
    Movement(std::vector<Player>& players, Map& playingMap, int moves);
    ~Movement();

    std::vector<Player> getPlayers() const;
    Map getPlayingMap() const;
    int getMoves() const;

    void setPlayers(const std::vector<Player>& players);
    void setPlayingMap(const Map& newMap);
    void setMoves(int num);

    

    void printMove() const;
};

#endif