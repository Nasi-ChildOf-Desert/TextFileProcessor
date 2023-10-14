#include "SetFirstCharUp.h"
#include <QStringList>
void SetFirstCharUp::firstCharUp()
{
    QStringList lines = _param.split("\n");
        for (QString& line : lines) {
            QStringList words = line.split(' ', QString::SkipEmptyParts);
            for (QString& word : words) {
                if (!word.isEmpty()) {
                    QChar firstChar = word.at(0);
                    if (firstChar.isLetter()) {
                        word[0] = firstChar.toUpper();
                    }
                }
            }
            line = words.join(' ');
        }
        _param = lines.join("\n");
}

/*************************************************************************************/
SetFirstCharUp::SetFirstCharUp(QString &param):_param(param){firstCharUp();}

/*************************************************************************************/
SetFirstCharUp::~SetFirstCharUp()
{

}


