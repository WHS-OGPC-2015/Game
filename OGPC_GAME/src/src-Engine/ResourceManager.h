#pragma once
#include "ofMain.h"
#include <windows.h>
#include <stdio.h>
class ResourceManager
{
public:
    ResourceManager();
    void loadFilesFromDirectory(std::string);


    void addTexture(std::string, std::string);
    ofTexture& getTextureReference(std::string);

    void addFont(std::string, std::string, int);
    ofTrueTypeFont& getFontReference(std::string);

    void addSound(std::string, std::string);        //add sound to vector
    ofSoundPlayer& getSoundReference(std::string);  //returns REFERECE to sound
    ofSoundPlayer getSound(std::string);            //returns COPY of sound

private:
    std::vector<ofTexture> textures;            //holds real copy of textures
    std::map<int, std::string> textureNames;    //holds names mapped to textures

    std::vector<ofTrueTypeFont> fonts;          //same but with fonts
    std::map<int, std::string> fontNames;

    std::vector<ofSoundPlayer> sounds;
    std::map<int, std::string> soundNames;


};
