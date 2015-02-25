#include "MainMenu.h"

MainMenu::MainMenu()
{
    Manager = new MenuManager; // creates a new Menumanager
    Menu opMenu(ofVec2f(0,0)); // creating the options menu
    Menu normalMenu(ofVec2f(0,0)); // creating the normal menu
    Manager->addTexture("DefaultQuitButton", "NormalQuitButton.png"); // adding textures
    Manager->addTexture("HoveredQuitButton", "HoveredQuitButton.png");
    Manager->addTexture("ClickedQuitButton", "ClickedQuitButton.png");
    Manager->addTexture("PressedQuitButton", "PressedQuitButton.png");
    Manager->addTexture("OrangeBackground", "OrangeBackground.png");
    Manager->addTexture("BlueButton", "BlueButton.png");
    Manager->addTexture("ClickedBlueButton", "ClickedBlueButton.png");
    Manager->addTexture("PressedBlueButton", "PressedBlueButton.png");
    Manager->addTexture("HoveredBlueButton", "HoveredBlueButton.png");
    Manager->addTexture("PressedClickedBlueButton", "PressedClickedBlueButton.png");
    Manager->addTexture("DolphinBackground", "DolphinBackground.png");


    Manager->addFont("NormalFont", "MySimpleFont.ttf", 12); // adding font

    MenuEntity *exitButton; // the exit button
    exitButton = new HoverButton(
                            ofVec2f(900,300),
                            Manager->getTexturePointer("DefaultQuitButton"),
                            Manager->getTexturePointer("HoveredQuitButton"),
                            Manager->getTexturePointer("PressedQuitButton"),
                            Manager->getTexturePointer("ClickedQuitButton"),
                            Manager->getTexturePointer("ClickedQuitButton"),
                            Manager->getTexturePointer("ClickedQuitButton")
                                  );

    MenuEntity *orangeBG; // background
    orangeBG = new MenuBackground(
                            ofVec2f(512,384),
                            Manager->getTexturePointer("OrangeBackground")
                                  );

    MenuEntity *optionsButton; // options button
    optionsButton = new HoverButton(
                            ofVec2f(400, 200),
                            Manager->getTexturePointer("BlueButton"),
                            Manager->getTexturePointer("HoveredBlueButton"),
                            Manager->getTexturePointer("PressedBlueButton"),
                            Manager->getTexturePointer("ClickedBlueButton"),
                            Manager->getTexturePointer("ClickedBlueButton"),
                            Manager->getTexturePointer("PressedClickedBlueButton"),
                            Manager->getFontPointer("NormalFont"),
                            "OPTIONS"
                                    );

    MenuEntity *dolphinBG; // options menu background
    dolphinBG = new MenuBackground(
                            ofVec2f(512,384),
                            Manager->getTexturePointer("DolphinBackground")
                                  );

    opMenu.addEntity(*dolphinBG, "DolphinBackground");
    opMenu.addEntity(*exitButton, "ExitButton");
    normalMenu.addEntity(*orangeBG, "normalBackground");
    normalMenu.addEntity(*optionsButton, "OptionsButton");
    Manager->addMenu(normalMenu, "NormalMenu");
    Manager->addMenu(opMenu, "OptionsMenu");
    defaultMenu = Manager->getMenuPointerByName("NormalMenu");
    defaultMenu->setActive();
    optionsMenu = Manager->getMenuPointerByName("OptionsMenu");
    optionsMenu->setInactive();
    Exit = optionsMenu->getPointerToChildByName<HoverButton>("ExitButton");
    OptionsBut = defaultMenu->getPointerToChildByName<HoverButton>("OptionsButton");

}

void MainMenu::draw()
{
    Manager->draw();
}
void MainMenu::update(ofVec2f& mousePos, bool& clicked, bool& pressed)
{

     if(Exit->getEventDataInt() > 2)
     {
         Exit->setClicked(false);
         OptionsBut->setClicked(false);
         optionsMenu->setInactive();
         defaultMenu->setActive();
     }
     else if (defaultMenu->isActive() == true and optionsMenu->isActive() == false and OptionsBut->getEventDataInt() > 2)
     {
         optionsMenu->setActive();
         defaultMenu->setInactive();
     }
     Manager->update(mousePos, clicked, pressed);

}
