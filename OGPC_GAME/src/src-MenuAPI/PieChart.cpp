#include "PieChart.h"


PieChart::PieChart(double& tot, double& dep, double radi) : total(tot) : depVar(dep)
{
    rati = (depVar/total);
    rad = radi;
    pos = ofVec2f(0,0);
    resolution = 50;
    pi = 3.14159265359;
    for (int i = 0; i < resolution; i++)
    {
        vertecies.push_back(ofVec2f(rad * cos(2 * pi / resolution + pi / 2), -rad * sin(2 * pi / resolution + pi / 2)));
    }
}

PieChart::PieChart(double& tot, double& dep, double radi, ofVec2f posi) : total(tot) : depVar(dep)
{
    rati = (depVar/total);
    rad = radi;
    pos = posi;
    pi = 3.14159265359;
    for (int i = 0; i < resolution; i++)
    {
        vertecies.push_back(ofVec2f(rad * cos(2 * pi / resolution + pi / 2) + pos.x, -rad * sin(2 * pi / resolution + pi / 2) + pos.y));
    }
}

void PieChart::Update()
{
    rati = total/depVar;

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

