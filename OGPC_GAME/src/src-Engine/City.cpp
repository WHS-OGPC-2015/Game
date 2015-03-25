#include "City.h"


//std::string randomname()
//{
//    std::vector <std::string> prefixes;
//    std::vector <std::string> suffixes;
//    std::string line;
//
//    int recordpf = 0;
//
//    std::ifstream TownNames("CityNames.txt");
//    if(TownNames.is_open())
//    {
//        while(getline(TownNames, line))
//        {
//            if (line == "---Prefixes---")
//            {
//                recordpf = 1;
//            }
//            else if (recordpf == 1)
//            {
//                prefixes.push_back(line);
//            }
//            if (line == "---Suffixes---")
//            {
//                recordpf = 2;
//            }
//            else if (recordpf == 2)
//            {
//                suffixes.push_back(line);
//            }
//        }
//        TownNames.close();
//    }
//    std::string retstr = prefixes[ofRandom(0, prefixes.size())]+suffixes[ofRandom(0,suffixes.size())];
//    return  retstr;
//}
//









City::City(int dif, Tile& btile) : boundTile(btile)
{
    TileIndex = boundTile;
    population = 1000; // default population
    converted = 0; // you don't have any influence
   // cityName = randomname(); // set name to a random combination of prefixes and suffixes
    maxdif = 5;  // set the maximum difficulty for ALL cities
    accelmax = 50;
    difficulty = dif;     // set the difficulty for a city
    thresholds[0] = .05;     // below this percentage of believers in an entered city, the believers will increase
    thresholds[1] = .5 + difficulty; // above this percentage in an entered city, the converted will increase
    thresholds[2] = .95;  // above this percentage in an entered city, the converted will decline
    velmin = -(thresholds[1]-thresholdsd[0]) * accelmax / 2; //integral from bottom th to middle th of the acceleration, / (-2) -- the C of the integral
    velmax = (thresholds[2]-thresholdsd[1]) * accelmax / 2;
    extremeaccel[0] = 10;
    extremeaccel[1] = -10;
    threshnums[0] = 0;


}

int City::getClickedData(ofVec2f& mousePos, bool& clicked, bool& pressed)
 {
    if (mousepos.x < TLpos.x || mousepos.x > BRpos.x ||
        mousepos.y < TLpos.y || mouspos.y > BRpos.y)
    {
        return 0;
        // its ouside
    }
    else
    {
        if (clicked == true)
        {
            return 3;
        }
        else if (pressed == true)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }


 }
void City::Update(ofVec2f& mousePos, bool& clicked, bool& pressed)
{
    if (getClickedData(mousePos, clicked, pressed) == 1)
    {
        cityPopup->setActive();
    }
}


void City::turnlyUpdate()
{
    percentconverted = converted / population;

    if (entered == true)
    {

        threshnums[1] = threshnums[0];
        if (percentconverted <= thresholds[0])
        {
           accel = extremeaccel[0];
           threshnums[0] = 0;
        }
        else if (percentconverted >= thresholds[2])
        {
            accel = extremeaccel[1];
            threshnums[0] = 3;
        }
        else
        {

            if (percentconverted < thresholds[1])
            {
                threshnums[0] = 1;
                accel  = (percentconverted - thresholds[0])*((accelmax)/(thresholds[1] - thresholds[0]));
               //this is a point-slope formula
            }
            else
            {
                threshnums[0] = 2;
                accel  = (percentconverted - thresholds[2])*((accelmax)/(thresholds[1] - thresholds[2]));
                // this is, too
            }
        }
//        if (percentconverted < thresholds[2])
//        {
//            add an acceleration based on the number of people in the city;
//        }
        if (threshnums[0] != threshnums[1]) // crossing thresholds
        {
            if (threshnums[1] == 0)
            {
                vel = velmin;
            }
            else if (threshnums[1] == 3)
            {
                vel = velmax;
            }
            else
            {
                vel = 0;
            }
        }

        vel += accel;
        converted += vel;


        if(converted < 0)
        {
            converted = 0;
        }
        if (converted > population)
        {
            converted = population;
        }
    }








}

void City::Draw()
{
    if (cityPopup->getActive() == true)
    {
        cityPopup->draw();
    }
    TLpos = ofVec2f(boundTile->position.x - cityTexture->getWidth() /2, boundTile->position.y - cityTexture->getHeight() /2);
    BRpos = ofVec2f(boundTile->position.x + cityTexture->getWidth() /2, boundTile->position.y + cityTexture->getHeight() /2);
    //cityPopup->draw(boundTile->position);


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
    file.addValue("velmin", velmin);
    file.addValue("velmax", velmax);
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
    file.addValue("entered", entered);


}

void City::loadObjectData(ofxXmlSettings& file);
{
    TileIndex = boundTile;
    TextureName = file.getValue("cityName", "")
    cityName = file.getValue("cityName", "");
    population = file.getValue("population", 0.0);
    converted = file.getValue("converted", 0.0);
    velocity = file.getValue("velocity", 0.0);
    velmin = file.getValue("velmin", 0.0);
    velmax = file.getValue("velmax", 0.0);
    accel = file.getValue("accel", 0.0);
    ofVec2f TLpos = ofVec2f(file.getValue("TLposx", 0.0), file.getValue("TLposy", 0.0));
    ofVec2f BRpos = ofVec2f(file.getValue("BRposx", 0.0), file.getValue("BRposy", 0.0));
    thresholds[0] = file.getValue("threshold0", 0.0);
    thresholds[1] = file.getValue("threshold1", 0.0);
    threshdolds[2] = file.getValue("threshold2", 0.0);
    difficulty = file.getValue("difficulty", 0);
    occupied = file.getValue("occupied", 0);
    entered = flie.getValue("entered", 0 /*hopefully works for bool?*/)
}
