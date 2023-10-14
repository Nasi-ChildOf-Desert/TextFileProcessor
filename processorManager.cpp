#include "processorManager.h"
#include <iostream>
#include "FactoryStringProccessor.h"
#include "utils/ProcessOrder.h"

void processorManager::paramInitialize()
{
    FactoryStringProccessor factory;
    QMap<QString, QString>::iterator it;
    QString sourceAddress;
    QString destAddress;
    if (_params.contains("i")) {
            sourceAddress = _params.value("i");
    }
    if (_params.contains("o")) {
            destAddress = _params.value("i");
    }
    _fileManager.init(sourceAddress,destAddress);
    _fileManager.openFile();
    _fileContent =_fileManager.getContent();

    for (it = _params.begin(); it != _params.end(); ++it) {
        QString key = it.key();
        QString value = it.value();
        if (key == "U" ) {
           factory.create(ProcessOrder::UpperCase, _fileContent);
        }
         else if (key == "L" ) {
           factory.create(ProcessOrder::LowerCase, _fileContent);
        }
        else if (key == "u" ) {
           factory.create(ProcessOrder::FirstCharUp, _fileContent);
        }
        else
           factory.create(ProcessOrder::FirstCharUp, _fileContent);
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

}
