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

void GameMap::genMap()
{
    mapSize = ofVec2i(150,150);
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
    seednum = 50;
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
    saveMap(mapSize, mapHeights);



}

void GameMap::genMapTwo()
{
    mapSize = ofVec2i(100, 100);


    std::vector <int> altitudes;
    for(int yy = 0; yy < mapSize.y; yy++)
    {
        for(int xx = 0; xx < mapSize.x; xx++)
        {
            float noise = scaled_octave_noise_2d(2, 1, .03, 0, 6, xx, yy);

            noise = trunc(noise);
            altitudes.push_back((int)noise);
            std::cout << noise << "  ";
        }
        std::cout << std::endl << std::endl;
    }
    saveMap(ofVec2i(mapSize.x, mapSize.y), altitudes);




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
        for(int bb = 0; bb < heights.size(); bb++)//cycle through all of the tags
        {
            tileSave.addTag("tile");
            tileSave.pushTag("tile", bb);
            std::string tex = textureStrings[heights[bb]];
            std::string lastTex = ""
            tileSave.addValue("texture", tex); //set texture based on tile altitude

            tileSave.popTag();
        }


    tileSave.popTag();
    tileSave.saveFile("tiles.xml");         //finally save file to "tiles.xml"
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

