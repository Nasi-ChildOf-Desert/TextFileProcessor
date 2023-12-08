#include "processorManager.h"
#include "StringProcessFactory.h"


void processorManager::paramInitialize()
{

    StringProcessFactory factory;
    _fileManager.init(sourceAddress,destAddress);
    _fileManager.openFile();
    _fileContent =_fileManager.getContent();
    for (auto it = orders.begin(); it != orders.end(); ++it) {
         auto  proc=  factory.create(*it);
         proc->stringProcessor(_fileContent);

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
   startSaving();
}

/*************************************************************************************/
void processorManager::startSaving()
{
    _fileManager.setContent(_fileContent);
    _fileManager.writeFile();
}


