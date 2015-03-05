#pragma once
#include "ofMain.h"
#include "EngineInclude.h"

class Engine
{
public:
    Engine(std::string tileData, std::string objectData, std::string gameData, ofVec2f&);
    ~Engine();
    void setup();
    void update();
    void draw();
private:
    TileManager* tiles;
    ResourceManager* resources;
    //ObjectManager* objects;

    ofVec2f* tFactor;



};
