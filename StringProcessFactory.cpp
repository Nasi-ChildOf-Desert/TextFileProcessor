#include "StringProcessFactory.h"
#include "ProcessClass/DoUpperCase.h"
#include "ProcessClass/DoLowerCase.h"
#include "ProcessClass/SetFirstCharUp.h"
#include "ProcessClass/Process.h"
#include <memory>
StringProcessFactory::StringProcessFactory()
{

}

std::unique_ptr<Process> StringProcessFactory::create(ProcessOrder order)
{
    switch(order)
    {
     case ProcessOrder::UpperCase:
         return std::make_unique<DoUpperCase>();
    case ProcessOrder::LowerCase:
        return std::make_unique<DoLowerCase>();
    case ProcessOrder::FirstCharUp:
        return std::make_unique<SetFirstCharUp>();
    case ProcessOrder::None:
        return std::make_unique<SetFirstCharUp>();
    }
}


