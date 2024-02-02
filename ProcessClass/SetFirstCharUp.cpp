#include "SetFirstCharUp.h"
#include <sstream>


void SetFirstCharUp::stringProcessor(std::string &str)
{

    bool cap = true;

        for(unsigned int i = 0; i <= str.length(); i++)
        {
            if (isalpha(str[i]) && cap == true)
            {
                str[i] = toupper(str[i]);
                cap = false;
            }
            else if (isspace(str[i]))
            {
                cap = true;
            }
        }
}

/*************************************************************************************/
SetFirstCharUp::SetFirstCharUp()
{

}

/*************************************************************************************/
SetFirstCharUp::~SetFirstCharUp()
{

}


