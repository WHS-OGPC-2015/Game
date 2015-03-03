#include "EngineMain.h"

Engine::Engine(std::string tileData, std::string objectData, std::string GameData)
{


    resources = new ResourceManager;
    resources->loadFilesFromDirectory("C:\\OpenFrameworks\\apps\\Game\\OGPC_GAME\\bin\\data\\tileTextures");

    tiles = new TileManager(tileData);
    //objects = new ObjectManager(objectData);

}

void setup()
{

}

void update()
{
    tiles->update();
}

void draw()
{
    tiles->draw();
}

Engine::~Engine()
{
    delete resources;
    delete tiles;
    //delete objects;
}

