#include "SetFirstCharUp.h"
#include <QStringList>

void SetFirstCharUp::stringProcessor(QString &str)
{
    QStringList lines = str.split("\n");
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
        str = lines.join("\n");
}

/*************************************************************************************/
SetFirstCharUp::SetFirstCharUp()
{

}

/*************************************************************************************/
SetFirstCharUp::~SetFirstCharUp()
{

}


