#ifndef SETFIRSTCHARUP_H
#define SETFIRSTCHARUP_H
#include <QString>
#include "Process.h"

class SetFirstCharUp: public Process
{
    QString& _param  ;
    void firstCharUp();
public:
    SetFirstCharUp(QString& param);
    ~SetFirstCharUp();
};

#endif // SETFIRSTCHARUP_H
