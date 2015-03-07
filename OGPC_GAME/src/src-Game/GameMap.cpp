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

    mapSize = ofVec2i(20,20);
    Tile mapArray[mapSize.x][mapSize.y];

    for (int i = 0; i < mapSize.x; i ++)
    {
        for (int j = 0; j < mapSize.y; j ++)
        {
             mapArray[i][j].aset = false;
             mapArray[i][j].altitude = -5;

        }
    }


//    seednum = maximize(sqrt((mapSize.x + mapSize.y)/2) + ofRandom(0,3) - 1, 1);
    seednum = 1;
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
    for (int i = 0; i < mapSize.x; i++)
    {
        for (int j = 0; j < mapSize.y; j++)
        {
            std::cout << mapArray[i][j].altitude << "  ";
            mapTiles.push_back(mapArray[i][j]);
        }
        std::cout << std::endl << std::endl;
    }
}

