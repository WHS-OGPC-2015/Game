#include "MenuBackground.h"


MenuBackground::MenuBackground(ofVec2f loc, ofTexture& textu)
{
    position = loc;
    backTexture = &textu;
}

void MenuBackground::update()//MenuBackground doesn't update
{

}
void MenuBackground::update(ofVec2f& mousePos, bool& clicked, bool& pressed)//MenuBackground doesn't update
{

}
void MenuBackground::draw()
{
    // draws the center at the position
    backTexture->draw(0,0,ofGetWindowWidth(), ofGetWindowHeight()) ;
}
bool MenuBackground::getEventDataBool()//no use
{

}
int MenuBackground::getEventDataInt()//not going to use this function, Dear Nathan
{

}


