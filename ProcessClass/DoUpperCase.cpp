#include "DoUpperCase.h"

void DoUpperCase::doUpper()
{
    auto modifiedContent =  _param.toUpper();
    _param.clear();
    _param  = modifiedContent;
}

/*************************************************************************************/
DoUpperCase::DoUpperCase(QString& param):_param(param){doUpper();}

/*************************************************************************************/
DoUpperCase::~DoUpperCase()
{

};
