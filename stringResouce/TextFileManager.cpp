#include "TextFileManager.h"
#include <iostream>
#include <fstream>
#include <string>


void TextFileManager::init(std::string sourceFilePath, std::string destinationFilePath)
{
    _sourceFilePath =sourceFilePath;
    _destinationFilePath = destinationFilePath;
}

/*************************************************************************************/
bool TextFileManager::openFile() {

    std::ifstream inf{ _sourceFilePath };

       // If we couldn't open the output file stream for reading
       if (!inf)
       {
           // Print an error and exit
           std::cerr << "Uh oh, "+ _sourceFilePath +" could not be opened for reading!\n";
           return false;
       }

           std::string line;
       while (std::getline(inf, line)) {
             _fileContents += line + "\n"; // Append each line to the string
         }
     inf.close();
     return true;
}

/*************************************************************************************/
bool TextFileManager::writeFile() {

    // Create and open a text file
      std::ofstream MyFile(_destinationFilePath);

      // Write to the file
      MyFile << _fileContents;

      // Close the file
      MyFile.close();
}

std::string TextFileManager::getStr()
{  
    openFile();
    return _fileContents;
}

void TextFileManager::setStr(std::string str)
{
  _fileContents = str;
  writeFile();
}

