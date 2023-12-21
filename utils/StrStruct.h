#ifndef STRSTRUCT_H
#define STRSTRUCT_H
#include <vector>
#include <string>
#include "ProcessOrder.h"
struct strStruct
{
    std::vector <ProcessOrder > orders;
    std::string source;
    std::string destination;

};

#endif // STRSTRUCT_H
