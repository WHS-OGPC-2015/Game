#pragma once
#include "ofMain.h"
#include "MenuEntity.h"

class Slider : public MenuEntity
{
public:

    Slider(ofVec2f position, ofTexture& bg, ofTexture& slider, int M, int m, int start);

    bool getEventDataBool();//so that the class is not abstract
    int getEventDataInt();//returns slider value

    void draw();
    void update(ofVec2f&, bool&, bool&);
    void update();//so that the class is not abstract

private:
    int currentValue, maxValue, minValue;
    float cordScale;
    ofVec2f position;
    ofTexture* background;
    ofTexture* sliderThing;
    ofVec2f bgTLPos, bgBRPos;



};

