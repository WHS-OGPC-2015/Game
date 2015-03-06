
#pragma once
#include "ofMain.h"


class Tile
{
    public:
    Tile(int alt, std::string text);
    Tile();
    void setAltitude(int a);
    int altitude;
    std::string texture;
    bool aset;
};
