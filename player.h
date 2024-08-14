#ifndef PLAYER_H
#define PLAYER_H


#include <vector>
#include <string>



// player
    class Player{

        private:
            std::string name; 
            int score;
            std::vector<std::string> playerItems; 
            std::vector<int> playerLoc;
            int x;
            int y;
            


        public:
        
            Player();
            Player(const std::string& name, int score, const std::vector<std::string>& playerItems, int x, int y);
            ~Player();

            std::string getName() const;
            int getScore() const;
            std::vector<std::string> getPlayerItems() const;
            int getX();  
            int getY();  
            
            


            void setName(const std::string& name);
            void setScore(int score);
            void setPlayerItems(const std::vector<std::string>& items);
            void setX(int X);  
            void setY(int Y);  

            void addItems(const std::string& playerItems);
            void removeItems(const std::string& items);
            void printItems() const;


            std::vector<int> getPlayerLoc();
            void setPlayerLoc(std::vector<int> newLoc);
            
            

    };

#endif