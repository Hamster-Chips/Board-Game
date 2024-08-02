#ifndef MINIGAMES_H
#define MINIGAMES_H

#include <vector>
#include <string>


//minigames
    class Minigames{

        private:

            std::string name; 
            std::vector<int> playersScore;
            std::vector<std::string> players;
            std::vector<int> reward;


        public:
        
            Minigames();
            Minigames(const std::string& name, const std::vector<int>& playersScore, const std::vector<std::string>& players, const std::vector<int>& reward);
            ~Minigames();

            std::string getName() const;
            std::vector<int> getPlayersScore() const;
            std::vector<std::string> getPlayer() const;
            std::vector<int> getReward() const;

            void setName(const std::string& name);
            void setPlayersScore(const std::vector<int>& playersScore);
            void setPlayer(const std::vector<std::string>& players);
            void setReward(const std::vector<int>& reward);

            void printMinigames() const;
            void printResult() const; 
    };

#endif