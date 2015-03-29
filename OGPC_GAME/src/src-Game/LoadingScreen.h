#pragma once
#include "ofMain.h"
void draw()
{
    std::vector<
}

class rectObject
{
public:
    rectObject(ofVec2f location, ofVec2f w)
    {
        position = location;
        width = w;
    }

    void draw()
    {
        ofRect(position.x, position.y, width, height);
    }

    void addLength(int W)
    {
        width+=w;
    }
    int width, height;
    ofVec2f position;

};

class LoadingScreen
{
public:
    LoadingScreen(int g, int n, int w)
    {
        screenSize = ofVec2f(ofGetWindowWidth(), ofGetWindowHeight());
        gap = g;
        num = n;
        width = w;
        currentWidth = 0;
        currentSide = 1;  //1 = top 2 = right 3 = bottom 4= left;
        it = 2;
    }
    void draw()
    {
        ofSetColor(176, 136, 31);
        for(int ii = 0; ii < segs.size(); ii++)
        {
            segs[ii].draw();
        }
    }
    void update(float Progress)
    {
        if(first)
        {
            randLength = ofRandom(ofGetWindowHeight()/(it-1), ofGetWindowHeight()/it);
        }
    }
private:
    std::vector<rectObject> segs;
    ofVec2f screenSize;
    int gap;
    int num;
    int width;
    int currentIndent;
    int currentSide;
    int randLength;
    int it;
};
