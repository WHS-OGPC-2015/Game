#include "MenuBackground.h"


MenuBackground::MenuBackground(ofVec2f loc, ofTexture& textu)
{
    position = loc;
    backTexture = &textu;
}

void MenuBackground::update()//MenuBackground doesn't update
{

}
void MenuBackground::update(ofVec2f& mousePos, bool& clicked)//MenuBackground doesn't update
{

}
void MenuBackground::draw()
{
    // draws at the top left corner
    backTexture->draw(ofVec2f(position.x - (backTexture->getWidth())/2, position.y - (backTexture->getHeight())/2));
}
bool MenuBackground::getEventDataBool()//no use
{

}
int MenuBackground::getEventDataInt()//not going to use this function, Dear Nathan
{

}


