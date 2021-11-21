#ifndef ITRANSACTION_H
#define ITRANSACTION_H
#include <QDate>
#include <QString>
using namespace std;

class ITransaction{
private:
    double _sum;
    QDate _date;
    virtual QString doDisplay() const {return "";};
public:
    class BadTransction;
    ITransaction(double newSum, QDate newDate): _sum(newSum), _date(newDate){ return; }
    ITransaction() { return; }
    virtual ~ITransaction() { return; }
    double sum() const { return _sum; }
    const QDate& date() const { return _date; }
    void date(const QDate& newDate) { _date = newDate; return; }
    QString display() const { return doDisplay(); }

};

class ITransaction::BadTransction{
private:
    const QString _reason;
public:
    BadTransction(QString reason = "") :
        _reason(reason){};
    ~BadTransction() {};
    QString diagnose() const { return _reason; };
};


#endif
