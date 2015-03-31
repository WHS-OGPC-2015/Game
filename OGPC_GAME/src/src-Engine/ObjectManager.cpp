#include "ObjectManager.h"

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
                    //addObjectType<City>("City");
                    //getPointerToChildByName<City>("City")->loadObjectData(objectFile, numType);
                }
                else if(type == "Player")
                {
                    //addObjectType<Player>("Player");
                    //getPointerToChildByName<Player>("Player")->loadObjectData(objectFile, numType);
                }
                else if(type == "??????")
                {
                    //add
                }
            }



        }

    }

}

void ObjectManager::saveToFile(std::string path)
{
    ofxXmlSettings file;
    if(file.loadFile(path))
    {
        int s = objects.size();
        file.addValue("numObjectTypes", s);
        for(int ii = 0; ii < objectArrayNames.size(); ii++)
        {
            file.addTag("type");
            file.pushTag("type", ii);
            //map<std::string, int>::iterator it = objectArrayNames.begin()+ii;
            file.addValue("name", "City");
            file.addValue("numOf", getPointerToChildByIndice<decltype(objects[ii])>(ii).getVector().size();
            objects[ii].saveObjectData(file);



            file.popTag();

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


