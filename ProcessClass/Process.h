#ifndef PROCESS_H
#define PROCESS_H
#include <string>
#include "BasicStringProcess.h"
class Process
{
public:
    virtual void stringProcessor(std::string& str)=0;
    virtual ~Process(){};
};

#endif // PROCESS_H
