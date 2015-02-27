#include "ResourceManager.h"

ResourceManager()
{

}

loadFilesFromDirectory(std::string folder)
{

    vector<string> names;
    ///NOT REALLY SURE HOW THIS BLOCK OF CODE WORKS
    char search_path[200];
    sprintf(search_path, "%s*.*", folder.c_str());
    WIN32_FIND_DATA fd;
    HANDLE hFind = ::FindFirstFile(search_path, &fd);
    if(hFind != INVALID_HANDLE_VALUE) {
        do {
            // read all (real) files in current folder
            // , delete '!' read other 2 default folder . and ..
            if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ) {
                names.push_back(fd.cFileName);
            }
        }while(::FindNextFile(hFind, &fd));
        ::FindClose(hFind);
    //at this point "names" vector has all file names in directory

    for(int indice = 0; indice < names.size(); indice++)
    {
        int dotLoc; //location of '.' in string
        std::string extension = "";  //parsed file extension
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
        }
        if(extension != "")
        {
            if(extension == "jpg" &&        //Checking for all texture file extensions
               extension == "jpeg" &&
               extension == "png" &&
               extension == "bmp")
            {
                addTexture(names[indice]);  //if so load texture from that path
            }
            else if(extension == "ttf")
            {
                addFont(names[indice]);
            }

        }

    }

}
