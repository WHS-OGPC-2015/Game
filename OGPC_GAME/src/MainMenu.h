#pragma once
#include "ofMain.h"
#include "src-MenuAPI/MenuInclude.h"

class MainMenu
{
public:
    MainMenu();
    void draw();
    void update(ofVec2f& mousePos, bool& clicked);

private:
   MenuManager *Manager;
};
