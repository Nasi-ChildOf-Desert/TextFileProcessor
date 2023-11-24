#include "processorManager.h"
#include <iostream>
#include "StringProcessFactory.h"


void processorManager::paramInitialize()
{

    StringProcessFactory factory;
   std::vector<ProcessOrder>::iterator it;

    _fileManager.init(sourceAddress,destAddress);
    _fileManager.openFile();
    _fileContent =_fileManager.getContent();
    for (it = orders.begin(); it != orders.end(); ++it) {
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

/*************************************************************************************/
QString processorManager::responseOfProcess()
{
 // do i need warning ui that done ok?
}
