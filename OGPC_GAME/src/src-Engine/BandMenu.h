#pragma once
#include "ofMain.h"
#include "../src-MenuAPI/MenuInclude.h"

void createBandMenu(MenuManager* man, ofVec2f pos, ResourceManager res);

void resetBandMenuPositions(Menu& bandmenu, ofVec2f deltaPos);

