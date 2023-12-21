#ifndef SETFIRSTCHARUP_H
#define SETFIRSTCHARUP_H
#include <string>
#include "Process.h"
#include <vector>
class SetFirstCharUp: public Process
{
private:
     const char delim = ' ';
     void split_str( std::string const &str, const char delim,
             std::vector  <std::string> &out ) ;
public:
    void stringProcessor(std::string& str);
    SetFirstCharUp();
    ~SetFirstCharUp();
};

#endif // SETFIRSTCHARUP_H
