#include "Tile.h"



Tile::Tile(int alt, std::string text)
{
    altitude = alt;
    texture = text;
    aset = true;
}
Tile::Tile()
{
}
void Tile::setAltitude(int a)
{
    if (aset == false)
    {
        altitude = a;
        if (altitude < 0)
        {
            altitude = 0;
        }
        aset = true;
    }
}
