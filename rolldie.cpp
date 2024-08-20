#include "rolldie.h"
#include <iostream>

using namespace std;

RollDie::RollDie() : side(6), quantity(1) {}

RollDie::RollDie(int side, int quantity)
        : side(side), quantity(quantity) {}

RollDie::~RollDie() {}

int RollDie::getSide() { return side; }
int RollDie::getQuantity() { return quantity; }

void RollDie::setSide(int side) { this->side = side; }
void RollDie::setQuantity(int quantity) { this->quantity = quantity; }

int RollDie::roll()
{
    srand(time(0));
    int result = 0;
    for (int i = 0; i < quantity; i++)
    {
        result += rand() % side + 1;
    }

    return result;
}

void RollDie::printDie()
{
    cout << "Sides: " << side << " Quantity: " << quantity << endl;
}
