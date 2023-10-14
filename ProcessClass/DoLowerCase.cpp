#include "DoLowerCase.h"

void DoLowerCase::doLower()
{
    auto modifiedContent =  _param.toLower();
    _param.clear();
    _param  = modifiedContent;

}

/*************************************************************************************/
DoLowerCase::DoLowerCase(QString& param):_param(param){doLower();}

/*************************************************************************************/
DoLowerCase::~DoLowerCase()
{

}


