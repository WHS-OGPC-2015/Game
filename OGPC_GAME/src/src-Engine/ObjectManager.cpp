///To add a new supported object type you must add an if statement in the save and load functions

#include "ObjectManager.h"

ObjectManager::ObjectManager(std::string toLoad, ofVec2f translation, TileManager& t)
{
    tiles = t;
    objectMenus = new MenuManager;

    loadFromFile(toLoad);
}
void ObjectManager::loadFromFile(std::string filePath)
{
    ofxXmlSettings objectFile;
    if(objectFile.loadFile(filePath))
    {

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
                    addObjectType<City>("City");
                    oVector<City>* C = getPointerToChildByName<City>("City");
                    City& tmp;
                    for(int ii = 0; ii<numType; ii++)
                    {
                        tmp = C->getObject(ii);
                        C->loadObjectData(objectFile, numType);
                        C->setTile(tiles.getTileByIndice(C->getTileIndex()));
                        C->setTexture(recMan.getTextureReference(C->getTextureName()));
                    }

                }
//                else if(type == "Player")
//                {
//                    //addObjectType<Player>("Player");
//                    //getPointerToChildByName<Player>("Player")->loadObjectData(objectFile, numType);
//                }
//                else if(type == "??????")
//                {
//                    //add
//                }
            }



        }

    }

}

void ObjectManager::saveToFile(std::string path)
{
    std::string typeName;
    ofxXmlSettings file;
    if(file.loadFile(path))
    {
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
                City* C = getPointerToChildByIndice<City>(ii);

            }





            file.popTag();

        }
    }

}

void ObjectManager::updateAll()
{
    for(int ii = 0; ii < objects.size(); ii++)
    {
        objects[ii].updateAll();
    }
}

void ObjectManager::drawAll()
{
    for(int ii = 0; ii < objects.size(); ii++)
    {
        objects[ii].drawAll();
    }
}


