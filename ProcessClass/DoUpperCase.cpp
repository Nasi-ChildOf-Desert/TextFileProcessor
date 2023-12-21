#include "DoUpperCase.h"



/*************************************************************************************/
DoUpperCase::DoUpperCase()
{

}

/*************************************************************************************/
DoUpperCase::~DoUpperCase()
{

}

void DoUpperCase::stringProcessor(std::string &str)
{
    auto strUpper = BasicStringProcess::str_toupper(str);
    str.clear();
    str = strUpper;

};
