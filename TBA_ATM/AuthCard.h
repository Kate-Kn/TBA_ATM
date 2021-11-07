#ifndef AUTHCARD_H
#define AUTHCARD_H
#include <string>
#include "StringValidator.h"
using namespace std;

class AuthCard{
private:
    string _cardNum;
    string _pincode;
public:
    class BadAuthCard;
    AuthCard(string newCardNumber, string newPincode);
    AuthCard(const AuthCard& authCard);
    string cardNumber() const { return _cardNum; }
    string pincode() const { return _pincode; }
};

class AuthCard::BadAuthCard{
private:
    const string _reason;
public:
    BadAuthCard(string reason = "") :
        _reason(reason){};
    ~BadAuthCard() {};
    string diagnose() const { return _reason; };
};

#endif
