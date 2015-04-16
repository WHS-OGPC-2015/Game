#pragma once
#include "ofMain.h"


class Tile
{
public:
    Tile();         //constructor

    void update();
    void draw();

    ofVec2f getLocation();
    void setLocation(ofVec2f);

    void setTexture(ofTexture&);    //sets tile texture
    void setHighlightTexture(ofTexture&);

    void switchCityoc();
    void setBandoc(int i);
    void switchEBandoc();
    void switchHighlight();

    bool getCityoc();
    int getBandoc();
    bool getEBandoc();
    //bool getHighlight();


private:
    ofTexture* texture;
    ofTexture* HLTexture;
    bool Cityoc;
    int Bandoc;
    bool EBandoc;
   // bool highlight;

};



