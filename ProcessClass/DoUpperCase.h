#ifndef DOUPPERCASE_H
#define DOUPPERCASE_H
#include <QString>
#include "Process.h"

class DoUpperCase: public Process
{
    QString& _param  ;
    void doUpper();
public:
    DoUpperCase(QString& param);
    ~DoUpperCase();
};

#endif // DOUPPERCASE_H
