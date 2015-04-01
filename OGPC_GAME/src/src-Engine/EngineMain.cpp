#include "EngineMain.h"
#include "../XML/src/ofxXmlSettings.h"
Engine::Engine()
{





}

void Engine::setup(std::string tileData, std::string objectData, std::string GameData, ofVec2f& trans, ResourceManager* R)
{
    tFactor = &trans;
//    resources = new ResourceManager;
//    resources->loadFilesFromDirectory("C:\\OpenFrameworks\\apps\\Game\\OGPC_GAME\\bin\\data\\tiles");
    resources = R;
    tiles = new TileManager(tileData, trans, *resources);
    objects = new ObjectManager(objectData, trans, TileManager);
}

void Engine::update()
{
    tiles->update();
}

void Engine::draw()
{
    tiles->draw();
}

Engine::~Engine()
{
    //delete resources;
    //delete tiles;
    //delete objects;
}

