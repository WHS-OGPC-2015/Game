#include "ofMain.h"


template<class T> class oVector
{
public:
    oVector();
    void addObject(auto object)
    {
        vec.push_back(object);
    }

private:
    std::vector<T> vec;
};
