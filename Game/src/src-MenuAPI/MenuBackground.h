#pragma once
#include "MenuEntity.h"

class MenuBackground : public MenuEntity
{
public:

	MenuBackground(ofVec2f loc, ofTexture& textu);//constrctor

	void update();
	void update(ofVec2f& mousePos, bool& clicked);

	void draw();

	bool getEventDataBool();
	int getEventDataInt();

private:
	ofTexture *backTexture;
	ofVec2f position;

};
