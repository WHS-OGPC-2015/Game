#include "ofMain.h"

class ObjectManager
{
public:
    ObjectManager();
    template<class T>
    void addObjectType(std::string name)
    {
        oVector<T> temp;
        objects.push_back(temp);
        objectsArrayNames[name] = object.size()-1;
    }

    void addObjectToType(auto object, std::string type)
    {
        objects[objectArrayNames[type]].addObject[object];
    }

    auto& getObjectTypePointer(std::string type)
    {
        return objects[objectArrayNames[type]];
    }
private:
    std::vector<oVector> objects;
    std::map<std::string, int> objectArrayNames;
};
