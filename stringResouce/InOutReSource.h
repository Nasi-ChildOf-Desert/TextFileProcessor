#ifndef INOUTRESOURCE_H
#define INOUTRESOURCE_H
#include <string>

class InOutReSource
{
public:
    virtual std::string getStr() = 0;
    virtual void setStr(std::string str)=0;
    virtual ~InOutReSource(){};;
};

#endif //INOUTRESOURCE_H
