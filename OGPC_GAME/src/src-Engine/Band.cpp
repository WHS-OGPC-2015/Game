#include "Band.h"
#include "sstream"


int Band::convertTo1dindex(ofVec2i v)
{
    return (v.y * (fabs(extremeTiles[1].x - extremeTiles[0].x)) + v.x); // converts an ofVec2i to an int based on the amount of tiles in the map
}

int turnToInt(double d) // returns an int -- probably something built in, but I'm lazy
{
    int i = d;
    return i;
}

Band::Band() // empty constructor
{
    incognito = false;
    incarnation = false;
    selected = false;
    begDisNum = 10; // arbitrary
    movement = 7; // arbitrary
    discipleNum = begDisNum;
    incarnationName = "";
    movable = true;
    bandClick = 0;
    actionState = 0;
    tileWidth = 0;

}

//you can change anything that would be have a possibility of being different at the start, including arbitrary things
Band::Band(bool incog, bool incarn, int startnum, int mov, double tilew, std::string incarnName /*set as "" if incarn is false*/)
{
    incognito = incog;
    incarnation = incarn;
    selected = false;
    movable = true;
    begDisNum = startnum;
    movement = mov;
    discipleNum = begDisNum;
    incarnationName = incarnName;
    bandClick = 0;
    actionState = 0;
    tileWidth = tilew;
}


void Band::resetBandType() // updates if you are normal, in incog, the incarnation, or if you are both
{
    if (incognito == true)
    {
        if (incarnation == true)
        {
            bandType = 3;
        }
        else
        {
            bandType = 1;
        }
    }
    else if (incarnation == true)
    {
       bandType = 2;
    }
    else
    {
        bandType = 0;
    }
}

int Band::getBandType()
{
    return bandType;
}


void Band::draw() // draws the current texture at the bound tile
{
    BandTextures[bandType]->draw(boundTile ->getLocation());
}


//returns 0 if not on the city, 1 if hovering, 2 if pressing, and 3 if clicked (for 1 frame)
int Band::getClickedData(ofVec2f& mousePos, bool& clicked, bool& pressed)
{

    if (mousePos.x < TLpos.x || mousePos.x > BRpos.x ||
        mousePos.y < TLpos.y || mousePos.y > BRpos.y)
    {
        return 0;
        // its ouside
    }
    else
    {
        if (clicked == true)
        {

            return 3;

        }
        else if (pressed == true)
        {

            return 2;

        }
        else
        {

            return 1;

        }
    }
}


//give the band a menu to point to
void Band::setBandMenu(Menu& fillme)
{
    bandMenu = &fillme;
    alignButtons();
}

// fills the menu
void Band::fillMenu()
{
    ostringstream convert;

    TextBox* bandName = bandMenu->getPointerToChildByName<TextBox>("BandName");
    bandName->setText(incarnationName);

    TextBox* disNum = bandMenu->getPointerToChildByName<TextBox>("BandNumber");
    convert << discipleNum;
    disNum->setText(convert.str());
}

// sets button pointer to menu buttons
void Band::alignButtons()
{
    actionButtons[0] = bandMenu->getPointerToChildByName<HoverButton>("MoveButton");
    actionButtons[1] = bandMenu->getPointerToChildByName<HoverButton>("BreakUpButton");
    actionButtons[2] = bandMenu->getPointerToChildByName<HoverButton>("IncognitoButton");
}

// determine, based on the buttons, which actionState to be in
void Band::findActions()
{
    if (selected == true and movable == true)
    {
        if (actionButtons[0]->getEventDataInt() > 2)
        {
            actionState = 1;
            movable = false;
        }
        else if (actionButtons[1]->getEventDataInt() > 2)
        {
            actionState = 2;
        }
        else if (actionButtons[2]->getEventDataInt() == 3 and incognito == false)
        {
            swapIncognito();
            movable = false;
        }
        else if (actionButtons[2]->getEventDataInt() == 0 and incognito == true)
        {
            swapIncognito();
            movable = false;
        }
    }
}

