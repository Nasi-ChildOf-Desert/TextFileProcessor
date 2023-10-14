#ifndef DOLOWERCASE_H
#define DOLOWERCASE_H
#include <QString>
#include "Process.h"

class DoLowerCase: public Process
{
    QString& _param  ;
    void doLower();
public:

    DoLowerCase(QString& param);
    ~DoLowerCase();
};

#endif // DOLOWERCASE_H



