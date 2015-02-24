#include "TileManager.h"

TileManager::TileManager(std::string file)
{

}



void TileManager::loadFromFile(std::string file)
{
    ofxXmlSettings theMap;
    if(theMap.loadFile(file))
    {
        mapSize.x = theMap.getValue("mapSizeX", 0.0);
        mapSize.y = theMap.getValue("mapSizeY", 0.0);
        tileSize.x = theMap.getValue("tileSizeX", 0.0);
        tileSize.y = theMap.getValue("tileSizeY", 0.0);
        int numOfTiles = mapSizeX*mapSizeY;
        theMap.pushTag("TILE");
        for(int ii = 0; ii < numOfTiles; ii++)
        {
            Tile tmp(NULL);
            tmp.setTexture(resources.getTextureRef(theMap.getValue("Texture", "")));;

            tiles.push_back(tmp);
        }

        for(int ii = 0; ii < numOfTiles; ii++)
        {

        }


    }
    else
    {
        ofLogError("Position file did not load!");
    }

}

void TileManager::update()
{

}

void TileManager::draw()
{

}

