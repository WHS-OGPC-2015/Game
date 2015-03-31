#ifndef PAUSEMENU_H
#define PAUSEMENU_H
#include "../src-MenuAPI/MenuInclude.h"


class PauseMenu
{
    public:
        PauseMenu();

        void draw();
        void update();
        int xpos = ofGetWindowWidth()/3;
        int ypos = ofGetWindowWidth()/3;

    private:
        MenuManager* PauseManager; //different manager for pause menu
        Menu* regularMenu;
        Menu* optionsMenu;  //pointer to options menu
        HoverButton* Resume; // resume button
        HoverButton* Options; // options button
        HoverButton* Quit; //quit button
        bool pauseActive; //tells if the menu is displayed or not (if the game is paused or not)

};

#endif // PAUSEMENU_H
