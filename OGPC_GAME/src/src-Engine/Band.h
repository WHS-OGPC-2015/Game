#pragma once
#include "ofMain.h"
#include "Tile.h"
#include "../src-Game/Vec2i.h"
#include "../src-MenuAPI/MenuInclude.h"
#include "../XML/src/ofxXmlSettings.h"

class Band
{
public:

    Band(Tile btile);

    void Draw();
    void Update(ofVec2f& mousePos, bool& clicked, bool& pressed);
    void turnlyUpdate();
    int getClickedData(ofVec2f& mousePos, bool& clicked, bool& pressed);


    void setTexture(ofTexture& TN0, ofTexture& TN1, ofTexture& TN2 , ofTexture& TN3);
    void setTile(Tile T);
    int getIndex();
    vector<std::string> getTextureNames();

    void setBandMenu(Menu& fillme);

    void fillMenu();
    //these are all boring -- just sets, gets, and swaps
    int convertTo1dindex(ofVec2i v);

    void setIncarnation(bool b, std::string incarnName);
    bool getIncarnation();

    void setDiscipleNum(int i);
    void changeDiscipleNum(int i);
    int getDiscipleNum();

    vector<ofVec2i> getMoves();

    void swapIncognito();
    bool getIncognito();

    void setMinTiles(ofVec2i v);
    void setMaxTiles(ofVec2i v);

    void resetBandState();
    int getBandState();

    void switchSelect();
    bool getSelect();
    //until here

    void saveObjectData(ofxXmlSettings&);
    void loadObjectData(ofxXmlSettings&);

private:



    Tile* boundTile;
    ofVec2i boundTileCoords;
    int boundTileIndex;

    ofTexture* BandTextures[4]; // 0 = reg, 1 = incog, 2 = incarn, 3 = incog and incarn
    std::string TextureNames[4];


    int discipleNum;
    int begDisNum; // beginning disciple number -- doesn't change as opposed to disciple num

    bool incarnation;
    std::string incarnationName;

    bool incognito;

    int bandState;

    bool selected;

    ofVec2i extremeTiles[2]; // e.g., [(0,0),(100,100)] -- useful for  finding possible moves


    int movement;

    ofVec2f TLpos;
    ofVec2f BRpos;

    Menu* bandMenu;
    bool drawMenu;

    vector<int> possibleMoves;
};
