#ifndef ITRANSACTIONSERVICE_H
#define ITRANSACTIONSERVICE_H
#include "TransactionCash.h"
#include "TransactionsCardAccount.h"
#include "TransactionsCards.h"
#include "Card.h"
#include "Account.h"
#include "IStorage.h"

class ITransactionService {
private:
    IStorage _storage;
    virtual void doTransactionCardAccount(const TransactionsCardAccount&, const Card&, const Account&) const { return; }
    virtual void doTransactionCash(const TransactionCash&, const Card&) const { return; }
    virtual void doTransactionCards(const TransactionsCards&, const Card&, const Card&) const { return; }
public:
    class BadTransactionService;
    ITransactionService(IStorage newStorage): _storage(newStorage) { return; }
    ~ITransactionService(){ return; }
    void transactionCardAccount(const TransactionsCardAccount& transaction, const Card& card, const Account& acc) const
    { return doTransactionCardAccount(transaction, card, acc); }
    void transactionCash(const TransactionCash& transaction, const Card& card) const
    { return doTransactionCash(transaction, card); }
    void transactionCards(const TransactionsCards& transaction, const Card& firstCard, const Card& secondCard) const
    { return doTransactionCards(transaction, firstCard, secondCard); }
    IStorage storage() const { return _storage; }
};

class ITransactionService::BadTransactionService{
private:
    const string _reason;
public:
    BadTransactionService(string reason = "") :
        _reason(reason){};
    ~BadTransactionService() {};
    string diagnose() const { return _reason; };
};

#endif
