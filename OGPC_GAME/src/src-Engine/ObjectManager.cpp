#include "ObjectManager.h"


void ObjectManager::addObjectToType(auto object, std::string type)
{
    objects[objectArrayNames[type]].addObject[object];
}

auto& ObjectManager::getObjectTypePointer(std::string type)
{
    return objects[objectArrayNames[type]];
}

void ObjectManager::loadFromFile(std::string filePath)
{
    ofxXmlSettings objects;
    if(objects.loadFile(filePath))
    {

        std::vector<std::string> objectNames;
        int numObjectTypes = objects.getValue("numObjectTypes", 0);

        std::string type;
        for(int ii = 0; ii < numObjectTypes; ii++)
        {
            objects.pushTag("type", ii)
            type = objects.getValue("name", "");
            numType = object.getValue("numOf", 0);
            if(objectArrayNames.find(type) == objectArrayNames.end())
            {
                if(type == "City")
                {
                    addObjectType<City>("City");
                }
                else if(type == "Player")
                {
                    addObjectType<Player>("Player");
                }
                else if(type == "??????")
                {
                    //add
                }
                objects[objectArrayNames[type]].loadObjectData(objects, numType);   //load all objects of that type
            }



        }

    }

}

void ObjectManager::updateAll()
{
    for(int ii = 0; ii < objects.size())
    {
        objects[ii].updateAll();
    }
}

void ObjectManager::drawAll()
{
    for(int ii = 0; ii < objects.size())
    {
        objects[ii].drawAll();
    }
}


