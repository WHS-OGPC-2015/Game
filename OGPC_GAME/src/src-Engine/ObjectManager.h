#pragma once
#include "ofMain.h"
#include "../XML/src/ofxXmlSettings.h"
#include "ObjectVector.h"
#include "City.h"
class ObjectManager
{

public:
    ObjectManager(std::string, ofVec2f, TileManager&);


    template<class T>
    bool addObjectType(std::string name)    //add a new type of object to the array
    {
        if(objectArrayNames.find(name) == objectArrayNames.end())
        {
            oVector<T> temp;
            oVectorAbstract tmp = temp;
            objects.push_back(temp);
            objectArrayNames[name] = objects.size()-1;
            return true;
        }
        return false;
    }

    template<class C>//C is child class
    oVector<C>* getPointerToChildByName(std::string name)
    {
        C* tmpChild = (C *) &(objects[objectArrayNames[name]]);    //cast parent as child
        return tmpChild;
    }

    template<class C>//C is child class
    oVector<C>* getPointerToChildByIndice(int i)
    {
        oVector<C>* tmpChild = (oVector<C>*) &(objects[i]);    //cast parent as child
        return tmpChild;
    }

    template<class oT>
    void addObjectToType(oT object, std::string type)    //add an object of specific type to its array
    {
        getPointerToChildByName<oVector<oT> >(type)->addObject[object];
    }
    //auto getObjectTypePointer(std::string type) -> decltype(objects[objectArrayNames[type]]);           //get pointer to an oVector



    void saveToFile(std::string);
    void loadFromFile(std::string filePath);    //load all objects from file
    void updateAll();                           //update all objects
    void drawAll();                             //draw all objects
private:
    std::vector<oVectorAbstract> objects;   //array of objects which will hold their own objects
    std::map<std::string, int> objectArrayNames;
    TileManager& tiles;         //local reference to tile manager
    ResourceManager& recMan;    //local reference to resources
    MenuManager* objectMenus;   //manager for popups and stuff

};
