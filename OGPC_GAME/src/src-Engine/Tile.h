#pragma once
#include "ofMain.h"
#include "TileTemplate.h"

class Tile
{
public:
    Tile(ofTexture& texture);
    void update();
    void draw();

private:
    ofTexture* texture

};



