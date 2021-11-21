#ifndef CARD_H
#define CARD_H
#include "User.h"
#include "StringValidator.h"
#include "Currency.h"

#include <QString>

using namespace std;

class Card {
private:
    QString _cardNumber;
    double _balance;
    User _user;
    Currency _currency;
public:
    class BadCard;
    Card(QString cardNumber, double balance, User user, Currency currency);
    Card(const Card&);
    Card(){ return; }
    ~Card(){ return; }
    const QString& cardNumber() const { return _cardNumber; }
    const double& balance() const { return _balance; }
    const User& user() const { return _user; }
    const Currency& currency() const { return _currency; }
    void cardNumber(const QString& );
    void balance(const double&);
    void user(const User&);
    void currency(const Currency&);
};

class Card::BadCard{
private:
    const QString _reason;
public:
    BadCard(QString reason = "") :
        _reason(reason){};
    ~BadCard() {};
    QString diagnose() const { return _reason; };
};

#endif
