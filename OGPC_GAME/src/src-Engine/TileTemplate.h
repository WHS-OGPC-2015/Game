#pragma once
#include "ofMain.h"

template<class T> class tileAttribute //data type to arbitrarily hold variables
{
  public:
      T attribute;

};

class TileTemplate  //template class for tile
{
public:
    template<class type>
    void addAttribute(type att, std::string name)//add a type of attribute to the template
    {
        tileAttribute<type> tmpAttribute;           //create local instance of specified attribute
        attributes.push_back(tmpAttribute);         //add attribute to vector
        attributeNames{name} = attributes.size()-1; //add attribute to map
    }

    std::vector<tileAttribute> getAttributes()//returns attribute array
    getAttributeIndice(std::string attributeName);//returns indice of the attribute mapped to the given string name
private:
    std::vector<tileAttribute> attributes;//holds all possible tile attributes
    std::map<std::string, int> attributeNames;//holds names mapped to all tile attributes

};
