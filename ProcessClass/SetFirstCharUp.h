#ifndef SETFIRSTCHARUP_H
#define SETFIRSTCHARUP_H
#include <string>
#include "Process.h"
#include <vector>
class SetFirstCharUp: public Process
{

public:
    void stringProcessor(std::string& str);
    SetFirstCharUp();
    ~SetFirstCharUp();
};

#endif // SETFIRSTCHARUP_H
