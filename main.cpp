
#include <iostream>
#include <map>
#include "processorManager.h"
#include "utils/ProcessOrder.h"
#include "utils/StrStruct.h"
#include "stringResouce/ResourceFactory.h"
#include "stringResouce/InOutReSource.h"
#include "stringResouce/TextFileManager.h"
#include <memory>

//sudo gdbserver 127.0.0.1:1234 ./TextFileProcessor -i ../sample/file-1.txt -o ../sample/file2.txt -U
//typedef  mapstr;
using mapstr = std::map<std::string, std::string>;

//modern c++
//typedef --> alias

bool check(const mapstr& v ,std::string x)
{
      if(v.find(x) == v.end())
          return false;
      else if(!v.find(x)->second.empty())
          return true ;
      return true;
}

mapstr parseParameters(int argc, char* argv[]) {
    mapstr parameters;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.length() > 1 && arg[0] == '-') {
            std::string parameter = arg.substr(1);
            std::string value = "";
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                value = argv[i + 1];
                ++i;
            }
            parameters[parameter] = value;
        }
    }

    return parameters;
}

/*************************************************************************************/
bool isCorrectInput(const mapstr& parameters)
{

    if (!(check(parameters,"i"))) {
         std::cout << " i is: " <<   parameters.find("i")->second.data()<< std::endl;
        // Key 'i' exists in the map and has a non-empty value
        return false;
    }

    if (!check(parameters,"o")) {
        // Key 'o' exists in the map and has a non-empty value
          std::cout << " o is: " <<   parameters.find("o")->second.data()<< std::endl;
        return false;
    }

    return true;
}

/*************************************************************************************/
void printParameters(const mapstr& parameters) {
    for (auto it = parameters.begin(); it != parameters.end(); ++it) {
        std::cout << "Parameter: " << it->first.data();
        if (!(*it).second.empty()) {
            std::cout << " Value: " << (*it).second;
        }
        std::cout << std::endl;
    }
}

/*************************************************************************************/
int main(int argc, char *argv[])
{

    if (argc > 1) {
           mapstr parameters = parseParameters(argc, argv);
            printParameters(parameters);
          if(!isCorrectInput(parameters))
          {
               std::cout << "No command-line arguments is complted tell addrese . -i for input address and -o for output address." << std::endl;
               return 0;
          }
          strStruct strstruct;
          processorManager process;
          ResourceFactory rFactory;

          std::unique_ptr<InOutReSource> inOutSource = rFactory.create('F');
          auto textFileSource = std::make_unique<TextFileManager>(dynamic_cast<TextFileManager&>(*inOutSource));
         textFileSource->init(parameters.at("i") , parameters.at("o"));

          auto nothingchoosen = true;
          if (parameters.find("U") != parameters.end()) {
             strstruct.orders.push_back(ProcessOrder::UpperCase);
             nothingchoosen = false;
          }
          if (parameters.find("L") != parameters.end()) {
                strstruct.orders.push_back(ProcessOrder::LowerCase);
               nothingchoosen = false;
          }
          if (parameters.find("u") != parameters.end()) {
                strstruct.orders.push_back(ProcessOrder::FirstCharUp);
          }
           if(nothingchoosen) {
                strstruct.orders.push_back(ProcessOrder::FirstCharUp);
                nothingchoosen = false;
          }

         process.setStrStruct(strstruct);

         process.injectSourceData(std::move(textFileSource));
         process.init();

        } else {
            std::cout << "No command-line arguments provided." << std::endl;
        }
    return 0;
}
