#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

class Map 
{

private:

    std::string name;
    int mapNum;
    int widthX;
    int lengthY;
    std::vector<std::vector<char>> mapData;


    static Map* instancePtr;
    Map();
   //Map(const std::string& name, int mapNum, const std::string& filename);
   Map(int _mapNum);
    ~Map();


    


    

    

public:
    
    Map(const Map& obj) = delete;

    static Map* getInstance()
    {
        if (instancePtr == NULL)
        {
            instancePtr = new Map();
        }else{
            return instancePtr;
        }
    }


    /*std::string getName() const;
    int getMapNum() const;
    

    void setName(const std::string& name);
    void setMapNum(int mapNum);
    void setDimension(const std::vector<std::vector<char>> mapData);*/

    std::vector<std::vector<char>> getMapData() const;
    void printMap(const std::vector<int>& p_loc);
    //void printMap() const;
    //bool loadMap(const std::string& filename);
    bool loadMap(int fileNum);

//Map* Map::instancePtr = NULL;
};



#endif