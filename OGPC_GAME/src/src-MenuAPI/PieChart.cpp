#include "PieChart.h"
#define pi 3.14159265359

PieChart::PieChart()
{
    resolution = 50;
    endingindeces[0] = 0;
    for (int i = 0; i < resolution; i++)
    {
        vertecies.push_back(ofVec2f(rad * cos(2 * pi / resolution + pi / 2), -rad * sin(2 * pi / resolution + pi / 2)));
    }
}

PieChart::PieChart(double tot, double dep, double radi, ofVec2f posi) : total(tot), depVar(dep)
{
    rati = (depVar/total);
    rad = radi;
    pos = posi;
    resolution = 50;
    for (int i = 0; i < resolution; i++)
    {
        vertecies.push_back(ofVec2f(rad * cos(2 * pi / resolution + pi / 2) + pos.x, -rad * sin(2 * pi / resolution + pi / 2) + pos.y));
    }
}


void PieChart::setVariables(double dub, double tot)
{
    depVar = dub;
    total = tot;
}

void PieChart::Update()
{
    rati = depVar/total;
    endingindeces[1] = rati * resolution + .5;
}

void PieChart::Draw()
{
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofSetColor(colors[0]);

    ofBeginShape();
        for (int i = endingindeces[0]; i < resolution; i++)
        {
            ofVertex(vertecies[i].x, vertecies[i].y);
        }
    ofEndShape();

    ofSetColor(colors[1])

    ofBeginShape();
        for (int i = endingindeces[0]; i < endingindeces[1]; i++)
        {
            ofVertex(vertecies[i].x, vertecies[i].y);
        }
    ofEndShape();
}

void PieChart::setRadius(double radi);
{
    double tempr = radi/rad;
    for (int i = 0; i < resolution; i++)
    {
       vertecies[i].x *= tempr;
       vertecies[i].y *= tempr;
    }
    rad = radi;
}

void PieChart::setPosition(ofVec2f posi)
{
    for (int i = 0; i < resolution; i++)
    {
        vertecies[i].x += (posi - pos);
        vertecies[i].y += (posi - pos);
    }
    pos = posi;

}

void PieChart::setColor(int i, ofColor col)
{
    if (i == 0 or i == 1)
    {
        colors[i] = col;
    }
}

void PieChart::setColor(ofColor cola, ofColor colb)
{
    colors[0] = cola;
    colors[1] = colb;
}
