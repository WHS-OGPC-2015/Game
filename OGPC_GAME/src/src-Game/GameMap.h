
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

    std::vector<int> genMap(int, int, int);
    void genMapTwo();
    void drought(bool, int&, int&, int, int);
    void floodFill(int, int, int);
    void mapTextureNames(std::string path);
    void saveMap(ofVec2i, std::vector<int>);

private:

    ofVec2i mapSize;
    int seednum;
    std::vector <GenTile> mapTiles;
    std::vector <std::string> textureStrings;

    std::vector<int> altitudes;
    std::vector<int> fillAlts;
    int numWater;
};
