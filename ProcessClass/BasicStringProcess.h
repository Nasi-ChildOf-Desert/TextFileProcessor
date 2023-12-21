#ifndef BASICSTRINGPROCESS_H
#define BASICSTRINGPROCESS_H
#include <string>

class BasicStringProcess
{
public:
   static std::string str_toupper(std::string s)
    {
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c){ return std::toupper(c); } // correct
                      );
        return s;
    }

  static std::string str_tolower(std::string s)
   {
       std::transform(s.begin(), s.end(), s.begin(),
                      [](unsigned char c){ return std::tolower(c); } // correct
                     );
       return s;
   }
};

#endif // BASICSTRINGPROCESS_H
