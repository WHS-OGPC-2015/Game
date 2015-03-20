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










City::City(int dif, Tile& btile) : boundTile(btile)
{
    TileIndex = boundTile;
    population = 1000; // default population
    converted = 0; // you don't have any influence
    cityName = randomname(); // set name to a random combination of prefixes and suffixes
    maxdif = 5;  // set the maximum difficulty for ALL cities
    difficulty = dif;     // set the difficulty for a city
    thresholds[0] = .05;     // below this percentage of believers in a discovered city, the believers will increase
    thresholds[1] = .5 + difficulty; // above this
    threshdolds[2] = .95;  // above this percentage in a discovered city, the converted will decline

}

void City::Update()
{
    if (percentconverted < thresholds[0])
    {
       accel = 1;
    }
    if (percentconverted > thresholds[2])
    {
        accel = -1;
    }
    else
    {
        if (percentconverted < thresholds[1])
        {
           accel  = (percentconverted - thresholds[0])*(thresholds[1])
        }
        else
        {

        }

    }





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

    file.addValue("cityTexture", TextureName);
    file.addValue("cityName", cityName);
    file.addValue("population", population);
    file.addValue("converted", converted);
    file.addValue("velocity", velocity);
    file.addValue("accel", accel);
    file.addValue("TLposx", TLpos.x);
    file.addValue("TLposy", TLpos.y);
    file.addValue("BRposx", BRpos.x);
    file.addValue("BRposy", BRpos.y);
    file.addValue("threshold0", thresholds[0]);
    file.addValue("threshold1", thresholds[1]);
    file.addValue("threshold2", thresholds[2]);
    file.addValue("difficulty", difficulty);
    file.addValue("occupied", occupied);


}

void City::loadObjectData(ofxXmlSettings& file);
{
    TileIndex = boundTile;
    TextureName = file.getValue("cityName", "")
    cityName = file.getValue("cityName", "");
    population = file.getValue("population", 0.0);
    converted = file.getValue("converted", 0.0);
    velocity = file.getValue("velocity", 0.0);
    accel = file.getValue("accel", 0.0);
    ofVec2f TLpos = ofVec2f(file.getValue("TLposx", 0.0), file.getValue("TLposy", 0.0));
    ofVec2f BRpos = ofVec2f(file.getValue("BRposx", 0.0), file.getValue("BRposy", 0.0));
    thresholds[0] = file.getValue("threshold0", 0.0);
    thresholds[1] = file.getValue("threshold1", 0.0);
    threshdolds[2] = file.getValue("threshold2", 0.0);
    difficulty = file.getValue("difficulty", 0);
    occupied = file.getValue("occupied", 0);
}
