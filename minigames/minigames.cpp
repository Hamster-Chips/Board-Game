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
    cout <<  "Results: \n" << endl;
    int num = 1;
    int num2 =1;
    bool over = false; 
    while (!over)
    {
        for(int i = 0; i < players.size();i++){
            cout << num << ". " << players[i].getName() << " " << players[i].getScore() << " +"<< playersScore[i] << "\n" << endl;
            num += 1;
            //pause
            players[i].setScore(players[i].getScore() + playersScore[i]);
            // player get new score by set 
        }

        
        cout << " Final Results: \n " << endl;
        for(int i = 0; i < players.size();i++){
            cout << num2 << ". " << players[i].getName() << " " << players[i].getScore() << "\n" << endl;
            num2 += 1;
            //pause
        }
        over = true; 
    }
}


