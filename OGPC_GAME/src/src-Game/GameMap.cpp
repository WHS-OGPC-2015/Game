#include "GameMap.h"


int wfunc(int x)
{
    int arraylength = 20;
    return fabs(fabs(x-(arraylength-1))-arraylength);
}

GameMap::GameMap()
{
    int seedx = ofRandom(0,20);
    int seedy = ofRandom(0,20);
    ofVec2f focus(seedx, seedy);
    mapArray[focus.x][focus.y].setAltitude(5);
    bool done = false;
    int rando;
    int highnum;
    bool donecheck;


    for (int i = 0; i < 20; i ++)
    {
        for (int j = 0; j < 20; j ++)
        {
             mapArray[i][j].aset = false;
             mapArray[i][j].altitude = -5;
        }
    }




    while (done == false)
    {
        donecheck = true;
        highnum = 0;
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                if (mapArray[i][j].aset == true and mapArray[i][j].altitude > highnum)
                {
                    if (        mapArray[wfunc(i-1)][wfunc(j-1)].aset == false
                                or mapArray[wfunc(i-1)][wfunc(j+1)].aset == false
                                or mapArray[wfunc(i+1)][wfunc(j-1)].aset == false
                                or mapArray[wfunc(i+1)][wfunc(j+1)].aset == false
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
        for (int i = -1; i < 2; i += 2)
        {

        for (int j = -1; j < 2; j += 2)
            if (mapArray[wfunc(focus.x + i)][wfunc(focus.y + j)].aset == false)
            {
                if (rando >= 0 and rando < 60)
                {
                    mapArray[wfunc(focus.x + i)][wfunc(focus.y + j)].setAltitude(mapArray[focus.x][focus.y].altitude - 1);
                }
                else if (rando >= 60 and rando < 80)
                {
                    mapArray[wfunc(focus.x + i)][wfunc(focus.y + j)].setAltitude(mapArray[focus.x][focus.y].altitude - 2);
                }
                else if (rando >= 60 and rando < 80)
                {
                    mapArray[wfunc(focus.x + i)][wfunc(focus.y + j)].setAltitude(mapArray[focus.x][focus.y].altitude);
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

