#include "enemy.h"
#include <iostream>
#include <queue>
#include <vector>
#include "player.h"

using namespace std;

Enemy::Enemy() : name(""), health(0), x(-1), y(-1) {}
Enemy::Enemy(const std::string& name, const char symbol, int health, vector<string>& reward, int x, int y)
    : name(name), symbol(symbol), health(health), reward(reward), x(x), y(y) {}
Enemy::~Enemy(){}

string Enemy::getName() { return name; }
char Enemy::getSymbol() { return symbol; }
int Enemy::getHealth() { return health; }
std::vector<std::string> Enemy::getReward() { return reward; }
int Enemy::getX() { return x; } 
int Enemy::getY() { return y; }

void Enemy::setName(const string& name) { this->name = name; }
void Enemy::setSymbol (const char symbol) { this->symbol = symbol; }
void Enemy::setHealth(int health) { this->health = health; }
void Enemy::setReward(std::vector<std::string>& reward) { this->reward = reward; }
void Enemy::setX(int x) { this->x = x; }
void Enemy::setY(int y) { this->y = y; }

void Enemy::printEnemy()
{
    cout << name << " (" << symbol << ")" << endl; 
    cout << "   health: " << health << endl;

    cout << "   rewards: ";
    for(int i = 0; i < reward.size(); i++)
    {
        cout << reward[i] << " ";
    }
    cout << endl;

    cout << "   location (x, y) -> ";
    cout << "(" << x << ", " << y << ")" << endl;
    
}

void Enemy::bfs(const std::vector<std::vector<char>>& mapData , std::vector<Player>& players){
    std::cout << " IN BFS..." << std::endl;
    struct Position {
        int x, y, distance;
    };
    queue<Position> q;
    vector<vector<bool>> visited(mapData.size(), vector<bool>(mapData[0].size(), false));

    int startX = this->getX();
    int startY = this->getY();

    q.push({startX, startY, 0});
    visited[startY][startX] = true;

    std::cout << "Enemy starting at position (" << startX << ", " << startY << ")" << endl;

    while (!q.empty()) {
        Position current = q.front();
        q.pop();
        cout << "Processing position (" << current.x << ", " << current.y << "), distance: " << current.distance << endl;

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (newX >= 0 && newX < mapData[0].size() && newY >= 0 && newY < mapData.size()) {
                if (!visited[newY][newX]) {
                    visited[newY][newX] = true;
                    std::cout << "Moving to new position (" << newX << ", " << newY << ")" << endl;
                    
                    // Check if this position matches a player's location
                    for (Player& player: players) {
                        cout << "Player at (" << player.getX() << ", " << player.getY() << ")" << endl;
                        if (player.getX() == newX && player.getY() == newY) {
                            // Nearest player found
                            cout << "Nearest player found at (" << newX << ", " << newY << ") distance: " << current.distance + 1 << endl;
                            return; // Stop searching after finding the player
                        }
                    }

                    if (mapData[newY][newX] == 'O') {
                        q.push({newX, newY, current.distance + 1});
                    }
                }
            }
        }
    }
}

void Enemy::targetPlayer(const std::vector<Player>& players){


}
// work on enemy object finding nearest player object and moving there

