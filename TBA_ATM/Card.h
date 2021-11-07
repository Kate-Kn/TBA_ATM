#ifndef CARD_H
#define CARD_H
#include <string>
#include "User.h"
#include "StringValidator.h"
using namespace std;

class Card {
private:
    string _cardNumber;
    double _balance;
    User _user;
public:
    class BadCard;
    Card(string cardNumber, double balance, User user);
    Card(const Card&);
    ~Card(){ return; }
    string cardNumber() const { return _cardNumber; }
    double balance() const { return _balance; }
    User user() const { return _user; }
};

class Card::BadCard{
private:
    const string _reason;
public:
    BadCard(string reason = "") :
        _reason(reason){};
    ~BadCard() {};
    string diagnose() const { return _reason; };
};

#endif
