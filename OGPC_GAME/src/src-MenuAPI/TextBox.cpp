#include "TextBox.h"

TextBox::TextBox(std::string str, ofVec2f posi, ofTrueTypeFont& f)
{
    text = str;
    position = posi;
    font = &f;
}

void TextBox::TextBox()
{
}

void TextBox::Update()
{
}

void TextBox::draw()
{
   if(font != NULL)
    {
        //center the text
        font->drawString(text, position.x - font->stringWidth(text)/2, position.y - font->stringHeight(text)/2);
    }
}
void TextBox::setText(std::string str)
{
    text = str;
}

void TextBox::setPosition(posi)
{
    position = posi;
}

void TextBox::setFont(ofTrueTypeFont& f)
{
    font = &f;
}
