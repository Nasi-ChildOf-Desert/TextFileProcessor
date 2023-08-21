#ifndef PROCESSORMANAGER_H
#define PROCESSORMANAGER_H
#include <QString>
#include "TextFileManager.h"
#include <QMap>

class processorManager
{
private:

    TextFileManager _fileManager;
    QMap<QString, QString> _params ;
    QString _fileContent;
    bool _doUpperCase = false;
    bool _doLowerCase = false;
    bool _setFirsCharToUpper = false;
    void paramInitialize();
    void doUpperCase();
    void doLowerCase();
    void setFirstChar();

public:
    processorManager();
    void init(QMap<QString, QString>& parameters);
    void startProcess();
    QString responseOfProcess();
};

#endif // PROCESSORMANAGER_H
