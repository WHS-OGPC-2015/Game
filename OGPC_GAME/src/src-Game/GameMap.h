
#pragma once
#include "ofMain.h"
#include "Tile.h"

class ofVec2i
{
public:
    ofVec2i(int a, int b);
    ofVec2i();
    int x;
    int y;

};



class GameMap
{
public:
   GameMap();
    int xwfunc(int x);
    int ywfunc(int x);

    void genMap();
    void genMapTwo();
    void mapTextureNames(std::string path);
    void saveMap(ofVec2i, std::vector<int>);

private:

    ofVec2i mapSize;
    int seednum;
    std::vector <GenTile> mapTiles;
    std::vector <std::string> textureStrings;
};
