#include "minigames.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

Minigames::Minigames() : name(""), description(""), playersScore(), players(), reward() {}

Minigames::Minigames(const string& name, const string& description, const vector<int>& playersScore, const vector<Player>& players, const vector<int>& reward)
          : name(name), description(description), playersScore(playersScore), players(players) , reward(reward) {}; 

Minigames::~Minigames() {}

string Minigames::getName() const {return name; }
string Minigames::getDescription() const {return description;}
vector<int> Minigames:: getPlayersScore() const {return playersScore;}
vector<Player> Minigames:: getPlayers() const {return players;}
vector<int> Minigames::getReward() const {return reward;}

void Minigames::setName(const string& name) { this->name = name; }
void Minigames::setDescription(const string& description) { this->description = description; }
void Minigames::setPlayersScore(const vector<int>& playersScore) { this->playersScore = playersScore; }
void Minigames::setPlayers(const vector<Player>& players) { this->players = players;}
void Minigames::setReward(const vector<int>& reward) { this->reward = reward;}

void Minigames::printMinigames(const string& name, const string& description){
    cout << "Welcome to " << name << "\n";
    cout << "How to play: " << description << "\n";
}

void Minigames::printResult(const vector<int>& playersScore, vector<Player>& players){
    cout <<  "Result: \n" << endl;
    int num = 1;
    for(int i = 0; i < players.size();i++){
        cout << num << ". " << players[i] << endl;
        num += 1;
    } 
}


