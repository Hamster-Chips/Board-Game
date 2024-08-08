#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>

class Player
{
private:
    std::string name; 
    char symbol;
    int score;
    std::vector<std::string> items; 
    int x;
    int y;

public:
    Player();
    Player(const std::string& name, char symbol, int score, const std::vector<std::string>& items, int x, int y);
    ~Player();

    std::string getName() const;
    char getSymbol() const;
    int getScore() const;
    std::vector<std::string> getItems() const;
    int getX() const;
    int getY() const;

    void setName(const std::string& name);
    void setSymbol(const char symbol);
    void setScore(int score);
    void setPlayerItems(const std::vector<std::string>& items);
    void setX(int x);
    void setY(int y);

    void addItems(const std::string& playerItems);
    void removeItems(const std::string& items);
    
    void printItems() const;
    void printPlayer() const;
    
};

#endif