void Band::update(ofVec2f& mousePos, bool& clicked, bool& pressed)
{
    bandMenu->setInactive(); // start the update with this
    if (actionState == 0) // normal
    {

        if (getClickedData(mousePos, clicked, pressed) == 3)
        {
            selected = true;
        }
        else if (clicked == true) // if clicked not on the city
        {
           selected = false;
        }
        else if (getClickedData(mousePos, clicked, pressed) == 1 or getClickedData(mousePos, clicked, pressed) == 2)
        {
            // nothing yet
        }
        if (selected == true)
        {
            bandMenu->setActive();
        }
        return -1;
    }

    else if (actionState == 1) // moving
    {
        if (clicked == true)
        {
            // finds the 2d coord of your mose click, based on the tiles
            ofVec2i temptile = ofVec2i(turnToInt(mousePos.x / tileWidth), turnToInt(mousePos.y / tileWidth));
            for (int i = 0; i < possibleMoves.size(); i++)
            {
                if (temptile = possibleMoves[i])// check every possible move if there is a match
                {
                    int t = convertTo1dindex(temptile);
                    return t;
                }
            }

        }
        return -2;
    }

    else if (actionState == 2) // dispatching
    {
       if (clicked == true)
        {
            ofVec2i temptila = ofVec2i(turnToInt(mousePos.x / tileWidth), turnToInt(mousePos.y / tileWidth));

            if (temptile =  ofVec2i(boundTile->getLocation().x / tileWidth - 1, boundTile->getLocation().y / tileWidth) ||
                temptile =  ofVec2i(boundTile->getLocation().x / tileWidth + 1, boundTile->getLocation().y / tileWidth) ||
                temptile =  ofVec2i(boundTile->getLocation().x / tileWidth, boundTile->getLocation().y / tileWidth + 1) ||
                temptile =  ofVec2i(boundTile->getLocation().x / tileWidth, boundTile->getLocation().y / tileWidth - 1))
            {
                int q = convertTo1dindex(temptila);
                return q;
            }


        }
        return -3;
    }

}

void Band::turnlyUpdate()
{
    //reset the TL and BR positions for collisions
    TLpos = ofVec2f(boundTile->getLocation().x - BandTextures[bandType]->getWidth() /2, boundTile->getLocation().y - BandTextures[bandType]->getHeight() /2);
    BRpos = ofVec2f(boundTile->getLocation().x + BandTextures[bandType]->getWidth() /2, boundTile->getLocation().y + BandTextures[bandType]->getHeight() /2);

    // reset every turn
    actionState = 0;
    movable = true;
    possibleMoves.clear();

    ofVec2i temp;
    for (int i = -movement; i <= movement; i++)
    {
        for (int j = (fabs(i) - movement); j <= (movement - fabs(i)); j++)
        {
            temp = ofVec2i(boundTileCoords.x - i, boundTileCoords.y - i);
            if (temp.x < extremeTiles[0].x
                or temp.x > extremeTiles[1].x
                or temp.y < extremeTiles[0].y
                or temp.y > extremeTiles[1].y)
            {
            }
            else
            {
                possibleMoves.push_back(convertTo1dindex(temp));
            }
        }
    }
}


void Band::saveObjectData(ofxXmlSettings&)
{

}

void Band::loadObjectData(ofxXmlSettings&)
{

}



//the rest are boring
void Band::setIncarnation(bool b, std::string incarnName)
{
    incarnation = b;
    incarnationName = incarnName;
    resetBandType();
}

bool Band::getIncarnation()
{
    return incarnation;
}



void Band::setDiscipleNum(int i)
{
    discipleNum = i;
}

void Band::changeDiscipleNum(int i)
{
    discipleNum += i;
}

int Band::getDiscipleNum()
{
    return discipleNum;
}


void Band::swapIncognito()
{
    incognito = !incognito;
    resetBandType();
}

bool Band::getIncognito()
{
    return incognito;
}



void Band::setMinTiles(ofVec2i v)
{
    extremeTiles[0] = v;
}

void Band::setMaxTiles(ofVec2i v)
{
    extremeTiles[1] = v;
}

//set ALL of the textures
void Band::setTextures(ofTexture& TN0, ofTexture& TN1, ofTexture& TN2 , ofTexture& TN3)
{
    BandTextures[0] = &TN0;
    BandTextures[1] = &TN1;
    BandTextures[2] = &TN2;
    BandTextures[3] = &TN3;
}
void Band::setTile(Tile T)
{
    boundTile = &T;
}

int Band::getIndex()
{
    return boundTileIndex;
}

void Band::switchSelect()
{
    selected = !selected;
}

bool Band::getSelect()
{
    return selected;
}

void Band::setTileWidth(double d)
{
    tileWidth = d;
}

vector<std::string> Band::getTextureNames()
{
    vector<std::string> names;
    for (int i = 0; i < 4; i++)
    {
        names.push_back(TextureNames[i]);
    }

    return names;
}
