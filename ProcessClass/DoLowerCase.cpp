#include "DoLowerCase.h"

/*************************************************************************************/
DoLowerCase::DoLowerCase(){}

/*************************************************************************************/
DoLowerCase::~DoLowerCase()
{

}

void DoLowerCase::stringProcessor(QString &str)
{
    auto strLower = str.toLower();
    str.clear();
    str = strLower;
}


