#ifndef PROCESSORMANAGER_H
#define PROCESSORMANAGER_H

#include "utils/ProcessOrder.h"
#include "utils/StrStruct.h"
#include <vector>
#include "stringResouce/InOutReSource.h"
#include <memory>

class processorManager
{
private:
    std::unique_ptr<InOutReSource> _strSource;
    std::string _fileContent;
    strStruct _strStruct;

    void paramInitialize();
    void startSaving();

public:
    void setStrStruct(strStruct stStruct);
    processorManager();
    void init();
    void injectSourceData(std::unique_ptr<InOutReSource> sourceData);

};

#endif // PROCESSORMANAGER_H
