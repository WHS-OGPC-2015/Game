#include "TileManager.h"

TileManager::TileManager(std::string file)
{
    loadFromFile(file);
}



void TileManager::loadFromFile(std::string file)
{
    ofxXmlSettings theMap;      //create new XML object for loading the tileset
    if(theMap.loadFile(file))   //if the xml document successfully loads
    {
        mapSize.x = theMap.getValue("mapSizeX", 0.0);   //retrieve width of tile map
        mapSize.y = theMap.getValue("mapSizeY", 0.0);   //retrieve height of tile map
        tileSize.x = theMap.getValue("tileSizeX", 0.0); //retrieve width of individual tile
        tileSize.y = theMap.getValue("tileSizeY", 0.0); //retrieve height of individual tile

        theMap.pushTag("TILES");    //go into tile tag section

        int numOfTiles = mapSizeX*mapSizeY; //#of tiles = product of map dimensions

        for(int ii = 0; ii < numOfTiles; ii++)
        {
            theMap.pushTag("tile"); //enter individual tile tag

            Tile tmp(); //create temporary tile

            //set texture of tile by getting string from xml doc
            tmp.setTexture(resources.getTextureRef(theMap.getValue("Texture", "")));;

            tiles.push_back(tmp);
        }


    }
    else
    {
        //tell open frameworks to print an error if the XML doc did not load
        ofLogError("Position file did not load!");
    }

}

void TileManager::update()
{

}

void TileManager::draw(ofVec2f tFactor)
{
    ofPushMatrix();
    ofTranslate(tFactor.x, tFactor.y);

        //tileSet.draw();
    ofPopMatrix();
}

