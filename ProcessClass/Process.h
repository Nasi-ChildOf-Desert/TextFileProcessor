#ifndef PROCESS_H
#define PROCESS_H
#include <QString>
#include "BasicStringProcess.h"
class Process
{
public:
    virtual void stringProcessor(std::string& str)=0;
    ~Process(){};
};

#endif // PROCESS_H
