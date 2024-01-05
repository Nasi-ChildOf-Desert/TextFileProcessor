#ifndef TEXTFILEMANAGER_H
#define TEXTFILEMANAGER_H
#include <fstream>
#include <iostream>
#include "InOutReSource.h"

class TextFileManager: public InOutReSource
{
private:
    std::string _sourceFilePath;
    std::string _destinationFilePath;
    std::string _fileContents;
    bool openFile();
    bool writeFile();

public:
    virtual  std::string getStr() override;
    virtual  void setStr(std::string str) override;
    //? how to access child method when we get parent object?
    void init(std::string sourceFilePath, std::string destinationFilePath);

};

#endif // TEXTFILEMANAGER_H


