#ifndef CARD_H
#define CARD_H
#include <string>
#include "User.h"
using namespace std;

class Card {
private:
    string _cardNumber;
    double _balance;
    User _user;
public:
    Card(string cardNumber, double balance, User user);
    ~Card(){ return; }
    string cardNumber() const { return _cardNumber; }
    double balance() const { return _balance; }
    User user() const { return _user; }
};

#endif