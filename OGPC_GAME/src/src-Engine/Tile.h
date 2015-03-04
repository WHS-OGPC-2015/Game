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

private:
    ofTexture* texture;
    ofVec2f location;

};



