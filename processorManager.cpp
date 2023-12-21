#include "processorManager.h"
#include "StringProcessFactory.h"



void processorManager::paramInitialize()
{

    StringProcessFactory factory;
    _fileManager.init(_strStruct.source,_strStruct.destination);
    _fileManager.openFile();
    _fileContent =_fileManager.getContent();
    for (auto it = _strStruct.orders.begin(); it != _strStruct.orders.end(); ++it) {
         auto  proc=  factory.create(*it);
         proc->stringProcessor(_fileContent);

    }
}

/*************************************************************************************/
void processorManager::setStrStruct(strStruct stStruct)
{
    _strStruct = stStruct;
}

/*************************************************************************************/
processorManager::processorManager()
{

}

/*************************************************************************************/
void processorManager::init()
{
   paramInitialize();
   startSaving();
}

/*************************************************************************************/
void processorManager::startSaving()
{
    _fileManager.setContent(_fileContent);
    _fileManager.writeFile();
}


