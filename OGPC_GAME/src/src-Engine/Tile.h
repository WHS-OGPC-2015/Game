#pragma once
#include "ofMain.h"
#include "TileTemplate.h"

class Tile
{
public:
    Tile();         //constructor
    void update();
    void draw();

    void setTexture(ofTexture&);    //sets tile texture

private:
    ofTexture* texture;

};



