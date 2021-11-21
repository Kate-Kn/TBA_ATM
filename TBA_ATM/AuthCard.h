#ifndef AUTHCARD_H
#define AUTHCARD_H
#include "StringValidator.h"

#include <QString>
using namespace std;

class AuthCard{
private:
    QString _cardNum;
    QString _pincode;
public:
    class BadAuthCard;
    AuthCard(QString newCardNumber, QString newPincode);
    AuthCard(const AuthCard& authCard);
    AuthCard() { return; }
    const QString& cardNumber() const { return _cardNum; }
    const QString& pincode() const { return _pincode; }
    void cardNumber(const QString& newCardNum);
    void pincode(const QString& newPincode);
};

class AuthCard::BadAuthCard{
private:
    const QString _reason;
public:
    BadAuthCard(QString reason = "") :
        _reason(reason){};
    ~BadAuthCard() {};
    QString diagnose() const { return _reason; };
};

#endif
