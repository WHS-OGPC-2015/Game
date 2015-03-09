#include "GameMap.h"
#include <sstream>
#include "../XML/src/ofxXmlSettings.h"
#include "simplexnoise.h"

ofVec2i::ofVec2i(int a, int b)
{
        x = a;
        y = b;
}
ofVec2i::ofVec2i()
{

}

int GameMap::xwfunc(int x)
{
    return fabs(fabs(x-(mapSize.x-1))-(mapSize.x-1));
}
int GameMap::ywfunc(int x)
{
    return fabs(fabs(x-(mapSize.y-1))-(mapSize.y-1));
}
double maximize(double a, double b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int roundforint(double i)
{
    if (i < 0)
    {
        return (i - .5);
    }
    else if (i > 0)
    {
        return (i + .5);
    }
    else
    {
        return 0;
    }

}



GameMap::GameMap()
{
    mapTextureNames("C:\\OpenFrameworks\\apps\\Game\\OGPC_GAME\\bin\\data\\tiles");
    genMapTwo();
}

std::vector<int> GameMap::genMap(int sizeX, int sizeY, int seeds)
{
    mapSize = ofVec2i(sizeX, sizeY);
    GenTile mapArray[mapSize.x][mapSize.y];

    for (int i = 0; i < mapSize.x; i ++)
    {
        for (int j = 0; j < mapSize.y; j ++)
        {
             mapArray[i][j].aset = false;
             mapArray[i][j].altitude = -5;

        }
    }


//    seednum = maximize(sqrt((mapSize.x + mapSize.y)/2) + ofRandom(0,3) - 1, 1);
    seednum = seeds;
    ofVec2i seed;

    ofVec2i focus(seed.x, seed.y);


    bool done = false;
    int rando;
    int highnum;
    bool donecheck;
    ofVec2i pluspattern;

    for (int i = 0; i < seednum; i++)
    {
        seed = ofVec2i(ofRandom(0, mapSize.x), ofRandom(0, mapSize.y));
        mapArray[seed.x][seed.y].setAltitude(5);
    }




    while (done == false)
    {

        donecheck = true;
        highnum = -1;
        for (int i = 0; i < mapSize.x; i++)
        {
            for (int j = 0; j < mapSize.y; j++)
            {

                if (mapArray[i][j].aset == true and mapArray[i][j].altitude > highnum)
                {

                    if (        mapArray[xwfunc(i-1)][ywfunc(j)].aset == false
                                or mapArray[xwfunc(i+1)][ywfunc(j)].aset == false
                                or mapArray[xwfunc(i)][ywfunc(j-1)].aset == false
                                or mapArray[xwfunc(i)][ywfunc(j+1)].aset == false
                        )
                    {


                        highnum = mapArray[i][j].altitude;
                        focus.x = i;
                        focus.y = j;
                    }
                }
                else if (mapArray[i][j].aset == false)
                {

                    donecheck = false;
                }
            }
        }

        rando = ofRandom(0,99);
        for (int i = 0; i < 4; i ++)
        {
            pluspattern.x = roundforint(cos(i * 3.14159265 / 2));
            pluspattern.y = roundforint(sin(i * 3.14159265 / 2));


            if (mapArray[xwfunc(focus.x + pluspattern.x)][ywfunc(focus.y + pluspattern.y)].aset == false)
            {
                if (rando >= 0 and rando < 40)
                {
                    mapArray[xwfunc(focus.x + pluspattern.x)][ywfunc(focus.y + pluspattern.y)].setAltitude(mapArray[focus.x][focus.y].altitude - 1);
                }
                else if (rando >= 40 and rando < 60)
                {
                    mapArray[xwfunc(focus.x + pluspattern.x)][ywfunc(focus.y + pluspattern.y)].setAltitude(mapArray[focus.x][focus.y].altitude - 2);
                }
                else if (rando >= 60 and rando < 100)
                {
                    mapArray[xwfunc(focus.x + pluspattern.x)][ywfunc(focus.y + pluspattern.y)].setAltitude(mapArray[focus.x][focus.y].altitude);
                }
            }

        }
        if (donecheck == true)
        {

            done = true;
        }


    }
    std::vector<int> mapHeights;
    for (int i = 0; i < mapSize.x; i++)
    {
        for (int j = 0; j < mapSize.y; j++)
        {

            mapTiles.push_back(mapArray[i][j]);                     //push tile into 1d array
            mapHeights.push_back(mapArray[i][j].altitude);

        }

    }
    return mapHeights;
    //saveMap(mapSize, mapHeights);



}

void GameMap::genMapTwo()
{
    mapSize = ofVec2i(100, 100);
    int numSeeds = mapSize.x;
    int last = 1;
    float noiseWeight = .25;
    float seedWeight = .75;
    int waterThresh = 2;            //first level that is not a water tile
    int minLakeSize = 20;


    std::vector <int> noiseAlts;        //holds perlin random altitudes
    for(int yy = 0; yy < mapSize.y; yy++)
    {
        for(int xx = 0; xx < mapSize.x; xx++)
        {
            float noise = scaled_octave_noise_3d(4.f, .5, .05, 0, 8, xx, yy, last); //get perlin for square

            noise = trunc(noise);       //truncate decimals
            last = noise;               //set z coord for next loop
            noiseAlts.push_back((int)noise);    //add height to array

        }
        std::cout << std::endl << std::endl;
    }
    float avg = 0;
    std::vector<int> seedAlts = genMap(mapSize.x, mapSize.y, numSeeds);     //make a new vector with mountain point from genMap()
    for(int ii = 0; ii < seedAlts.size(); ii++)
    {
        seedAlts[ii]*=2;                                //simple averaging based on weights
        avg = seedAlts[ii]*seedWeight;
        avg += noiseAlts[ii]*noiseWeight;
        avg/=noiseWeight+seedWeight;
        avg = trunc(avg);
        if(avg > textureStrings.size())                                     //make sure the height is not bigger than the number of textures
        {
            avg = textureStrings.size();                                     //if it is, set the height to the highest texture

        }
        altitudes.push_back(avg);
    }

    for(int ii = 1; ii < altitudes.size(); ii++)                //check all of the tiles
    {
        if(altitudes[ii] < waterThresh)             //if its a water tile
        {
            drought(false, waterThresh, minLakeSize, ii, 31); //check to make sure there are at least >>minLakeSize<< tiles around it
        }
    }
    saveMap(ofVec2i(mapSize.x, mapSize.y), altitudes);


}

void GameMap::drought(bool diag, int& threshold, int& minSize, int start, int desired)
{
    fillAlts = altitudes;   //reset spare altitude vector
    numWater = 0;           //reset the number of water tiles
    if(!diag)               //call the 4 way fill
    {
        floodFill(threshold, desired, start);   //fill all water tiles in that section with other values
    }


    if(numWater < minSize)          //if the water needs to be replaced
    {
        for(int ii = 0; ii < fillAlts.size(); ii++)
        {
            if(fillAlts[ii] == desired)
            {
                altitudes[ii] = threshold;      //set the tile to not be water
            }
        }
    }

}

void GameMap::floodFill(int threshold, int desired, int indice)
{
    if(fillAlts[indice] < threshold)
    {
        fillAlts[indice] = desired;
        numWater++;
        floodFill(threshold, desired, indice+1);
        floodFill(threshold, desired, indice-1);
        floodFill(threshold, desired, indice+mapSize.x);
        floodFill(threshold, desired, indice-mapSize.x);
    }

}
void GameMap::saveMap(ofVec2i mapSize, std::vector<int> heights)
{

    ofxXmlSettings tileSave;
    tileSave.addValue("mapSizeX", mapSize.x);
    tileSave.addValue("mapSizeY", mapSize.y);
    tileSave.addValue("tileSizeX", 20);
    tileSave.addValue("tileSizeY", 20);
    tileSave.addTag("tileArray");
    tileSave.pushTag("tileArray");

    int numSame = 1;
    int currentH = 0;
    int nextH = 0;
    int pushedTagCount = 0;

    for(int bb = 0; bb < heights.size(); bb++)//cycle through all of the tags
    {
        currentH = heights[bb];
        nextH = heights[bb+1];
        if(currentH == nextH)
        {
            numSame++;
        }
        else
        {
            tileSave.addTag("tile");
            tileSave.pushTag("tile", pushedTagCount);
            pushedTagCount++;

            tileSave.addValue("texture", textureStrings[currentH]);
            tileSave.addValue("numSame", numSame);

            tileSave.popTag();

            numSame = 1;

        }

    }

    tileSave.popTag();

    tileSave.addValue("pushedTileCount", pushedTagCount);

    tileSave.saveFile("tiles.xml");
}

void GameMap::mapTextureNames(std::string folder)
{
    std::vector<std::string> names;

    std::string specPath = folder + "\\*.*";
    folder += "\\";

    WIN32_FIND_DATA fd;     //declare variable to hold file data
    HANDLE hFind = FindFirstFile(specPath.c_str(), &fd);    //find first file and store data
    if(hFind != INVALID_HANDLE_VALUE) {                     //if that data is not corrupt
        do {
            // read all (real) files in current folder
            // , delete '!' read other 2 default folder . and ..
            if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
                names.push_back(fd.cFileName);
                std::cout << fd.cFileName << std::endl;
            }
        }while(FindNextFile(hFind, &fd));                   //find the next file

        FindClose(hFind);

    }
    //at this point "names" vector has all file names in directory

    for(int indice = 0; indice < names.size(); indice++)
    {
        int dotLoc = names[indice].size(); //location of '.' in string
        std::string extension = "";  //parsed file extension
        std::string notExtension = ""; //just the name
        std::string prefix = "";
        prefix[0] = names[indice][0];
        int prefixInt;
        stringstream ss;
        ss << prefix;
        ss >> prefixInt;
        for(int ii = 0; ii<names[indice].size(); ii++)
        {
            if(names[indice][ii] == '.')    //if the character is a period
            {
                dotLoc = ii;                //store that indice
            }
            else if(ii > dotLoc)            //if the indice is after the period
            {
                extension+= names[indice][ii];   //store the character
            }
            else if(ii < dotLoc)
            {
                notExtension+= names[indice][ii];
            }
        }

        std::string fullPath  = folder+names[indice];
        if(extension == "jpg" ||       //Checking for all texture file extensions
            extension == "jpeg" ||
            extension == "png" ||
            extension == "bmp")
        {

            textureStrings.push_back(notExtension);  //if so load texture from that path
            //std::cout << textureMap[prefixInt] << " SWAG1" << std::endl;

        }





    }
}

