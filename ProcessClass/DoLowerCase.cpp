#include "DoLowerCase.h"

/*************************************************************************************/


DoLowerCase::DoLowerCase(){}

/*************************************************************************************/
DoLowerCase::~DoLowerCase()
{

}

void DoLowerCase::stringProcessor(std::string &str)
{
    str = BasicStringProcess::str_tolower(str);
}


