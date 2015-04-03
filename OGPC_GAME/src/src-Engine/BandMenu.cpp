#include "BandMenu.h"

void createBandMenu(MenuManager* man, ofVec2f pos, ResourceManager* res)
{
    double consta = 100;
    double constb = 5;
    double constc = 5;
    double constd = 5;
    double conste = 20;

    int borderWidth = 5;
    Menu bandMenu(ofVec2f(0, 0));

    man->addTexture("BMBackground", res->getTexture("BMBackground"));

    man->addTexture("BMBreakUpButNormal", res->getTexture("BMBreakUpButNormal"));
    man->addTexture("BMBreakUpButHovered", res->getTexture("BMBreakUpButHovered"));
    man->addTexture("BMBreakUpButPressed", res->getTexture("BMBreakUpButPressed"));

    man->addTexture("BMIncogUpButNormal", res->getTexture("BMIncogUpButNormal"));
    man->addTexture("BMIncogUpButHovered", res->getTexture("BMIncogUpButHovered"));
    man->addTexture("BMIncogUpButPressed", res->getTexture("BMIncogUpButPressed"));

    man->addTexture("BMMoveUpButNormal", res->getTexture("BMMoveUpButNormal"));
    man->addTexture("BMMoveUpButHovered", res->getTexture("BMMoveUpButHovered"));
    man->addTexture("BMMoveUpButPressed", res->getTexture("BMMoveUpButPressed"));

    man->addFont("BMText", "MySimpleFont.ttf", 24);

    double halfmenuHeight = man->getTexturePointer("BMBackground").getHeight()/2;
    double halfmenuWidth = man->getTexturePointer("BMBackground").getWidth()/2;
    //---------------------------------------------------------------------------

    MenuEntity* bandBG;
    bandBG = new MenuBackground{
                    pos,
                    man->getTexturePointer("BMBackground"),
                    false
                     };



    MenuEntity* incarnName;Move
    incarnName = new TextBox{
                        "BAND_NAME"
                        ofVec2f(ofVec2f(pos.x, pos.y - halfmenuHeight + borderWidth),
                        man->getFontPointer("BMText")
                            };
    MenuEntity* discBox;
    discBox = new TextBox{
                        "Number of Disciples:"
                       ofVec2f(pos.x - constb, pos.y +  halfmenuHeight - borderWidth - consta /*a constant*/),
                        man->getFontPointer("BMText")
                            };

    MenuEntity* discNum;
    discNum = new TextBox{
                    "X",
                    ofVec2f(pos.x + constc, pos.y +  halfmenuHeight - borderWidth - consta),
                    man->getFontPointer("BMText")
                    };

    MenuEntity* BreakUp;
    BreakUp = new HoverButton{
                        ofVec2f(pos.x - (halfmenuWidth - borderWidth)/2, pos.y - borderWidth - constd),
                        man->getTexturePointer("BMBreakUpButNormal"),           // adding textures, we have done this before...
                        man->getTexturePointer("BMBreakUpButHovered"),
                        man->getTexturePointer("BMBreakUpButPressed"),
                        man->getTexturePointer("BMBreakUpButPressed"),
                        man->getTexturePointer("BMBreakUpButPressed"),
                        man->getTexturePointer("BMBreakUpButPressed")
                                };

    MenuEntity* MoveBut;
    MoveBut = new HoverButton{
                        ofVec2f(pos.x + (halfmenuWidth - borderWidth)/2, pos.y - borderWidth - constd),
                        man->getTexturePointer("BMMoveUpButNormal"),           // adding textures, we have done this before...
                        man->getTexturePointer("BMMoveUpButHovered"),
                        man->getTexturePointer("BMMoveUpButPressed"),
                        man->getTexturePointer("BMMoveUpButPressed"),
                        man->getTexturePointer("BMMoveUpButPressed"),
                        man->getTexturePointer("BMMoveUpButPressed")
                                };

    MenuEntity* IncogBut;
    IncogBut = new HoverButton{
                        ofVec2f(pos.x + (halfmenuWidth - borderWidth)/2, pos.y - borderWidth + conste),
                        man->getTexturePointer("BMIncogUpButNormal"),           // adding textures, we have done this before...
                        man->getTexturePointer("BMIncogUpButHovered"),
                        man->getTexturePointer("BMIncogUpButPressed"),
                        man->getTexturePointer("BMIncogUpButPressed"),
                        man->getTexturePointer("BMIncogUpButPressed"),
                        man->getTexturePointer("BMIncogUpButPressed")
                                } ;

    bandMenu.addEntity(*bandBG, "BandMenuBackground");
    bandMenu.addEntity(*incarnName, "IncarnationName");
    bandMenu.addEntity(*discBox, "DiscipleBox");
    bandMenu.addEntity(*discNum, "DiscipleNumber");
    bandMenu.addEntity(*BreakUp, "BreakUpButton");
    bandMenu.addEntity(*MoveBut, "MoveButton");
    bandMenu.addEntity(*IncogBut, "IncognitoButton");

    man->addMenu(bandMenu, "BandMenu");
}
