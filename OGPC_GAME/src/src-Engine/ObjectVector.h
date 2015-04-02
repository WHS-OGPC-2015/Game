#include "ofMain.h"
#include "../XML/src/ofxXmlSettings.h"
struct oVectorAbstract
{
    virtual ~oVectorAbstract() = 0;
    virtual void updateAll() = 0;
    virtual void drawAll() = 0;
};



template<class T> class oVector : public oVectorAbstract
{
public:
    oVector()
    {

    }

    void loadObjectData(ofxXmlSettings& file, int numType)//create objects and if necessary tell them to load themselves
    {
        for(int ii = 0; ii < numType; ii++)
        {
            vec[ii].loadObjectData(file);
        }
    }

    void saveObjectData(ofxXmlSettings& file)
    {
        for(int ii = 0; ii < vec.size(); ii++)
        {
            vec[ii].saveObjectData(file);
        }
    }

    std::vector<T> getVector()
    {
        return vec;
    }

    void updateAll()
    {
        for(int ii = 0; ii < vec.size(); ii++)
        {
            vec[ii].update();
        }
    }

    void drawAll()
    {
            for(int ii = 0; ii < vec.size(); ii++)
        {
            vec[ii].draw();
        }
    }

    void addObject(T object)//add an object of type to the array
    {
        vec.push_back(object);
    }
private:
    std::vector<T> vec;
};
