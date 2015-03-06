
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

private:

    ofVec2i mapSize;
    std::vector <Tile> mapTiles;
};
