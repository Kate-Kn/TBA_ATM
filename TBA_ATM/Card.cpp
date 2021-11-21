#include "Card.h"
Card::Card(string newCardNumber, double newBalance, User newUser):
    _cardNumber(newCardNumber), _balance(newBalance), _user(newUser) {
    if(isNumericalSequence(cardNumber()))
        throw BadCard("Card must consist of numbers.");
    if(cardNumber().length() != 4)
        throw BadCard("Card must consist of 4 numbers.");
    if(balance() <0.0 )
        throw BadCard("Balance can't be less then 0");
    return;
}

Card::Card(const Card& card):
    _cardNumber(card.cardNumber()), _balance(card.balance()), _user(card.user()) {
    return;
}
