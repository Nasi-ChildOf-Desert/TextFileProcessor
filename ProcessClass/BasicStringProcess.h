#ifndef BASICSTRINGPROCESS_H
#define BASICSTRINGPROCESS_H
#include <string>
#include <algorithm>

class BasicStringProcess
{
public:
   static std::string str_toupper(std::string s)
    {
       /*std::transform applies the given function to a range and stores the result in another range,
         keeping the original elements order and beginning at d_first. */
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
