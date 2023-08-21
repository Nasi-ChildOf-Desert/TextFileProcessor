#include "processorManager.h"
#include <iostream>
void processorManager::paramInitialize()
{
    QMap<QString, QString>::iterator it;
    QString sourceAddress;
    QString destAddress;
    for (it = _params.begin(); it != _params.end(); ++it) {
        QString key = it.key();
        QString value = it.value();

        if (key == "i" && !value.isEmpty()) {
          sourceAddress = value;
        }
        if (key == "o" && !value.isEmpty()) {
          destAddress = value;
        }
        if (key == "U" ) {
          _doUpperCase = true;
        }
        if (key == "L" ) {
          _doLowerCase = true;
        }
        if (key == "u" ) {
          _setFirsCharToUpper = true;
        }
    }
    if(!_doUpperCase && !_doLowerCase && !_setFirsCharToUpper)
    {
         _setFirsCharToUpper = true;
    }

    if (it == _params.end()) {
      //  qDebug() << "Key-value pair not found.";
    }
   _fileManager.init(sourceAddress,destAddress);
   _fileManager.openFile();
   _fileContent =_fileManager.getContent();
}

/*************************************************************************************/
void processorManager::doUpperCase()
{
    if(_doUpperCase)
    {
      std::cout << "_doUpperCase." << std::endl;
      auto modifiedContent =  _fileContent.toUpper();
      _fileContent.clear();
      _fileContent  = modifiedContent;
    }
}

/*************************************************************************************/
void processorManager::doLowerCase()
{
    if(_doLowerCase)
    {
      std::cout << "doLowerCase." << std::endl;
      auto modifiedContent =  _fileContent.toLower();
      _fileContent.clear();
      _fileContent  = modifiedContent;
    }
}

/*************************************************************************************/
void processorManager::setFirstChar()
{
    if(_setFirsCharToUpper)
    {
        QStringList lines = _fileContent.split("\n");
            for (QString& line : lines) {
                QStringList words = line.split(' ', QString::SkipEmptyParts);
                for (QString& word : words) {
                    if (!word.isEmpty()) {
                        QChar firstChar = word.at(0);
                        if (firstChar.isLetter()) {
                            word[0] = firstChar.toUpper();
                        }
                    }
                }
                line = words.join(' ');
            }
            _fileContent = lines.join("\n");

    }
}

/*************************************************************************************/
processorManager::processorManager()
{

}

/*************************************************************************************/
void processorManager::init(QMap<QString, QString>& parameters)
{
   _params =parameters;
   paramInitialize();
   startProcess();
}

/*************************************************************************************/
void processorManager::startProcess()
{
    doUpperCase();
    doLowerCase();
    setFirstChar();
    _fileManager.setContent(_fileContent);
    _fileManager.writeFile();
}

/*************************************************************************************/
QString processorManager::responseOfProcess()
{

}
