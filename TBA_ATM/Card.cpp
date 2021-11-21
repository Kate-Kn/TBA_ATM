#include "Card.h"
Card::Card(QString newCardNumber, double newBalance, User newUser, Currency newCurrency):
    _cardNumber(newCardNumber), _balance(newBalance), _user(newUser), _currency(newCurrency) {
    if(!isNumericalSequence(cardNumber()))
        throw BadCard("Card must consist of numbers.");
    if(cardNumber().length() != 4)
        throw BadCard("Card must consist of 4 numbers.");
    if(balance() <0.0 )
        throw BadCard("Balance can't be less then 0");
    return;
}

Card::Card(const Card& card):
    _cardNumber(card.cardNumber()), _balance(card.balance()), _user(card.user()), _currency(card.currency()) {
    return;
}

void Card::cardNumber(const QString& newCardNum){
    if(!isNumericalSequence(newCardNum))
        throw BadCard("Card must consist of numbers.");
    if(newCardNum.length() != 4)
        throw BadCard("Card must consist of 4 numbers.");
    _cardNumber = newCardNum;
    return;
}

void Card::balance(const double& newBalance){
    if(newBalance <0.0 )
        throw BadCard("Balance can't be less then 0");
    _balance = newBalance;
    return;
}

void Card::user(const User& newUser){
    _user = newUser;
    return;
}

void Card::currency(const Currency& newCurrency){
    _currency = newCurrency;
    return;
}
