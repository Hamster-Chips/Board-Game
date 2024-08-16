#ifndef ROLLDIE_H
#define ROLLDIE_H

class RollDie
{
private:
    int side;
    int quantity;

public:
    RollDie();
    RollDie(int side, int quantity);
    ~RollDie();

    int getSide();
    int getQuantity();

    void setSide(int side);
    void setQuantity(int quantity);

    int roll();

    void printDie();

};

#endif

