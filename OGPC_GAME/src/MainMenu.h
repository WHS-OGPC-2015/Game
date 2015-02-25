#pragma once
#include "ofMain.h"
#include "src-MenuAPI/MenuInclude.h"


class MainMenu
{
public:
    MainMenu();
    void draw();
    void update(ofVec2f& mousePos, bool& clicked, bool& pressed);
    void switchActive();
    bool getActive();

private:
   MenuManager *Manager;
   Menu* optionsMenu;
   Menu* defaultMenu;
   bool active;
   HoverButton* Exit;
   HoverButton* OptionsBut;
   HoverButton* StartGameButton;
};
