#pragma once
#include "ofMain.h"
#include "Tile.h"
#include "../src-Game/Vec2i.h"
#include "../src-MenuAPI/MenuInclude.h"
#include "../XML/src/ofxXmlSettings.h"

class City
{
public:
    City(Tile& btile) : boundTile(btile);

    void Update();
    void Draw();

    void saveObjectData(ofxXmlSettings&);
    void loadObjectData(ofxXmlSettings&);

    double getPercentConverted();

private:
    Tile& boundTile;
    ofVec2i TileIndex;
    ofTexture* cityTexture;
    std::string TextureName;
    std::string cityName;
    Menu* cityPopup;
    double population;
    double converted;
    double percentconverted;
    ofVec2f TLpos;
    ofVec2f BRpos;
    double thresholds[3];
    double converted;
    double velocity;
    double accel;
    int occupied;


    double
    int difficulty;
    int maxdif;

};
