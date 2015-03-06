#include "GameMap.h"




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
    return fabs(fabs(x-(mapSize.x-1))-mapSize.x);
}
int GameMap::ywfunc(int x)
{
    return fabs(fabs(x-(mapSize.y-1))-mapSize.y);
}



GameMap::GameMap()
{

    mapSize = ofVec2i(3,3);
    int seedx = ofRandom(0,mapSize.x);
    int seedy = ofRandom(0,mapSize.y);
    ofVec2i focus(seedx, seedy);
    Tile mapArray[mapSize.x][mapSize.y];

    bool done = false;
    int rando;
    int highnum;
    bool donecheck;


    for (int i = 0; i < mapSize.x; i ++)
    {
        for (int j = 0; j < mapSize.y; j ++)
        {
             mapArray[i][j].aset = false;
             mapArray[i][j].altitude = -5;

        }
    }
    mapArray[focus.x][focus.y].setAltitude(5);




    while (done == false)
    {

        donecheck = true;
        highnum = -1;
        for (int i = 0; i < mapSize.x; i++)
        {
            for (int j = 0; j < mapSize.y; j++)
            {
                std::cout << mapArray[i][j].altitude << std::endl;

                if (mapArray[i][j].aset == true and mapArray[i][j].altitude > highnum)
                {

                    if (        mapArray[xwfunc(i-1)][ywfunc(j-1)].aset == false
                                or mapArray[xwfunc(i-1)][ywfunc(j+1)].aset == false
                                or mapArray[xwfunc(i+1)][ywfunc(j-1)].aset == false
                                or mapArray[xwfunc(i+1)][ywfunc(j+1)].aset == false
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
        std::cout << std::endl;

        rando = ofRandom(0,99);
        for (int i = -1; i < 2; i += 2)
        {

            for (int j = -1; j < 2; j += 2)
            {
                if (mapArray[xwfunc(focus.x + i)][ywfunc(focus.y + j)].aset == false)
                {
                    if (rando >= 0 and rando < 60)
                    {

                        mapArray[xwfunc(focus.x + i)][ywfunc(focus.y + j)].setAltitude(mapArray[focus.x][focus.y].altitude - 1);
                    }
                    else if (rando >= 60 and rando < 80)
                    {
                        mapArray[xwfunc(focus.x + i)][ywfunc(focus.y + j)].setAltitude(mapArray[focus.x][focus.y].altitude - 2);
                    }
                    else if (rando >= 60 and rando < 80)
                    {
                        mapArray[xwfunc(focus.x + i)][ywfunc(focus.y + j)].setAltitude(mapArray[focus.x][focus.y].altitude);
                    }
                }
            }

        }
        if (donecheck == true)
        {

            done = true;
        }


    }
    std::cout << mapArray;
}

