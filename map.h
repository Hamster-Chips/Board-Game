#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

class Map 
{
private:
    std::string name;
    //int mapNum;
    int widthX;
    int lengthY;
    std::vector<int> StartLoc;
    std::vector<int> FinishLoc;
    std::vector<std::vector<char>> mapData;

public:
    
    Map();
    //Map(const std::string& name, int mapNum, const std::string& filename);
    Map(int mapNum);
    ~Map();

    std::vector<int> getStartLoc();
    std::vector<int> getFinishLoc();
    std::string getName() const;
    //int getMapNum() const;
    int getWidthX() const;
    int getLengthY() const;
    std::vector<std::vector<char>> getMapData() const;

    void setName(const std::string& name);
    //void setMapNum(int mapNum);
    //void setDimension(const std::vector<std::vector<char>> mapData);


    void printMap(const std::vector<int>& p_loc);
    friend std::ostream& operator<<(std::ostream&, Map mp1);

    bool loadMap(int fileNum);
};

#endif