#pragma once
#include "ofMain.h"
#include "TileManager.h"

class Engine
{
public:
    Engine(std::string tileData, std::string objectData, std::string gameData);
    setup();
    update();
    draw();
private:
    TileManager* tiles;
    ResourceManager* resources;
    ObjectManager* objects;
};
