#include "ofMain.h"

struct oVectorAbstract
{
    virtual ~oVectorAbstract() = 0;
};



template<class T> class oVector : public oVectorAbstract
{
public:
    oVector();
    void addObject(T object)//add an object of type to the array
    {
        vec.push_back(object);
    }
    void loadObjectData(ofxXmlSettings& file, int numType);//create objects and if necessary tell them to load themselves
    std::vector<T> getVector();

    void updateAll();
    void drawAll();
private:
    std::vector<T> vec;
};
