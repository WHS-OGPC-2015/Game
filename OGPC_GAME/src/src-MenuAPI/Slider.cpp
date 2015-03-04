#include "Slider.h"

Slider::Slider(ofVec2f p, ofTexture& bg, ofTexture& slider, int M, int m, int start)
{
    background = &bg;
    sliderThing = &slider;
    currentValue = start;
    maxValue = M;
    minValue =m;
    position = p;
    cordScale = background->getWidth()/(maxValue-minValue);
    std::cout << cordScale;
}

bool Slider::getEventDataBool(){}//here so its not abstract

int Slider::getEventDataInt()
{
    return currentValue;
}

void Slider::update(){}//also just here to prevent error

void Slider::update(ofVec2f& mousePos, bool& clicked, bool& pressed)
{
    std::cout<<"here3";
    if(clicked)
    {
        std::cout<<"here2";
        //nowClicked = !nowClicked; //toggle clicked status

            //if it is...test to see if a point is not inside the button
        if(mousePos.x < bgTLPos.x ||
           mousePos.y < bgTLPos.y ||
           mousePos.x > bgBRPos.x ||
           mousePos.y > bgBRPos.y   )
        {
            std::cout<<"here1";
        }
        else
        {
            std::cout<<"here";
            std::cout << currentValue << std::endl;
            currentValue = ((mousePos.x - bgTLPos.x)+minValue)*cordScale;
        }
    }
    if(currentValue > maxValue)
    {
        currentValue = maxValue;
    }
    else if(currentValue < minValue)
    {
        currentValue = minValue;
    }
}

void Slider::draw()
{
        //reset BR and TL corner positions for collision
        bgTLPos = ofVec2f((position.x-(background->getWidth()/2)), (position.y-(background->getHeight()/2)));
        bgBRPos = ofVec2f((bgTLPos.x+(background->getWidth())), (bgTLPos.y+(background->getHeight())));
        background->draw(bgTLPos);
        sliderThing->draw(ofVec2f(bgTLPos.x+((currentValue-minValue)*cordScale)-sliderThing->getWidth()/2, (bgTLPos.y+((background->getHeight()/2)-(sliderThing->getHeight()/2)))));

        ofCircle(bgTLPos, 10);
        ofCircle(bgBRPos, 10);


}
