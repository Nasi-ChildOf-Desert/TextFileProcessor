#ifndef DOLOWERCASE_H
#define DOLOWERCASE_H
#include <QString>
#include "Process.h"

class DoLowerCase: public Process
{

public:

    DoLowerCase();
    ~DoLowerCase();
    void stringProcessor(std::string& str);
};

#endif // DOLOWERCASE_H



