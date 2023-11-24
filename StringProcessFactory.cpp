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

//std::vector<std::unique_ptr<Process> > StringProcessFactory::create(QMap<QString, QString> params)
//{
//    std::vector<std::unique_ptr<Process>> processorList;
//        QMap<QString, QString>::iterator it;
//    for (it = params.begin(); it != params.end(); ++it) {
//        QString key = it.key();
//        QString value = it.value();
//        if (key == "U" )

//           processorList.push_back(std::make_unique<DoUpperCase>());
//        if (key == "L" )
//           processorList.push_back(std::make_unique<DoLowerCase>());
//        if (key == "u" )
//           processorList.push_back(std::make_unique<SetFirstCharUp>());
//        else if(key !="o" )
//        {
//             processorList.push_back(std::make_unique<SetFirstCharUp>());
//        }
//    }
//    return processorList;
//}
