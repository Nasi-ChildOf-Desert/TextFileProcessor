
#include <iostream>
#include <QString>
#include <QMap>
#include "processorManager.h"
#include <QDebug>
#include "utils/ProcessOrder.h"
//sudo gdbserver 127.0.0.1:1234 ./TextFileProcessor -i ../sample/file-1.txt -o ../sample/file2.txt -U

QMap<QString, QString> parseParameters(int argc, char* argv[]) {
    QMap<QString, QString> parameters;

    for (int i = 1; i < argc; ++i) {
        QString arg = argv[i];
        if (arg.length() > 1 && arg[0] == '-') {
            QString parameter = arg.mid(1);
            QString value = "";
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
bool isCorrectInput(const QMap<QString, QString>& parameters)
{

    if (parameters.contains("i") && parameters.value("i").isEmpty()) {
         std::cout << " i is: " <<  parameters.value("i").toStdString()<< std::endl;
        // Key 'i' exists in the map and has a non-empty value
        return false;
    }

    if (parameters.contains("o") && parameters.value("o").isEmpty()) {
        // Key 'o' exists in the map and has a non-empty value
          std::cout << " o is: " <<  parameters.value("o").toStdString()<< std::endl;
        return false;
    }

    return true;
}

/*************************************************************************************/
void printParameters(const QMap<QString, QString>& parameters) {
    for (auto it = parameters.begin(); it != parameters.end(); ++it) {
        std::cout << "Parameter: " << it.key().toStdString();
        if (!it.value().isEmpty()) {
            std::cout << " Value: " << it.value().toStdString();
        }
        std::cout << std::endl;
    }
}

/*************************************************************************************/
int main(int argc, char *argv[])
{

    if (argc > 1) {
            QMap<QString, QString> parameters = parseParameters(argc, argv);
            printParameters(parameters);
          if(!isCorrectInput(parameters))
          {
               std::cout << "No command-line arguments is complted tell addrese . -i for input address and -o for output address." << std::endl;
               return 0;
          }
          processorManager process;
              process.sourceAddress = parameters.value("i");
              process.destAddress = parameters.value("o");

          if (parameters.contains("U")) {
             process.orders.push_back(ProcessOrder::UpperCase);
          }
          if (parameters.contains("L")) {
               process.orders.push_back(ProcessOrder::LowerCase);
          }
          if (parameters.contains("u")) {
               process.orders.push_back(ProcessOrder::FirstCharUp);
          }
           if(!parameters.contains("U") && !parameters.contains("L") && !parameters.contains("u")) {
               process.orders.push_back(ProcessOrder::FirstCharUp);
          }
          process.init(parameters);
        } else {
            std::cout << "No command-line arguments provided." << std::endl;
        }
    return 0;
}
