#include "FactoryStringProccessor.h"

#include "ProcessClass/DoUpperCase.h"
#include "ProcessClass/DoLowerCase.h"
#include "ProcessClass/SetFirstCharUp.h"

std::shared_ptr<Process> FactoryStringProccessor::create(ProcessOrder type, QString &fileContent)
{
    switch (type) {
    case ProcessOrder::UpperCase:
       return std::shared_ptr<Process>(new DoLowerCase(fileContent));
        break;

    default:
        break;

    }

   return nullptr;
}
