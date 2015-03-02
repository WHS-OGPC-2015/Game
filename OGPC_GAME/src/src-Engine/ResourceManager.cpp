#include "ResourceManager.h"

ResourceManager::ResourceManager()
{

}

void ResourceManager::loadFilesFromDirectory(std::string folder)
{

    std::vector<std::string> names;

    std::string specPath = folder + "\\*.*";
    folder += "\\";

    WIN32_FIND_DATA fd;     //declare variable to hold file data
    HANDLE hFind = FindFirstFile(specPath.c_str(), &fd);    //find first file and store data
    if(hFind != INVALID_HANDLE_VALUE) {                     //if that data is not corrupt
        do {
            // read all (real) files in current folder
            // , delete '!' read other 2 default folder . and ..
            if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
                names.push_back(fd.cFileName);
            }
        }while(FindNextFile(hFind, &fd));                   //find the next file

        FindClose(hFind);

    }
    //at this point "names" vector has all file names in directory

    for(int indice = 0; indice < names.size(); indice++)
    {
        int dotLoc = names[indice].size(); //location of '.' in string
        std::string extension = "";  //parsed file extension
        std::string notExtension = ""; //just the name
        for(int ii = 0; 0<names[indice].size(); ii++)
        {
            if(names[indice][ii] == '.')    //if the character is a period
            {
                dotLoc = ii;                //store that indice
            }
            else if(ii > dotLoc)            //if the indice is after the period
            {
                extension+= names[indice][ii];   //store the character
            }
            else if(ii < dotLoc)
            {
                notExtension+= names[indice][ii];
            }
        }

        std::string fullPath  = folder+names[indice];
        if(extension == "jpg" ||       //Checking for all texture file extensions
            extension == "jpeg" ||
            extension == "png" ||
            extension == "bmp")
        {
            addTexture(fullPath, notExtension);  //if so load texture from that path
        }
        else if(extension == "ttf")
        {
            addFont(fullPath, notExtension);
        }
        else if(extension ==  ".wav" ||         //checks for valid sound extensions
                extension == ".aif" ||
                extension == ".mp3" ||
                extension == ".mp2" ||
                extension == ".ogg" ||
                extension == ".raw")
        {
            addSound(fullPath, notExtension);
        }




    }
}

void ResourceManager::addTexture(std::string path, std::string name)
{
    ofTexture tmp;
    ofLoadImage(&tmp, path);
    textures.push_back(tmp);
    textureNames[name] = textures.size()-1;

}

ofTexture& ResourceManager::getTextureReference(std::string name)
{
    return &textures[textureNames[name]];
}

void ResourceManager::addFont(std::string path, std::string name, int loadSize)
{
    ofTrueTypeFont tmp;
    tmp.loadFont(path, loadSize);
    fonts.push_back(tmp);
    textureName{name} = fonts.size()-1
}

ofTexture& ResourceManager::getFontReference(std::string name)
{
    return &fonts[fontNames[name]];
}

void addSound(std::string path, std::string name, bool stream=false)
{
    ofSoundPlayer tmp;
    tmp.loadSound(path, stream);
    sounds.push_back(tmp);
    soundNames[name] = sounds.size()-1;
}

ofSoundPlayer& getSoundReference(std::string name)
{
    return &sounds[soundNames[name]];
}

ofSoundPlayer getSound(std::string name)
{
    return sounds[soundNames[name]];
}

