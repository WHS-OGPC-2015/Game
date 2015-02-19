#include "MainMenu.h"

MainMenu::MainMenu()
{
    Manager = new MenuManager; // creates a new Menumanager
    Menu opMenu(ofVec2f(0,0)); // creating the options menu
    Menu normalMenu(ofVec2f(0,0)); // creating the normal menu
    Manager->addTexture("DefaultQuitButton", "NormalQuitButton.png"); // adding textures
    Manager->addTexture("HoveredQuitButton", "HoveredQuitButton.png");
    Manager->addTexture("PressedQuitButton", "ClickedQuitButton.png");
     Manager->addTexture("OrangeBackground", "OrangeBackground.png");
    Manager->addFont("NormalFont", "MySimpleFont.ttf", 12); // adding font

    MenuEntity *exitButton; // the exit button
    exitButton = new SimpleButton(
                        ofVec2f(900,100),
                        Manager->getTexturePointer("DefaultQuitButton"),
                        Manager->getTexturePointer("PressedQuitButton")
                                  );
    MenuEntity *orangeBG;
    orangeBG = new MenuBackground(
                            ofVec2f(512,384),
                            Manager->getTexturePointer("OrangeBackground")
                                  );

    opMenu.addEntity(*exitButton, "ExitButton");
    normalMenu.addEntity(*orangeBG, "normalBackground");
    Manager->addMenu(opMenu, "OptionsMenu");
    Manager->addMenu(normalMenu, "NormalMenu");
    optionsMenu = Manager->getMenuPointerByName("OptionsMenu");
    optionsMenu->setInactive();
    defaultMenu = Manager->getMenuPointerByName("NormalMenu");
}

void MainMenu::draw()
{
    Manager->draw();
}
void MainMenu::update(ofVec2f& mousePos, bool& clicked)
{
     Manager->update(mousePos, clicked);
     if(optionsMenu->getEntityPointer("ExitButton")->getEventDataBool() == true)
     {
         optionsMenu->setInactive();
     }
}
