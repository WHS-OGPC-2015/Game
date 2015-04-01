//#include "ObjectManager.h"
//
//void ObjectManager::loadFromFile(std::string filePath)
//{
//    ofxXmlSettings objects;
//    if(objects.loadFile(filePath))
//    {
//
//        std::vector<std::string> objectNames;
//        int numObjectTypes = objects.getValue("numObjectTypes", 0);
//
//        std::string type;
//        for(int ii = 0; ii < numObjectTypes; ii++)
//        {
//            objects.pushTag("type", ii)
//            type = objects.getValue("name", "");
//            numType = object.getValue("numOf", 0);
//            if(objectArrayNames.find(type) == objectArrayNames.end())           //if statements deduce type which is then loaded
//            {
//                if(type == "City")
//                {
//                    addObjectType<City>("City");
//                    getPointerToChildByName<City>("City")->loadObjectData(objects, numType);
//                }
//                else if(type == "Player")
//                {
//                    addObjectType<Player>("Player");
//                    getPointerToChildByName<Player>("Player")->loadObjectData(objects, numType);
//                }
//                else if(type == "??????")
//                {
//                    //add
//                }
//            }
//
//
//
//        }
//
//    }
//
//}
//
//void ObjectManager::saveToFile(std::string path)
//{
//    ofxXmlSettings file;
//    file.addValue("numObjectTypes", objectArrayNames.size())
//    for(int ii = 0; ii < objectArrayNames.size())
//    {
//        objects.addTag("type");
//        objects.pushTag("type", ii);
//        //map<std::string, int>::iterator it = m.begin()+ii;
//        objects.addValue("name", objectArrayNames[ii].first/*it->first*/)
//        objects.addValue("numOf", objectArrayNames[ii].getVector().size)
//        objects[ii].saveObjectData(file);
//
//
//
//        objects.popTag();
//
//    }
//}
//
//void ObjectManager::updateAll()
//{
//    for(int ii = 0; ii < objects.size())
//    {
//        objects[ii].updateAll();
//    }
//}
//
//void ObjectManager::drawAll()
//{
//    for(int ii = 0; ii < objects.size())
//    {
//        objects[ii].drawAll();
//    }
//}
//
//
