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
    void paramInitialize();

public:
    processorManager();
    void init(QMap<QString, QString>& parameters);
    void startSaving();
    QString responseOfProcess();
};

#endif // PROCESSORMANAGER_H
