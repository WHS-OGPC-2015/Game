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
//
//}
//
//Band::Band(bool incog, bool incarn, int startnum, int mov, std::string incarnName /*set as "" if incarn is false*/)
//{
//    incognito = incog;
//    incarnation = incarn;
//    selected = false;
//    begDisNum = startnum; // arbitrary
//    movement = mov; // arbitrary
//    discipleNum = begDisNum;
//    incarnationName = incarnName;
//}
//
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
//void Band::draw()
//{
////    BandTextures[bandState]->draw();
//
//    TLpos = ofVec2f(boundTile->getLocation().x - BandTextures[bandState]->getWidth() /2, boundTile->getLocation().y - BandTextures[bandState]->getHeight() /2);
//    BRpos = ofVec2f(boundTile->getLocation().x + BandTextures[bandState]->getWidth() /2, boundTile->getLocation().y + BandTextures[bandState]->getHeight() /2);
//
//}
//
//int Band::getClickedData(ofVec2f& mousePos, bool& clicked, bool& pressed)
//{
//    if (mousePos.x < TLpos.x || mousePos.x > BRpos.x ||
//        mousePos.y < TLpos.y || mousePos.y > BRpos.y)
//    {
//        return 0;
//
//        // its ouside
//    }
//    else
//    {
//        if (clicked == true)
//        {
//            return 3;
//
//        }
//        else if (pressed == true)
//        {
//            return 2;
//
//        }
//        else
//        {
//            return 1;
//
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
//void Band::fillMenu()
//{
//    ostringstream convert;
//
//    TextBox* bandName = bandMenu->getPointerToChildByName<TextBox>("BandName");
//    bandName->setText(incarnationName);
//
//    TextBox* disNum = bandMenu->getPointerToChildByName<TextBox>("BandNumber");
//    convert << discipleNum;
//    disNum->setText(convert.str());
//}
//
//void Band::update(ofVec2f& mousePos, bool& clicked, bool& pressed)
//{
//    bandMenu->setInactive();
//    if (getClickedData(mousePos, clicked, pressed) == 3)
//    {
//        bandPopup->setActive();
//        selected = true;
//    }
//    else if (getClickedData(mousePos, clicked, pressed) == 1 or getClickedData(mousePos, clicked, pressed) == 2)
//    {
//
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
