#include "SetFirstCharUp.h"

#include <sstream>

void SetFirstCharUp::split_str(const std::string &str, const char delim, std::vector<std::string> &out)
{
    // create a stream from the string
      std::stringstream s(str);

     std::string s2;
     while (std:: getline (s, s2, delim) )
        {
            out.push_back(s2); // store the string in s2
         }
}

/*************************************************************************************/
void SetFirstCharUp::stringProcessor(std::string &str)
{
    std::vector <std::string> out;
     split_str (str, delim, out);
     // use range based for loop
     std::string result;
                 for (auto &word: out)
                 {
                     if (!word.empty()) {
                         char firstChar = word.at(0);
                         if (isalpha(firstChar)) {
                             word[0] = std::toupper(firstChar);
                         }
                     }
                     result.append(" " + word)  ;
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


