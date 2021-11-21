#include "Cryptor.h"

#include <QChar>
#include <qchar.h>

QString Cryptor::doCryptPassword(const QString& password) const {
    QString encryptPassword;
    int key = password.size();
    for(int i=0;i<password.size();i++)
    {
        encryptPassword += QString::number(password.toStdString().c_str()[i]+(key/5));
    }
    return encryptPassword;
}
