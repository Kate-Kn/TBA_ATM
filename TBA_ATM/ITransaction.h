#ifndef ITRANSACTION_H
#define ITRANSACTION_H
#include <QDate>
#include <string>
using namespace std;

class ITransaction{
private:
    double _sum;
    QDate _date;
    virtual string doDisplay() const = 0;
public:
    class BadTransction;
    ITransaction(double sum, QDate date): _sum(sum), _date(date){return;}
    double sum() const { return _sum; }
    QDate date() const { return _date; }
    string display() const { return doDisplay(); }
    virtual ~ITransaction() {return;}
};

class ITransaction::BadTransction{
private:
    const string _reason;
public:
    BadTransction(string reason = "") :
        _reason(reason){};
    ~BadTransction() {};
    string diagnose() const { return _reason; };
};


#endif
