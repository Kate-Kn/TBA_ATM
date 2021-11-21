#include "TransactionService.h"

void TransactionService::doTransactionCardAccount(const TransactionsCardAccount& transaction, const Card& card, const Account& acc) const{
    if(card.balance()<transaction.sum())
        throw BadTransactionService("Cannot process the payment: not enough money on the card.");
    storage().addTransactionCardAccount(transaction, card, acc);
}
void TransactionService::doTransactionCash(const TransactionCash& transaction, const Card& card) const{
    if(card.balance()<transaction.sum())
        throw BadTransactionService("Cannot process the payment: not enough money on the card.");
    storage().addTransactionCash(transaction, card);
}
void TransactionService::doTransactionCards(const TransactionsCards& transaction, const Card& firstCard, const Card& secondCard) const{
    if(firstCard.balance()<transaction.sum())
        throw BadTransactionService("Cannot process the payment: not enough money on the card.");
    storage().addTransactionCards(transaction, firstCard, secondCard);
}
