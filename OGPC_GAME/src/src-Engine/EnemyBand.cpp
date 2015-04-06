#include "EnemyBand.h"


int EnemyBand::convertTo1dindex(ofVec2i v)
{
    return (v.y * fabs(extremeTiles[1].x - extremeTiles[0].x) + v.x); // converts an ofVec2i to an int based on the amount of tiles in the map
}

EnemyBand::EnemyBand();
{
    textureName = "";
    movable = true;
}

EnemyBand::EnemyBand(std::string str)
{
    textureName = str;
    movable = true;
}
//---------------------------------------------------
void EnemyBand::update()
{

}

void EnemyBand::turnlyUpdate()
{

}

void EnemyBand::draw()
{

}


//---------------------------------------------------
void EnemyBand::setTexture(std::string TexNam, ResourceManager& res)
{
    textureName = TexNam;
    enemyTexture = &res->getTexture(TexNam);

}
void EnemyBand::setTile(Tile til, int inde)
{
    boundTile = &til;
    boundTileIndex = inde;
}

void EnemyBand::setExtremeTiles(ofVec2i v1, ofVec2i v2)
{
    extremeTiles[0] = v1;
    extremeTiles[1] = v2;
    int temp = fabs(extremeTiles[1].x - extremeTiles[0].x)
    boundTileCoords = ofVec2i(boundTileIndex % temp, boundTileIndex / temp);
}

int EnemyBand::getIndex();
{
    return boundTileIndex;
}

