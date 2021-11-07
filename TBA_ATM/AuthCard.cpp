#include "AuthCard.h"

AuthCard::AuthCard(string newCardNumber, string newPincode):
_cardNum(newCardNumber), _pincode(newPincode){
    if(isNumericalSequence(cardNumber()))
        throw BadAuthCard("Card must consist of numbers.");
    if(cardNumber().length() != 4)
        throw BadAuthCard("Card must consist of 4 numbers.");
    if(isNumericalSequence(pincode()))
        throw BadAuthCard("Pincode must consist of numbers.");
    if(pincode().length() != 4)
        throw BadAuthCard("Pincode must consist of 4 numbers.");
}
AuthCard::AuthCard(const AuthCard& authCard):
_cardNum(authCard.cardNumber()), _pincode(authCard.pincode()){
    return;
};
