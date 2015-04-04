//#include "Band.h"
//#include "sstream"
//
//
//int Band::convertTo1dindex(ofVec2i v)
//{
//    return (v.y * (fabs(extremeTiles[1].x - extremeTiles[0].x)) + v.x);
//}
//
//Band::Band()
//{
//    incognito = false;
//    incarnation = false;
//    selected = false;
//    begDisNum = 10; // arbitrary
//    movement = 7; // arbitrary
//    discipleNum = begDisNum;
//    incarnationName = "";
//    drawMenu = false;
//
//}
//
//void Band::resetBandState()
//{
//    if (incognito == true)
//    {
//        if (incarnation == true)
//        {
//            bandState = 3;
//        }
//        else
//        {
//            bandState = 1;
//        }
//    }
//    else if (incarnation == true)
//    {
//       bandState = 2;
//    }
//    else
//    {
//        bandState = 0;
//    }
//}
//
//int Band::getBandState()
//{
//    return bandState;
//}
//
//
//void Band::Draw()
//{
////    BandTextures[bandState]->draw();
//
//    TLpos = ofVec2f(boundTile.getLocation().x - BandTextures[bandState]->getWidth() /2, boundTile.getLocation().y - BandTextures[bandState]->getHeight() /2);
//    BRpos = ofVec2f(boundTile.getLocation().x + BandTextures[bandState]->getWidth() /2, boundTile.getLocation().y + BandTextures[bandState]->getHeight() /2);
//
//}
//
//int Band::getClickedData(ofVec2f& mousePos, bool& clicked, bool& pressed)
//{
//    if (mousePos.x < TLpos.x || mousePos.x > BRpos.x ||
//        mousePos.y < TLpos.y || mousePos.y > BRpos.y)
//    {
//        return 0;
//        bandMenu->setInactive();
//        // its ouside
//    }
//    else
//    {
//        if (clicked == true)
//        {
//            return 3;
//            bandMenu->setInactive();
//        }
//        else if (pressed == true)
//        {
//            return 2;
//            bandMenu->setActive();
//        }
//        else
//        {
//            return 1;
//            bandMenu->setActive();
//        }
//    }
//}
//
//void Band::setTexture(ofTexture& TN0, ofTexture& TN1, ofTexture& TN2 , ofTexture& TN3)
//{
//    BandTextures[0] = &TN0;
//    BandTextures[1] = &TN1;
//    BandTextures[2] = &TN2;
//    BandTextures[3] = &TN3;
//}
//
//void Band::setTile(Tile T);
//{
//    boundTile = &T;
//}
//
//int Band::getIndex()
//{
//    return boundTileIndex;
//}
//
//std::string Band::getTextureNames()
//{
//    vector<std::string> names;
//    for (int i = 0; i < 4; i++)
//    {
//        names.push_back(TextureNames[i]);
//    }
//
//    return names;
//}
//
//void Band::setBandMenu(Menu& fillme)
//{
//    bandMenu = &fillme;
//}
//
//
//void Band::fillMenu(Menu& fillme)
//{
//    ostringstream convert;
//
//    TextBox* bandName = fillme.getPointerToChildByName<TextBox>("BandName");
//    bandName->setText(incarnationName);
//
//    TextBox* disNum = fillme.getPointerToChildByName<TextBox>("BandNumber");
//    convert << discipleNum;
//    disNum->setText(convert.str());
//}
//
//void Band::Update(ofVec2f& mousePos, bool& clicked, bool& pressed)
//{
//    if (getClickedData(mousePos, clicked, pressed) == 3)
//    {
//        selected = true;
//    }
//    else if (fabs(getClickedData(mousePos, clicked, pressed)) - 1.5 == .5)
//    {
//        bandPopup->setActive();
//    }
//
//
//}
//
//void Band::turnlyUpdate()
//{
//    ofVec2i temp;
//    for (int i = -movement; i <= movement; i++)
//    {
//        for (int j = (fabs(i) - movement); j <= (movement - fabs(i)); j++)
//        {
//            temp = ofVec2i(boundTileCoords.x - i, boundTileCoords.y - i);
//            if (temp.x < extremeTiles[0].x
//                or temp.x > extremeTiles[1].x
//                or temp.y < extremeTiles[0].y
//                or temp.y > extremeTiles[1].y)
//            {
//            }
//            else
//            {
//                possibleMoves.push_back(convertTo1dindex(temp));
//            }
//        }
//    }
//}
//
//
//void Band::saveObjectData(ofxXmlSettings&)
//{
//
//}
//
//void Band::loadObjectData(ofxXmlSettings&)
//{
//
//}
//
//
//
////the rest are boring
//void Band::setIncarnation(bool b, std::string incarnName);
//{
//    incarnation = b;
//    inacarnationName = incarnName
//    resetBandState();
//}
//
//bool Band::getIncarnation()
//{
//    return incarnation;
//}
//
//
//
//void Band::setDiscipleNum(int i)
//{
//    discipleNum = i;
//}
//
//void Band::changeDiscipleNum(int i)
//{
//    discipleNum += i;
//}
//
//int Band::getDiscipleNum()
//{
//    return discipleNum;
//}
//
//
//void Band::swapIncognito()
//{
//    incognito = !incognito;
//    resetBandState();
//}
//
//bool Band::getIncognito()
//{
//    return incognito;
//}
//
//
//
//void Band::setMinTiles(ofVec2i v)
//{
//    extremeTiles[0] = v;
//}
//
//void Band::setMaxTiles(ofVec2i v)
//{
//    extremeTiles[1] = v;
//}
//
//
//
//void Band::switchSelect()
//{
//    selected = !selected;
//}
//
//bool Band::getSelect()
//{
//    return selected;
//}
