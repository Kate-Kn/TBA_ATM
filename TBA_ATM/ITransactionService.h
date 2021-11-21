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
    IStorage* _storage;
    virtual void doTransactionCardAccount(const TransactionsCardAccount&, const Card&, const Account&) =0;
    virtual void doTransactionCash(const TransactionCash&, const Card&) = 0;
    virtual void doTransactionCards(const TransactionsCards&, const Card&, const Card&) = 0;
public:
    class BadTransactionService;
    ITransactionService(IStorage* newStorage): _storage(newStorage) { return; }
    ~ITransactionService(){ delete _storage; return; }
    void transactionCardAccount(const TransactionsCardAccount& transaction, const Card& card, const Account& acc)
    { return doTransactionCardAccount(transaction, card, acc); }
    void transactionCash(const TransactionCash& transaction, const Card& card)
    { return doTransactionCash(transaction, card); }
    void transactionCards(const TransactionsCards& transaction, const Card& firstCard, const Card& secondCard)
    { return doTransactionCards(transaction, firstCard, secondCard); }
    IStorage* storage() const { return _storage; }
};

class ITransactionService::BadTransactionService{
private:
    const QString _reason;
public:
    BadTransactionService(QString reason = "") :
        _reason(reason){};
    ~BadTransactionService() {};
    QString diagnose() const { return _reason; };
};

#endif
