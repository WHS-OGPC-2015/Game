#include "MainMenu.h"

MainMenu::MainMenu()
{
    Manager = new MenuManager;
    Menu myMenu(ofVec2f(0,0));
    Manager->addTexture("DefaultQuitButton", "NormalQuitButton.png");
    Manager->addTexture("HoveredQuitButton", "HoveredQuitButton.png");
    Manager->addTexture("PressedQuitButton", "ClickedQuitButton.png");
    Manager->addFont("NormalFont", "MySimpleFont.ttf", 12);

    MenuEntity *exitButton;
    exitButton = new SimpleButton(
                        ofVec2f(900,0),
                        Manager->getTexturePointer("DefaultQuitButton"),
                        Manager->getTexturePointer("ClickedQuitButton")
                                  );

    myMenu.addEntity(*exitButton, "ExitButton");
    Manager->addMenu(myMenu, "NormalMenu");
}

void MainMenu::draw()
{
    Manager->draw();
}
void MainMenu::update(ofVec2f& mousePos, bool& clicked)
{
     Manager->update(mousePos, clicked);
}
