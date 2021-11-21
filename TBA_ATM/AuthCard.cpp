#include "AuthCard.h"

AuthCard::AuthCard(QString newCardNumber, QString newPincode):
_cardNum(newCardNumber), _pincode(newPincode){
    if(!isNumericalSequence(cardNumber()))
        throw BadAuthCard("Card must consist of numbers.");
    if(cardNumber().length() != 4)
        throw BadAuthCard("Card must consist of 4 numbers.");
}
AuthCard::AuthCard(const AuthCard& authCard):
_cardNum(authCard.cardNumber()), _pincode(authCard.pincode()){
    return;
};

void AuthCard::cardNumber(const QString& newCardNum){
    if(!isNumericalSequence(newCardNum))
        throw BadAuthCard("Card must consist of numbers.");
    if(newCardNum.length() != 4)
        throw BadAuthCard("Card must consist of 4 numbers.");
    _cardNum = newCardNum;
    return;
}

void AuthCard::pincode(const QString& newPincode){
    _pincode = newPincode;
    return;
}
