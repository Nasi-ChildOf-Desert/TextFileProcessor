#include "processorManager.h"
#include "StringProcessFactory.h"



void processorManager::paramInitialize()
{

    StringProcessFactory factory;


    _fileContent =_strSource->getStr();
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
void processorManager::injectSourceData(std::unique_ptr<InOutReSource> sourceData)
{
    _strSource = std::move(sourceData);
}

/*************************************************************************************/
void processorManager::startSaving()
{
    _strSource->setStr(_fileContent);
 }


