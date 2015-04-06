///To add a new supported object type you must add an if statement in the save and load functions

#include "ObjectManager.h"

ObjectManager::ObjectManager(std::string toLoad, ofVec2f translation, TileManager* t, ResourceManager* R)
{
    tiles = t;
    recMan = R;
    objectMenus = new MenuManager;  //create menu manager for the
    createCityMenu(objectMenus, ofVec2f(ofGetWindowWidth()-100, ofGetWindowHeight()-150), recMan);

    loadFromFile(toLoad);
}
ObjectManager::~ObjectManager()
{
    delete objectMenus;
}
void ObjectManager::mainThreadFunction()
{

}
void ObjectManager::loadFromFile(std::string filePath)
{
    ofxXmlSettings objectFile;

    if(objectFile.loadFile("objects.xml"))
    {
    std::cout << "file Loadded" << std::endl;
        std::vector<std::string> objectNames;
        int numObjectTypes = objectFile.getValue("numObjectTypes", 0);

        std::string type;
        for(int ii = 0; ii < numObjectTypes; ii++)
        {
            objectFile.pushTag("type", ii);
            std::string type = objectFile.getValue("name", "");
            int numType = objectFile.getValue("numOf", 0);
            if(objectArrayNames.find(type) == objectArrayNames.end())           //if statements deduce type which is then loaded
            {
                if(type == "City")
                {
                    addObjectType<City>("City", numType);
                    oVector<City>* C = getPointerToChildByName<City>("City");
                                                                      //create temporary city to add textures n stuff to individual cities
                    C->loadObjectData(objectFile, numType);                     //load data for (numType) cities in the array
                    for(int ii = 0; ii<numType; ii++)
                    {
                        City* tmp = C->getObject(ii);
                        tmp->setTile(tiles->getTileByIndice(tmp->getTileIndex()));
                        tmp->setTexture(recMan->getTextureReference(tmp->getTextureName(false)), false);
                        tmp->setTexture(recMan->getTextureReference(tmp->getTextureName(true)), true);
                        tmp->setMenu(objectMenus->getMenuPointerByName("CityMenu"));
                    }

                }
                /*
                -----------------------------------
                ADD OTHER TYPES HERE
                -----------------------------------
                */
            }



        }

    }
    else
    {
        std::cout << "file NOT Loadded" << std::endl;
    }

}

void ObjectManager::saveToFile(std::string path)
{
    std::string typeName;
    ofxXmlSettings file;
    int s = objects.size();
    file.addValue("numObjectTypes", s);
    for(int ii = 0; ii < objectArrayNames.size(); ii++)
    {
        file.addTag("type");
        file.pushTag("type", ii);
        std::map<std::string, int>::iterator it = objectArrayNames.begin();
        std::advance(it, ii);
        typeName = it->first;
        file.addValue("name", typeName);
        if(typeName == "City")
        {
            oVector<City>* C = getPointerToChildByIndice<City>(ii);
            C->saveObjectData(file);
        }
        /*
        -----------------------------------
        ADD OTHER TYPES HERE
        -----------------------------------
        */

        file.popTag();
    }
    file.saveFile(path);
}



void ObjectManager::updateAll(ofVec2f& mousePos, bool& clicked, bool& pressed)
{
    for(int ii = 0; ii < objects.size(); ii++)
    {
        objects[ii]->updateAll(mousePos, clicked, pressed);
    }
    objectMenus->update(mousePos, clicked, pressed);
}

void ObjectManager::drawNoTranslate()
{
    objectMenus->draw();
    objectMenus->getMenuPointerByName("CityMenu")->setInactive();
}

void ObjectManager::drawAll()
{
    for(int ii = 0; ii < objects.size(); ii++)
    {
        objects[ii]->drawAll();
    }
}


