#ifndef PROCESSORMANAGER_H
#define PROCESSORMANAGER_H
#include <QString>
#include "TextFileManager.h"
#include <QMap>
#include "utils/ProcessOrder.h"
#include "utils/StrStruct.h"
#include <vector>
class processorManager
{
private:

    TextFileManager _fileManager;
    std::string _fileContent;
    void paramInitialize();
    strStruct _strStruct;
public:
    void setStrStruct(strStruct stStruct);
    processorManager();
    void init();
    void startSaving();
    std::string responseOfProcess();
};

#endif // PROCESSORMANAGER_H
