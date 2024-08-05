#include "minigames.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

Minigames::Minigames() : name(""), playersScore(), players(), reward() {}

Minigames::Minigames(const string& name, const vector<int>& playersScore, const vector<string>& players, const vector<int>& reward)
          : name(name), playersScore(playersScore), players(players) , reward(reward) {}; 

Minigames::~Minigames() {}

string Minigames::getName() const {return name; }
vector<int> Minigames:: getPlayersScore() const {return playersScore;}
vector<string> Minigames:: getPlayers() const {return players;}
vector<int> Minigames::getReward() const {return reward;}

void Minigames::setName(const string& name) { this->name = name; }
void Minigames::setPlayersScore(const vector<int>& playersScore) { this->playersScore = playersScore; }
void Minigames::setPlayers(const vector<string>& players) { this->players = players;}
void Minigames::setReward(const vector<int>& reward) { this->reward = reward;}

void Minigames::printMinigames() const {
    
}
