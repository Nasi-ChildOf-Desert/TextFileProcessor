#ifndef STRINGPROCESSFACTORY_H
#define STRINGPROCESSFACTORY_H
#include "ProcessClass/Process.h"
#include <memory>
#include <vector>
#include <QMap>
#include "utils/ProcessOrder.h"
class StringProcessFactory
{
public:
    StringProcessFactory();
    //std::vector<std::unique_ptr<Process>> create(QMap<QString, QString> params);
    std::unique_ptr<Process> create(ProcessOrder order);
};

#endif // STRINGPROCESSFACTORY_H
