#include "TransactionService.h"

void TransactionService::doTransactionCardAccount(const TransactionsCardAccount& transaction, const Card& card, const Account& acc) {
    double currencyTaken = transaction.sum()*card.currency().rateUAH();
    if(card.balance()<currencyTaken)
        throw BadTransactionService("Cannot process the payment: not enough money on the card.");
    try {
        (*storage()).addTransactionCardAccount(transaction, card, acc);
    }  catch (IStorage::BadStorage bs) {
        throw BadTransactionService(bs.diagnose());
    }
}
void TransactionService::doTransactionCash(const TransactionCash& transaction, const Card& card) {
    try {
        (*storage()).addTransactionCash(transaction, card);
    }  catch (IStorage::BadStorage bs) {
        throw BadTransactionService(bs.diagnose());
    }

}
void TransactionService::doTransactionCards(const TransactionsCards& transaction, const Card& firstCard, const Card& secondCard) {
    double currencyTaken = transaction.sum()*firstCard.currency().rateUAH();
    if(firstCard.balance()<currencyTaken)
        throw BadTransactionService("Cannot process the payment: not enough money on the card.");
    try {
        (*storage()).addTransactionCards(transaction, firstCard, secondCard);
    }  catch (IStorage::BadStorage bs) {
        throw BadTransactionService(bs.diagnose());
    }
}
