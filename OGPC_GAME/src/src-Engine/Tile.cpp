#include "Tile.h"

Tile::Tile()
{
    //??
}

void Tile::update()
{
    //??
}

void Tile::draw()
{
    texture->draw(location.x, location.y);
}

ofVec2f Tile::getLocation()
{
    return location;
}

void Tile::setLocation(ofVec2f newLocation)
{
    location = newLocation;
}

void Tile::setTexture(ofTexture& tex)
{
    texture = &tex;
}




