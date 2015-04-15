#include "UtilMenus.h"

void createNextTurnMenu(MenuManager* man, ofVec2f pos)
{
    Menu turnMenu(ofVec2f(0, 0));

    double halfMenuHeight = man->getTexturePointer("TMBackground").getHeight()/2;
    double halfMenuWidth = man->getTexturePointer("TMBackground").getWidth()/2;
    //---------------------------------------------------------------------------

    MenuEntity* menuBG;
    menuBG = new MenuBackground(
                    ofVec2f(ofGetScreenWidth()/2, ofGetScreenHeight()-150),
                     man->getTexturePointer("TMBackground"),
                    false
                     );

    MenuEntity* nextTurnBut;
    nextTurnBut = new HoverButton(
                        ofVec2f(pos.x + (halfMenuWidth)/2, pos.y+(halfMenuWidth)/2),
                        man->getTexturePointer("turnButNormal"),           // adding textures, we have done this before...
                        man->getTexturePointer("turnButHovered"),
                        man->getTexturePointer("turnButPressed"),
                        man->getTexturePointer("turnButPressed"),
                        man->getTexturePointer("turnButPressed"),
                        man->getTexturePointer("turnButPressed")
                                );

    //turnMenu.addEntity(*menuBG, "TMBackground");
    turnMenu.addEntity(*nextTurnBut, "NextTurnButton");

   man->addMenu(turnMenu, "TurnMenu");
}

