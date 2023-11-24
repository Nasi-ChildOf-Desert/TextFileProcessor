#ifndef DOUPPERCASE_H
#define DOUPPERCASE_H
#include <QString>
#include "Process.h"

class DoUpperCase: public Process
{

public:
    DoUpperCase();
    ~DoUpperCase();
     void stringProcessor(QString& str);
};

#endif // DOUPPERCASE_H
