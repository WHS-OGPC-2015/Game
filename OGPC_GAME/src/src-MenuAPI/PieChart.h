#pragma once
#include "MenuEntity.h"

class PieChart : public MenuEntity
{
public:
    PieChart();
    PieChart(double tot, double dep, double radi, ofVec2f posi);

    void setVariables(double dub, double tot);
    void Update();
    void Draw();
    void setRadius(double radi);
    void setPosition(ofVec2f posi);
    void setColor(int i, ofColor col);
    void setColor(ofColor cola, ofColor colb);



private:

    double total;
    double depVar;
    double rati;
    ofColor colors[2];
    double rad;
    int resolution;
    ofVec2f pos;
    int endingindeces[2];
    vector<ofVec2f> vertecies;

};
