#ifndef ITRANSACTION_H
#define ITRANSACTION_H
#include <QDate>
#include <string>
using namespace std;

class ITransaction{
private:
    double _sum;
    QDate _date;
    virtual string doDisplay() const {return "";};
public:
    class BadTransction;
    ITransaction(double newSum, QDate newDate): _sum(newSum), _date(newDate){return;}
    virtual ~ITransaction() { return; }
    double sum() const { return _sum; }
    QDate date() const { return _date; }
    string display() const { return doDisplay(); }

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
