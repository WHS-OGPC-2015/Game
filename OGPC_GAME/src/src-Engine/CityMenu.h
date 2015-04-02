#pragma once
#include "ofMain.h"
#include "../src-MenuAPI/MenuInclude.h"

void createCityMenu(MenuManager* man, ofVec2f pos);

void resetCityMenuPositions(Menu& citymenu, ofVec2f deltaPos);
