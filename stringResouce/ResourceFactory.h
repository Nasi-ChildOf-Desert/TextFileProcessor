#ifndef RESOURCEFACTORY_H
#define RESOURCEFACTORY_H
#include "InOutReSource.h"
#include "TextFileManager.h"
#include <memory>
class ResourceFactory
{
public:
    ResourceFactory();
    std::unique_ptr<InOutReSource> create(char choosen);
};

#endif // RESOURCEFACTORY_H
