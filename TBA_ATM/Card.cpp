#include "Card.h"

Card::Card(string cardNumber, double balance, User user):
    _cardNumber(cardNumber), _balance(balance), _user(user) {
    return;
}
