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
    str = BasicStringProcess::str_toupper(str);
};
