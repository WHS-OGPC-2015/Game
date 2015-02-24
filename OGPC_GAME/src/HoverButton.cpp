//
//  HoverButton.cpp
//  Game
//
//  Created by WilsonCS on 2/20/15.
//
//

#include "HoverButton.h"

HoverButton::HoverButton(ofVec2f loc, ofTexture& norm, ofTexture& hov, ofTexture& fpressed, ofTexture& fclicked, ofTexture& fclickedHovered, ofTexture& fclickedPressed, ofTrueTypeFont& f, std::string t)
{

    position = loc;
    normal = &norm;
    hovered = &hov;
    pressed = &fpressed;
    clickedHovered = &fclickedHovered;
    clickedPressed = &fclickedPressed;
    clicked = &fclicked;
    font = &f;
    requiresMouseData = true;//this class will need data about the mouse to function
    nowClicked = false;
    text = t;

}

HoverButton::HoverButton(ofVec2f loc, ofTexture& norm, ofTexture& hov, ofTexture& fpressed, ofTexture& fclicked, ofTexture& fclickedHovered, ofTexture& fclickedPressed)
{

    position = loc;
    normal = &norm;
    hovered = &hov;
    pressed = &fpressed;
    clickedHovered = &fclickedHovered;
    clickedPressed = &fclickedPressed;
    clicked = &fclicked;
    font = NULL;//set font pointer to NULL if there is no text
    requiresMouseData = true;//this class will need data about the mouse to function
    nowClicked = false;
    text = "";

}

void HoverButton::setButtonTextString(std::string newString)
{
    text = newString;
}

std::string HoverButton::getButtonTextString()
{
    return text;
}

void HoverButton::update(ofVec2f& mousePos, bool& clicked, bool& pressed)
{

    //test to see if the mouse is clicked
    if(clicked == true)
    {
        //nowClicked = !nowClicked; //toggle clicked status

        //if it is...test to see if a point is not inside the button
        if(mousePos.x < textureTLPos.x ||
           mousePos.y < textureTLPos.y ||
           mousePos.x > textureBRPos.x ||
           mousePos.y > textureBRPos.y   )
        {
        }
        else//if the points not outside its inside
        {
            nowClicked = !nowClicked; //toggle clicked status
        }
    }
    if (pressed == true) // same for pressed..
    {
        nowHovered == false; // prevents hovered and pressed from being true at the same time
        if(mousePos.x < textureTLPos.x ||
           mousePos.y < textureTLPos.y ||
           mousePos.x > textureBRPos.x ||
           mousePos.y > textureBRPos.y   )
        {
        }
        else
        {
            nowPressed = !nowPressed; //toggle pressed status
        }
    }
    else if (pressed == false)
    {
        nowPressed = false;// if the mouse button is released off of the button, hovered shall be false
        if(mousePos.x < textureTLPos.x ||
           mousePos.y < textureTLPos.y ||
           mousePos.x > textureBRPos.x ||
           mousePos.y > textureBRPos.y   )
        {
            nowHovered = false; // if the mouse if off of the button, it's not hovering
        }
        else//if the points not outside its inside
        {
            nowHovered = !nowHovered; //toggle clicked status
        }
    }

}

void HoverButton::draw()
{

    //the BR/TL positions are for keeping track of the coordinates for purposes
    //of the mouse collision logic in update()
    if(nowClicked == true)//if the button has been clicked draw that texture
    {
        //reset BR and TL corner positions for collision

        if (nowPressed == true)
        {

        }
        else if (nowHovered == true)
        {
            textureTLPos = ofVec2f((position.x-(clickedHovered->getWidth()/2)), (position.y-(clickedHovered->getHeight()/2)));
            textureBRPos = ofVec2f((textureTLPos.x+(clickedHovered->getWidth())), (textureTLPos.y+(clickedHovered->getHeight())));
            clickedHovered->draw(textureTLPos);
        }
        else
        {
            textureTLPos = ofVec2f((position.x-(clicked->getWidth()/2)), (position.y-(clicked->getHeight()/2)));
            textureBRPos = ofVec2f((textureTLPos.x+(clicked->getWidth())), (textureTLPos.y+(clicked->getHeight())));
            clicked->draw(textureTLPos);
        }
    }
    else if (nowPressed == true)
    {
        textureTLPos = ofVec2f((position.x-(pressed->getWidth()/2)), (position.y-(pressed->getHeight()/2)));
        textureBRPos = ofVec2f((textureTLPos.x+(pressed->getWidth())), (textureTLPos.y+(pressed->getHeight())));
        pressed->draw(textureTLPos);
    }
    else if (nowHovered == true)
    {
        textureTLPos = ofVec2f((position.x-(hovered->getWidth()/2)), (position.y-(hovered->getHeight()/2)));
        textureBRPos = ofVec2f((textureTLPos.x+(hovered->getWidth())), (textureTLPos.y+(hovered->getHeight())));
        hovered->draw(textureTLPos);
    }
    else//otherwise draw the non-clicked texture
    {
        //reset BR and TL corner positions for collision
        textureTLPos = ofVec2f((position.x-(normal->getWidth()/2)), (position.y-(normal->getHeight()/2)));
        textureBRPos = ofVec2f((textureTLPos.x+(normal->getWidth())), (textureTLPos.y+(normal->getHeight())));
        normal->draw(textureTLPos);
    }
    if(font != NULL)
    {
        //center the text
        font->drawString(text, textureTLPos.x+((normal->getWidth()-(font->stringWidth(text)))/2), textureTLPos.y+((normal->getHeight()-(font->stringHeight(text)))/2));
    }

}

void HoverButton::update()
{
    //this is just here so the compiler doesn't complain when calling update(void) in menu
}

int HoverButton::getUseEventDataInt()
{
   if(nowClicked == true)
    {
        if (nowPressed == true)
        {
            return 5;
        }
        else if (nowHovered == true)
        {
            return 4;
        }
        else
        {
            return 3;
        }
    }
    else if (nowPressed == true)
    {
        return 2;
    }
    else if (nowHovered == true)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int HoverButton::getEventDataInt()
{

}

void HoverButton::setClicked(bool b)
{
    nowClicked == b;
}
