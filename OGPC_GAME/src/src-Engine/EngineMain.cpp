#include "EngineMain.h"

Engine::Engine(std::string tileData, std::string objectData, std::string GameData)
{


    resources = new ResourceManager();
    resources->loadFromDirectory(ADD_STRING_HERE);

    tiles = new TileManager(tileData);
    objects = new ObjectManager(objectData);

}
