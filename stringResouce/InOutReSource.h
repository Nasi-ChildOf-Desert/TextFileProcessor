#ifndef INOUTRESOURCE_H
#define INOUTRESOURCE_H
#include <string>

class InOutReSource
{
public:
    ~InOutReSource();
    virtual std::string getStr() = 0;
    virtual void setStr(std::string str)=0;
};

#endif //INOUTRESOURCE_H
