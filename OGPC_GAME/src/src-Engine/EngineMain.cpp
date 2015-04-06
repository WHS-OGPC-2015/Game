#include "EngineMain.h"
#include "../XML/src/ofxXmlSettings.h"
Engine::Engine()
{





}

void Engine::mainThreadFunction()
{
    objects->mainThreadFunction();
}
void Engine::setup(std::string tileData, std::string objectData, std::string GameData, ofVec2f& trans, ResourceManager* R)
{
    tFactor = &trans;
//    resources = new ResourceManager;
//    resources->loadFilesFromDirectory("C:\\OpenFrameworks\\apps\\Game\\OGPC_GAME\\bin\\data\\tiles");
    resources = R;
    tiles = new TileManager(tileData, trans, *resources);
    objects = new ObjectManager(objectData, trans, tiles, resources);
}

void Engine::update(ofVec2f& mousePos, bool& clicked, bool& pressed)
{
    tiles->update();
    objects->updateAll(mousePos, clicked, pressed);
}

void Engine::draw()
{
    tiles->draw();
    objects->drawAll();
}

void Engine::drawNoTranslate()
{
    objects->drawNoTranslate();
}

Engine::~Engine()
{
    //delete resources;
    //delete tiles;
    //delete objects;
}

