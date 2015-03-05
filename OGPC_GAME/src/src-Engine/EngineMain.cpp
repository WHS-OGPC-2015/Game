#include "EngineMain.h"
#include "../XML/src/ofxXmlSettings.h"
Engine::Engine(std::string tileData, std::string objectData, std::string GameData, ofVec2f& trans)
{

    tFactor = &trans;


    //resources->loadFilesFromDirectory("C:\\OpenFrameworks\\apps\\Game\\OGPC_GAME\\bin\\data\\tileTextures");
    std::cout << "here3" << std::endl;
    tiles = new TileManager(tileData, trans);
    //objects = new ObjectManager(objectData, trans);





}

void Engine::setup()
{

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
    delete resources;
    delete tiles;
    //delete objects;
}

