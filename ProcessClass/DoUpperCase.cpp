#include "DoUpperCase.h"



/*************************************************************************************/
DoUpperCase::DoUpperCase()
{

}

/*************************************************************************************/
DoUpperCase::~DoUpperCase()
{

}

void DoUpperCase::stringProcessor(QString &str)
{
    auto strUpper = str.toUpper();
    str.clear();
    str =strUpper;

};
