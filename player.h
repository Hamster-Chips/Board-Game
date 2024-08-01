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
            std::vector<int> loc;
            int cur_map = 1; 


        public:
            Player();
            Player(const std::string& name, int score, std::vector<int>& loc, const std::vector<std::string>& playerItems);
            ~Player();

            std::string getName() const;
            int getScore() const;
            std::vector<int> getLoc() const;
            int get_cur_map() const;

            std::vector<std::string> getPlayerItems() const;

            void setName(const std::string& name);
            void setScore(int score);
            void setPlayerItems(const std::vector<std::string>& items);
            void add_items(const std::string& playerItems);
            void remove_items(const std::string& playerItems);
            void print_items() const;
            //void setLoc(const std::vector<int>& _loc);
            void moveUp();
            void moveDown();
            void moveLeft();
            void moveRight();
            void set_cur_map(int num);
            


      
    };

#endif