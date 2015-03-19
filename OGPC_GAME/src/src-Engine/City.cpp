#include "City.h"


std::string randomname()
{
    std::vector <std::string> prefixes;
    std::vector <std::string> suffixes;
    std::string line;

    int recordpf = 0;

    std::ifstream TownNames("CityNames.txt");
    if(TownNames.is_open())
    {
        while(getline(TownNames, line))
        {
            if (line == "---Prefixes---")
            {
                recordpf = 1;
            }
            else if (recordpf == 1)
            {
                prefixes.push_back(line);
            }
            if (line == "---Suffixes---")
            {
                recordpf = 2;
            }
            else if (recordpf == 2)
            {
                suffixes.push_back(line);
            }
        }
        TownNames.close();
    }
    std::string retstr = prefixes[ofRandom(0, prefixes.size())]+suffixes[ofRandom(0,suffixes.size())];
    return  retstr;
}










City::City(Tile& btile) : boundTile(btile)
{
    population = 1000;
    converted = 0;
    cityName = randomname();
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

void City::saveObjectData(ofxXmlSettings& file)
{

}


