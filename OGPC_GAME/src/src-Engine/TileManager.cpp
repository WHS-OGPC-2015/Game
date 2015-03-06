#include "TileManager.h"
#include "../XML/src/ofxXmlSettings.h"
TileManager::TileManager(std::string file, ofVec2f& trans)
{
    loadFromFile(file);
    tFactor = &trans;
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

        int numOfTiles = mapSize.x*mapSize.y; //#of tiles = product of map dimensions

        for(int ii = 0; ii < numOfTiles; ii++)
        {
            theMap.pushTag("tile"); //enter individual tile tag

            Tile tmp; //create temporary tile

            //set texture of tile by getting string from xml doc
                std::cout << theMap.getValue("texture", "") << std::endl;
                std::string temp = theMap.getValue("texture", "");
            tmp.setTexture(resources->getTextureReference(temp));
                std::cout << "here5" << std::endl;
            ofVec2f location = ofVec2f(((tiles.size()/mapSize.y)+1)*tileSize.y,
                                        ((tiles.size()/mapSize.x)+1)*tileSize.x);
            tmp.setLocation(location);

            tiles.push_back(tmp);
            theMap.popTag();
        }
        theMap.popTag();


    }
    else
    {
        //tell open frameworks to print an error if the XML doc did not load
        ofLogError("Position file did not load!");
    }

}

void TileManager::update()
{
    maxDisplayDim = ofVec2f((ofGetScreenWidth()/tileSize.x), (ofGetWindowHeight()/tileSize.y));//max number of tiles that can be displayed on the screen
    topLeftTile = ofVec2f((tFactor->x/tileSize.x), (tFactor->y/tileSize.y));               //number of tiles the map has been translated
    bottomRightTile = ofVec2f(topLeftTile.x+maxDisplayDim.x, topLeftTile.y+maxDisplayDim.y);
    topLeftScalar = tileIndiceByArrayCoords(topLeftTile);
    bottomRightScalar = tileIndiceByArrayCoords(bottomRightTile);


    for(int ii = 0; ii<tiles.size(); ii++)//initialize all members of array to false
    {
        toDraw.push_back(false);
    }

    for(int ii = topLeftScalar; ii < bottomRightScalar; ii+=mapSize.x)//increment by row
    {
        for(int bb = ii; bb< bottomRightTile.x; bb++)//increment by number of tile to draw per row
        {
            toDraw[bb] = true;
        }

    }
}

void TileManager::draw()
{
    for(int ii = 0; ii<tiles.size(); ii++)
    {
        if(toDraw[ii] == true)
        {
            tiles[ii].draw();
        }
    }
}

ofVec2f TileManager::tileArrayCoordsByIndice(int indice)
{
    int row = (indice/mapSize.y)+1;
    float fcolumn = indice%int(mapSize.x);
    int icolumn = fcolumn;
    return ofVec2f(icolumn, row);
}

int TileManager::tileIndiceByArrayCoords(ofVec2f coords)
{
    return (coords.y*mapSize.y)+coords.x;
}
