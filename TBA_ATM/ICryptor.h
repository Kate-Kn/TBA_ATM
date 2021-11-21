#ifndef ICRYPTOR_H
#define ICRYPTOR_H

#include <QString>

using namespace std;

class ICryptor{
private:
    virtual QString doCryptPassword(const QString&) const = 0;
public:
    class BadCryptor;
    ICryptor(){ return; };
    virtual ~ICryptor(){ return; };
    QString cryptPassword(const QString& str) const{ return doCryptPassword(str); }
};

class ICryptor::BadCryptor{
private:
    const QString _reason;
public:
    BadCryptor(QString reason = "") :
        _reason(reason){};
    ~BadCryptor() {};
    QString diagnose() const { return _reason; };
};

#endif // ICRYPTOR_H
