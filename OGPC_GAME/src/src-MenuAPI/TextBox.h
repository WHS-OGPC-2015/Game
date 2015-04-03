
#pragma once
#include "MenuEntity.h"

class TextBox : MenuEntity
{
public:
    TextBox(std::string str, ofVec2f posi, ofTrueTypeFont& f);
    TextBox();
    void update();
    void draw();

    void addPosition(ofVec2f dpos);
    void setText(std::string str);
    void setPosition(ofVec2f posi);
    void setFont(ofTrueTypeFont& f);

private:
    std::string text;
    ofVec2f position;
    ofTrueTypeFont* font;

};
