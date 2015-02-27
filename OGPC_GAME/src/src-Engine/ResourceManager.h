#pragma once
#include "ofMain.h"
#include "windows.h"
#include "stdio
class ResourceManager
{
public:
    ResourceManager();
    void loadFilesFromDirectory();


    void addTexture();
    void addFont();
    void getTextureReference();

private()
    std::vector<ofTexture> textures;            //holds real copy of textures
    std::map<int, std::string> textureNames;    //holds names mapped to textures

    std::vector<ofTrueTypeFont> fonts;          //same but with fonts
    std::map<int, std::string> fontNames;


};
