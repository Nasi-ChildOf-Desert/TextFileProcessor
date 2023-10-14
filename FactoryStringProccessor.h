#ifndef FACTORYSTRINGPROCCESSOR_H
#define FACTORYSTRINGPROCCESSOR_H
#include <QString>
#include <QMap>
#include <QObject>
#include "ProcessClass/Process.h"
#include "utils/ProcessOrder.h"
#include <memory>
class FactoryStringProccessor: public QObject
{
  Q_OBJECT

public:

 std::shared_ptr<Process> create(ProcessOrder type, QString &fileContent);

signals:
 void announceJobDone();
};
#endif // FACTORYSTRINGPROCCESSOR_H
