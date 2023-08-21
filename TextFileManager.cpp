#include "TextFileManager.h"
#include <iostream>
#include <QFile>
#include <QTextStream>


TextFileManager::TextFileManager()
{

}

void TextFileManager::init(QString sourceFilePath, QString destinationFilePath)
{
    _sourceFilePath =sourceFilePath;
    _destinationFilePath = destinationFilePath;
}

/*************************************************************************************/
bool TextFileManager::openFile() {
    QFile file(_sourceFilePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        _fileContents = in.readAll();
        file.close();
        std::cout << "Source file opened successfully." << std::endl;
        return true;
    } else {
        std::cerr << "Failed to open the source file." << std::endl;
        return false;
    }
}

/*************************************************************************************/
bool TextFileManager::writeFile() {
    QFile file(_destinationFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << _fileContents;
        file.close();
        std::cout << "Destination file written successfully." << std::endl;
        return true;
    } else {
        std::cerr << "Failed to write to the destination file." << std::endl;
        return false;
    }
}

/*************************************************************************************/
QString TextFileManager::getContent()
{
    return _fileContents;
}

/*************************************************************************************/
void TextFileManager::setContent(QString fileContents)
{
    _fileContents = fileContents;
}
