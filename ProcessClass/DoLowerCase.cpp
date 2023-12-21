#include "DoLowerCase.h"

/*************************************************************************************/


DoLowerCase::DoLowerCase(){}

/*************************************************************************************/
DoLowerCase::~DoLowerCase()
{

}

void DoLowerCase::stringProcessor(std::string &str)
{
    auto strLower = BasicStringProcess::str_tolower(str);
    str.clear();
    str = strLower;
}


