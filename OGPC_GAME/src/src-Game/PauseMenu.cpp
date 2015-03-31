#include "PauseMenu.h"


PauseMenu::PauseMenu()
{
    pauseActive = true; //activating the pause menu

    PauseManager = new MenuManager;
    Menu defaultMenu(ofVec2f(xpos, ypos));
    Menu opMenu(ofVec2f(xpos, ypos));
                                                                    //adding textures and fonts to the manager
    PauseManager->addTexture("StandardNormal", "StandardNormal.png");
    PauseManager->addTexture("StandardPressed", "StandardPressed.png");
    PauseManager->addTexture("StandardHovered", "StandardHovered.png");

    PauseManager->addTexture("OrangeBackground" , "OrangeBackground.png");
    PauseManager->addFont("NormalFont", "MySimpleFont.ttf", 16);

    //making buttons for the menu
    MenuEntity *background; // Orange Background
    background = new MenuBackground(
                            ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()/2), // in the middle of the window
                            PauseManager->getTexturePointer("OrangeBackground")
                                  );
    MenuEntity *ResumeBut;
    ResumeBut = new HoverButton(
                            ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()/3),
                            PauseManager->getTexturePointer("StandardNormal.png"),
                            PauseManager->getTexturePointer("StandardHovered.png"),
                            PauseManager->getTexturePointer("StandardPressed.png"),
                            PauseManager->getTexturePointer("StandardPressed.png"),
                            PauseManager->getTexturePointer("StandardPressed.png"),
                            PauseManager->getTexturePointer("StandardPressed.png"),
                            PauseManager->getFontPointer("NormalFont"),
                                ""
                                );
    MenuEntity *OptionsBut;
    OptionsBut = new HoverButton(
                            ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()/3),
                            PauseManager->getTexturePointer("StandardNormal.png"),
                            PauseManager->getTexturePointer("StandardHovered.png"),
                            PauseManager->getTexturePointer("StandardPressed.png"),
                            PauseManager->getTexturePointer("StandardPressed.png"),
                            PauseManager->getTexturePointer("StandardPressed.png"),
                            PauseManager->getTexturePointer("StandardPressed.png"),
                            PauseManager->getFontPointer("NormalFont"),
                                 ""
                                );

    MenuEntity *QuitBut;
    QuitBut = new HoverButton(
                            ofVec2f(ofGetWindowWidth()/2, ofGetWindowHeight()/3),
                            PauseManager->getTexturePointer("StandardNormal.png"),
                            PauseManager->getTexturePointer("StandardHovered.png"),
                            PauseManager->getTexturePointer("StandardPressed.png"),
                            PauseManager->getTexturePointer("StandardPressed.png"),
                            PauseManager->getTexturePointer("StandardPressed.png"),
                            PauseManager->getTexturePointer("StandardPressed.png"),
                            PauseManager->getFontPointer("NormalFont"),
                              ""
                                );

    //adding buttons to the menu and the options menu to the manager as well

    defaultMenu.addEntity(*background , "PauseBackground");
    defaultMenu.addEntity(*ResumeBut , "ResumeButton");
    defaultMenu.addEntity(*OptionsBut , "OptionsButton");
    defaultMenu.addEntity(*QuitBut , "QuitButton");

    PauseManager->addMenu(defaultMenu , "DefaultMenu");

    regularMenu = PauseManager->getMenuPointerByName("DefaultMenu");
    regularMenu->setActive();

    Resume = regularMenu->getPointerToChildByName<HoverButton>("ResumeButton");
    Options = regularMenu->getPointerToChildByName<HoverButton>("OptionsButton");
    Quit = regularMenu->getPointerToChildByName<HoverButton>("QuitButton");


}

void PauseMenu::draw()
{
    std::cout << "CUNT" << std::endl;
    if(pauseActive == true)
    {
        std::cout << "CUNT" << std::endl;
        PauseManager->draw();
    }
}


