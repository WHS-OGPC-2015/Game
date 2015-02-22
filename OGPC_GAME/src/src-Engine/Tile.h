#pragma once
#include "ofMain.h"
#include "TileTemplate.h"

class Tile
{
public:
    Tile(TileTemplate&);
    void update();
    void draw();

private:
    std::vector<tileAttribute> attributes;

};



