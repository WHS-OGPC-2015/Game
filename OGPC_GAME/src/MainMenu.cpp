#include "MainMenu.h"

MainMenu::MainMenu()
{
    Manager = new MenuManager; // creates a new Menumanager
    Menu opMenu(ofVec2f(0,0)); // creating the options menu
    Menu normalMenu(ofVec2f(0,0)); // creating the normal menu
    Menu credMenu(ofVec2f(0,0)); // creating credits menu
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
    Manager->addTexture("StartGameButtonNormal", "PlayButtonNormal.png");
    Manager->addTexture("StartGameButtonPressed", "PlayButtonPressed.png");
    Manager->addTexture("StartGameButtonHovered", "PlayButtonHovered.png");
    Manager->addTexture("CreditsBackground", "DolphinBackground.png");



    Manager->addFont("NormalFont", "MySimpleFont.ttf", 16); // adding font

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

    MenuEntity *orangeBG; // backgrounddefaultMenu->getPointerToChildByName<HoverButton>("OptionsButton");
    orangeBG = new MenuBackground(
                            ofVec2f(ofGetWindowWidth()/2,ofGetWindowHeight()/2),
                            Manager->getTexturePointer("OrangeBackground")
                                  );

    MenuEntity *optionsButton; // options button
    optionsButton = new HoverButton(
                            ofVec2f(ofGetWindowWidth()/2, 350),
                            Manager->getTexturePointer("BlueButton"),
                            Manager->getTexturePointer("HoveredBlueButton"),
                            Manager->getTexturePointer("PressedBlueButton"),
                            Manager->getTexturePointer("ClickedBlueButton"),
                            Manager->getTexturePointer("ClickedBlueButton"),
                            Manager->getTexturePointer("PressedClickedBlueButton"),
                            Manager->getFontPointer("NormalFont"),
                            "Options"
                                    );

    MenuEntity *creditsButton; // Credits
    creditsButton = new HoverButton(
                            ofVec2f(ofGetWindowWidth()/2, 500),
                            Manager->getTexturePointer("BlueButton"),
                            Manager->getTexturePointer("HoveredBlueButton"),
                            Manager->getTexturePointer("PressedBlueButton"),
                            Manager->getTexturePointer("ClickedBlueButton"),
                            Manager->getTexturePointer("ClickedBlueButton"),
                            Manager->getTexturePointer("PressedClickedBlueButton"),
                            Manager->getFontPointer("NormalFont"),
                            "Credits"
                                    );


    MenuEntity *SGButton;
    SGButton = new HoverButton(
                            ofVec2f(ofGetWindowWidth()/2, 200),
                            Manager->getTexturePointer("StartGameButtonNormal"),
                            Manager->getTexturePointer("StartGameButtonHovered"),
                            Manager->getTexturePointer("StartGameButtonPressed"),
                            Manager->getTexturePointer("StartGameButtonPressed"),
                            Manager->getTexturePointer("StartGameButtonPressed"),
                            Manager->getTexturePointer("StartGameButtonPressed")
                                    );

    MenuEntity *cancelButton;
    cancelButton = new HoverButton(
                            ofVec2f(ofGetWindowWidth()/2, 600),
                            Manager->getTexturePointer("BlueButton"),
                            Manager->getTexturePointer("HoveredBlueButton"),
                            Manager->getTexturePointer("PressedBlueButton"),
                            Manager->getTexturePointer("ClickedBlueButton"),
                            Manager->getTexturePointer("ClickedBlueButton"),
                            Manager->getTexturePointer("PressedClickedBlueButton"),
                            Manager->getFontPointer("NormalFont"),
                            "Cancel"
                                    );


    MenuEntity *dolphinBG; // options menu background
    dolphinBG = new MenuBackground(
                            ofVec2f(ofGetWindowWidth()/2,ofGetWindowHeight()/2),
                            Manager->getTexturePointer("DolphinBackground")
                                  );

    MenuEntity *creditsBG; // options menu background
    creditsBG = new MenuBackground(
                            ofVec2f(ofGetWindowWidth()/2,ofGetWindowHeight()/2),
                            Manager->getTexturePointer("CreditsBackground")
                                  );

    opMenu.addEntity(*dolphinBG, "DolphinBackground");
    opMenu.addEntity(*exitButton, "ExitButton");
    normalMenu.addEntity(*orangeBG, "NormalBackground");
    normalMenu.addEntity(*SGButton, "StartGameButton");
    normalMenu.addEntity(*optionsButton, "OptionsButton");
    normalMenu.addEntity(*creditsButton, "CreditsButton");
    credMenu.addEntity(*creditsBG, "CreditsBackground");
    credMenu.addEntity(*cancelButton, "CancelButton");
    Manager->addMenu(normalMenu, "NormalMenu");
    Manager->addMenu(opMenu, "OptionsMenu");
    Manager->addMenu(credMenu, "CreditsMenu");
    defaultMenu = Manager->getMenuPointerByName("NormalMenu");
    defaultMenu->setActive();
    optionsMenu = Manager->getMenuPointerByName("OptionsMenu");
    optionsMenu->setInactive();
    creditsMenu = Manager->getMenuPointerByName("CreditsMenu");
    creditsMenu->setInactive();
    Exit = optionsMenu->getPointerToChildByName<HoverButton>("ExitButton");
    OptionsBut = defaultMenu->getPointerToChildByName<HoverButton>("OptionsButton");
    StartGameButton = defaultMenu->getPointerToChildByName<HoverButton>("StartGameButton");
    Credits = defaultMenu->getPointerToChildByName<HoverButton>("CreditsButton");
    CancelBut = defaultMenu->getPointerToChildByName<HoverButton>("CancelButton");


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
     if (StartGameButton->getEventDataInt() > 2)
     {
         StartGameButton->setClicked(false);
         defaultMenu->setInactive();
     }
     Manager->update(mousePos, clicked, pressed);

}
