#ifndef SETFIRSTCHARUP_H
#define SETFIRSTCHARUP_H

#include "Process.h"

class SetFirstCharUp: public Process
{

public:
    void stringProcessor(QString& str);
    SetFirstCharUp();
    ~SetFirstCharUp();
};

#endif // SETFIRSTCHARUP_H
