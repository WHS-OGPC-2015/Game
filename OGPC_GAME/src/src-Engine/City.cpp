#include "City.h"

City::City()
{

    population = 1000;
    converted = 0;
}

void City::Update()
{
    percentconverted = converted / population;
}

void City::Draw()
{
    if (cityPopup->getActive() == true)
    {
        cityPopup->draw();
    }
    TLpos = ofVec2f(boundTile->position.x - cityTexture->getWidth() /2, boundTile->position.y - cityTexture->getHeight() /2);
    BRpos = ofVec2f(boundTile->position.x + cityTexture->getWidth() /2, boundTile->position.y + cityTexture->getHeight() /2);
    cityPopup->draw(boundTile->position);


}

double City::getPercentConverted()
{
    return percentconverted;
}
