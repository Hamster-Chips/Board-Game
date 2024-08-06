#ifndef MINIGAMES_H
#define MINIGAMES_H

#include <vector>
#include <string>
#include "../player.h"

//minigames
    class Minigames{

        private:

            std::string name;
            std::string description;
            std::vector<int> playersScore;
            std::vector<Player> players;
            std::vector<int> reward;


        public:
        
            Minigames();
            Minigames(const std::string& name, const std::string& description, const std::vector<int>& playersScore, const std::vector<Player>& players, const std::vector<int>& reward);
            ~Minigames();

            std::string getName() const;
            std::string getDescription() const;
            std::vector<int> getPlayersScore() const;
            std::vector<Player> getPlayers() const;
            std::vector<int> getReward() const;

            void setName(const std::string& name);
            void setDescription(const std::string& description);
            void setPlayersScore(const std::vector<int>& playersScore);
            void setPlayers(const std::vector<Player>& players);
            void setReward(const std::vector<int>& reward);

            void printMinigames(const std::string& name, const std::string& description);
            void printResult(const std::vector<int>& playerscore, std::vector<Player>& players); 
    };

#endif