#pragma once
#include "ofMain.h"
#include "Tile.h"

class City
{
public:
    City();
    void Update();
    void Draw();
    double getPercentConverted();

private:
    Tile* boundTile;
    ofVec2i posBoundTile;
    ofTexture* cityTexture
    std::string cityName;
    Menu* cityPopup;
    double population;
    double converted;
    double percentconverted;
    ofVec2f TLpos;
    ofVec2f BRpos;


};
