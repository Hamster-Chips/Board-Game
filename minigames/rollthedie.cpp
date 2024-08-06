#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <string>

/*
  Temporary version of rolling the dice.
  
*/

using namespace std;

// The dice you want to roll in dice notation.
const string DIE = "13d20";

// Rolls dice and returns the total sum.
int rollDice(int count, int max) {
  int sum = 0;
  int roll;
  string receipt = "Rolled: ";

  srand(time(0));

  for (int i = 0; i < count; i++) {
    roll = (rand() % max);

    receipt += to_string(roll) + ", ";
    sum += roll;
  }

  // scuffed removal of the last ", "
  receipt.pop_back();
  receipt.pop_back();

  cout << receipt << endl << "Sum: " << sum << endl;

  return sum;
}

int main() {
  int count = 0;
  int max = 0;
  int pos = DIE.find('d');

  cout << pos << endl;

  cout << DIE.substr(0, 'd') << endl;

  // Converts the max possible roll and # of dice from string into a number
  count = stoi(DIE.substr(0, pos));
  max = stoi(DIE.substr(pos + 1));

  cout << "# of Dice: " << count << endl;
  cout << "Max Possible Roll: " << max << endl;

  rollDice(count, max);
  
  return 0;
}
