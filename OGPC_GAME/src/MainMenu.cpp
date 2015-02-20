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
    Manager->addTexture("BlueButton", "BlueButton.png");
    Manager->addTexture("ClickedBlueButton", "ClickedBlueButton.png");

    Manager->addFont("NormalFont", "MySimpleFont.ttf", 12); // adding font

    MenuEntity *exitButton; // the exit button
    exitButton = new SimpleButton(
                            ofVec2f(900,300),
                            Manager->getTexturePointer("DefaultQuitButton"),
                            Manager->getTexturePointer("PressedQuitButton")
                                  );

    MenuEntity *orangeBG; // background
    orangeBG = new MenuBackground(
                            ofVec2f(512,384),
                            Manager->getTexturePointer("OrangeBackground")
                                  );

    MenuEntity *optionsButton; // options button
    optionsButton = new SimpleButton(
                            ofVec2f(400, 200),
                            Manager->getTexturePointer("BlueButton"),
                            Manager->getTexturePointer("ClickedBlueButton"),
                            Manager->getFontPointer("NormalFont"),
                            "OPTIONS"
                                    );

    opMenu.addEntity(*exitButton, "ExitButton");
    normalMenu.addEntity(*orangeBG, "normalBackground");
    normalMenu.addEntity(*optionsButton, "OptionsButton");
    Manager->addMenu(normalMenu, "NormalMenu");
    Manager->addMenu(opMenu, "OptionsMenu");
    defaultMenu = Manager->getMenuPointerByName("NormalMenu");
    defaultMenu->setActive();
    optionsMenu = Manager->getMenuPointerByName("OptionsMenu");
    optionsMenu->setInactive();


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
     if (defaultMenu->isActive() == true and optionsMenu->isActive() == false and defaultMenu->getEntityPointer("OptionsButton")->getEventDataBool() == true)
     {
         std::cout<< optionsMenu->isActive();
         optionsMenu->setActive();
     }
     else if (optionsMenu->isActive() == false)
     {

     }

}
