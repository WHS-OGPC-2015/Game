#pragma once
#include "ofMain.h"
#include "Tile.h"
#include "../src-Game/Vec2i.h"
#include "../src-MenuAPI/MenuInclude.h"
#include "../XML/src/ofxXmlSettings.h"

class EnemyBand
{
public:

    EnemyBand();
    EnemyBand();

    void draw();
    void update();
    void turnlyUpdate();

    void setTexture(std::string TexNam, ResourceManager& res);
    void setTile(Tile Til, int inde);
    void setExtremeTiles(ofVec2i v1, ofVec2i v2);
    int getIndex();

    int convertTo1dindex(ofVec2i v);


private:

    Tile* boundTile;
    ofVec2i boundTileCoords;
    int boundTileIndex;

    ofTexture* enemyTexture;
    std::string textureName;

    ofVec2i extremeTiles[2];

    bool movable;

    vector<ofVec2i> possibleMoveCoords;
    vector<int> possibleMoveIndecies;
};
