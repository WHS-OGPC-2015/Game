#include "ofMain.h"
#include "../XML/src/ofxXmlSettings.h"
class ObjectManager
{
public:
    ObjectManager();

    template<class T>
    bool addObjectType(std::string name)    //add a new type of object to the array
    {
        if(objectArrayNames.find(name) == objectArrayNames.end())
        {
            oVector<T> temp;
            objects.push_back(temp);
            objectsArrayNames[name] = object.size()-1;
            return true;
        }
        return false;
    }

    void addObjectToType(auto object, std::string type);    //add an object of specific type to its array
    auto& getObjectTypePointer(std::string type);           //get pointer to an oVector

    void loadFromFile(std::string filePath);    //load all objects from file
    void updateAll();                           //update all objects
    void drawAll();                             //draw all objects
private:
    std::vector<oVector> objects;   //array of objects which will hold their own objects
    std::map<std::string, int> objectArrayNames;
};
