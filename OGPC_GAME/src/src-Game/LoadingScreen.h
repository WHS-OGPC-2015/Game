#pragma once
#include "ofMain.h"


class rectObject
{
public:
    rectObject(ofVec2f location, int w, int h)
    {
        position = location;
        width = w;
        height = h;
    }

    void draw()
    {
        ofRect(position.x, position.y, width, height);
    }

    int width, height;
    ofVec2f position;

};

class LoadingScreen
{
public:
    LoadingScreen(int iterations, int s, ofVec2f start, int w)
    {
        screenSize = ofVec2f(ofGetWindowWidth(), ofGetWindowHeight());
        //gap = g;
        //num = n;
        width = w;
        direction = 1;  //1 = right 2 = left 3 = down 4= up;
        speed = s;
        maxIt = iterations;
        it = 2;
        speed = 1;
        pos = start;
    }
    void draw()
    {
        ofBackground(79, 67, 44);
        ofSetColor(176, 136, 31);
        for(int ii = 0; ii < segs.size(); ii++)
        {
            segs[ii].draw();
        }
    }
    bool update()
    {
        if(first)
        {
            if(segs.size() > 1)
            {
                if(segs[segs.size()-1].width == width)
                {
                    pos.y += segs[segs.size()-1].height;
                }
                else
                {
                    pos.x += segs[segs.size()-1].width;
                }
            }

            it++;
            randLength = ofRandom(ofGetWindowHeight()/it, ofGetWindowHeight()/(it-1));
            direction = ofRandom(1, 3);

            if(direction == 1)
            {
                rectObject temp(pos, width, 0);
                segs.push_back(temp);
            }
            else if(direction == 2)
            {
                rectObject temp(pos, width, 0);
                segs.push_back(temp);
            }
            else if(direction == 3)
            {
                rectObject temp(pos, 0, width);
                segs.push_back(temp);
            }
            else if(direction == 4)
            {
                rectObject temp(pos, 0, width);
                segs.push_back(temp);
            }

            first = false;
        }
        if(segs[segs.size()-1].height < randLength ||
           segs[segs.size()-1].width < randLength)
        {
            if(direction == 1)
            {
                segs[segs.size()-1].width += speed;
            }
            else if(direction == 2)
            {
                segs[segs.size()-1].width -= speed;
            }
            else if(direction == 3)
            {
                segs[segs.size()-1].height -= speed;
            }
            else if(direction == 4)
            {
                segs[segs.size()-1].height += speed;
            }

        }
        else
        {
            first = true;
        }
        if(it == maxIt)
        {
            return false;
        }
        return true;

    }
private:
    std::vector<rectObject> segs;
    ofVec2f screenSize;
    int gap;
    int num;
    int width;
    int currentIndent;
    int direction;
    int randLength;
    int it;     //current iteration
    int maxIt;  //maxinum number of iterations
    bool first;
    int speed;
    ofVec2f pos;
};

