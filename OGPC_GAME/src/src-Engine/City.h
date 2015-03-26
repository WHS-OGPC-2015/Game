#pragma once
#include "ofMain.h"
#include "Tile.h"
#include "../src-Game/Vec2i.h"
#include "../src-MenuAPI/MenuInclude.h"
#include "../XML/src/ofxXmlSettings.h"

class City
{
public:
    City(int, Tile& btile);

    void Update(ofVec2f& mousePos, bool& clicked, bool& pressed);
    void turnlyUpdate();
    int getClickedData(ofVec2f& mousePos, bool& clicked, bool& pressed);
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

    double thresholds[3]; // th 0 and th 2 are same in all cities

    // converted could also go here
    double velocity;
    double velmin;
    double velmax;
    double accel;
    double accelmax;    //same in all cities

    double extremeaccel[2]; // same in all cities

    int threshnums[2];

    int occupied;   // how many disciples are in the city
    bool entered;

    int difficulty;
    int maxdif;     //same in all cities

};
