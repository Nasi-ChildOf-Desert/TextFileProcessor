#ifndef TEXTFILEMANAGER_H
#define TEXTFILEMANAGER_H
#include <fstream>
#include <iostream>

class TextFileManager
{
private:
    std::string _sourceFilePath;
    std::string _destinationFilePath;
    std::string _fileContents;

public:
    TextFileManager();
    void init(std::string sourceFilePath, std::string destinationFilePath);
    bool openFile();
    bool writeFile();
    std::string getContent();
    void setContent(std::string fileContents);
};

#endif // TEXTFILEMANAGER_H
