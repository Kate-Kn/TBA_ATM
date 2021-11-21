#ifndef CURRENCY_H
#define CURRENCY_H

#include <QString>

using namespace std;

class Currency{
private:
    QString _name;
    double _rateUAH;
public:
    class BadCurrency;
    Currency(QString newName, double newRateUAH);
    Currency() { return; }
    Currency(const Currency& currency);
    ~Currency() { return; }
    const QString& name() const { return _name; }
    const double& rateUAH() const {return _rateUAH; }
    void name(const QString& newName);
    void rateUAH(const double& newRate);
};

class Currency::BadCurrency{
private:
    const QString _reason;
public:
    BadCurrency(QString reason = "") :
        _reason(reason){};
    ~BadCurrency() {};
    QString diagnose() const { return _reason; };
};

#endif // CURRENCY_H
