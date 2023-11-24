#ifndef PROCESS_H
#define PROCESS_H
#include <QString>

class Process
{
public:
    virtual void stringProcessor(QString& str)=0;
    ~Process(){};
};

#endif // PROCESS_H
