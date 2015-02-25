#include "TileManager.h"

TileManager::TileManager(std::string file)
{
    TileTemplate basicTile;//create temporary tile template
    basicTile.addAttribute(ofTexture* texture, "Texture");// add Texture attribute
    basicTile.addAttribute(int value, "Value");//add arbitrary value attribute
    templates.push_back(basicTile);//push template into template array
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
        for(int ii = 0; ii < numOfTiles; iii++)
        {
            Tile tmp(templates[templateNames{tileType}]);
            tmp.setAttribute()
            tiles.push_back(tmp);
        }

        for(int ii = 0; ii < numOfTiles; iii++)
        {
            Tile tmp(templates[0]);
            tiles.push_back(tmp);
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

