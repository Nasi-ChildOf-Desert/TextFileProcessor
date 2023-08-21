#ifndef TEXTFILEMANAGER_H
#define TEXTFILEMANAGER_H
#include <QString>

class TextFileManager
{
private:
    QString _sourceFilePath;
    QString _destinationFilePath;
    QString _fileContents;

public:
    TextFileManager();
    void init( QString sourceFilePath, QString destinationFilePath);
    bool openFile();
    bool writeFile();
    QString getContent();
    void setContent( QString fileContents);
};

#endif // TEXTFILEMANAGER_H
