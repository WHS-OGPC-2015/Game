//
//  HoverButton.h
//  Game
//
//  Created by WilsonCS on 2/20/15.
//
//


#pragma once
#include "src-MenuAPI/MenuEntity.h"

class HoverButton : public MenuEntity //child of MenuEntity class
{
public:
    HoverButton(ofVec2f loc, ofTexture& norm, ofTexture& hov, ofTexture& fpressed, ofTexture& fclicked, ofTexture& fclickedHovered, ofTexture& fclickedPressed, ofTrueTypeFont& f, std::string text);//initialize button with position and textures and text
    HoverButton(ofVec2f loc, ofTexture& norm, ofTexture& hov, ofTexture& fpressed, ofTexture& fclicked, ofTexture& fclickedHovered, ofTexture& fclickedPressed);//initialize button with position and textures without text

    //!!!!!!functions not declared in MenuEntity but declared here are mostly totally non-usable!!!!!!
    void setPosition(ofVec2f);
    ofVec2f getPosition();

    void setButtonTextString(std::string);
    std::string getButtonTextString();
    //!!!!!!!!

    void update(ofVec2f& mousePos, bool& clicked);
    void draw();
    void update();


    void setClicked(bool b); // set the clicked value manually
    int getEventDataInt();//return 0-3 (0 = nothing, 1 = hovered, 2 = pressed, 3 = clicked) value

private:
    ofTexture* normal; //pointer to default texture
    ofTexture* hovered; // pointer to hovered texture
    ofTexture* pressed; // pointer to pressed texture
    ofTexture* clicked; //pointer to texture used on mouse click
    ofTexture* clickedHovered;// pointer to clicked and hovered texture
    ofTexture* clickedPressed;// pointer to clicked and pressed texture

    ofTrueTypeFont* font; //pointer to font for button text
    std::string text;//text to draw

    ofVec2f position;//position of the buttons center
    ofVec2f textureTLPos;//location of current top left corner of the texture
    ofVec2f textureBRPos;//location of current bottom right corner of the Texture
    bool nowClicked;//true if the button is currently in its clicked state
    bool nowHovered;// true if button is hovered
    bool nowPressed;// true if button is pressed


};
