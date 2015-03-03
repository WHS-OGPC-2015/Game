#pragma once
#include "Tile.h"

class TileManager
{
public:
    TileManager(std::string);

    void loadFromFile(std::string);

    void update();
    void draw();

    ofVec2f tileArrayCoordsByIndice(int indice);
    int tileIndiceByArrayCoords(ofVec2f);
private:
    std::vector<Tile> tiles;    //list of Tiles
    ofVec2f mapSize;   //width and height of tile array
    ofVec2f tileSize; //width and height of tiles (should be equal)
    ResourceManager* resources;//local pointer to engine resource manager

    ofVec2f maxDisplayDim, offsetDisplayDim, currentDisplayDim;
    int currentDimScalar;
    ofVec2f* tFactor;

    std::vector<bool> toDraw;






};
