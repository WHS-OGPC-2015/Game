#pragma once
#include "ofMain.h"
#include "TileTemplate.h"

class Tile
{
public:
    Tile(TileTemplate&);
    void update();
    void draw();

    template<class T>
    void setAttribute(T val, int indice)
    {
        attributes[indice] = val;
    }

private:
    std::vector<tileAttribute> attributes;//TEXTURE IS ALWAYS THE FIRST ATTRIBUTE

};



