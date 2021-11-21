#ifndef TRANSACTIONSERVICE_H
#define TRANSACTIONSERVICE_H
#include "ITransactionService.h"

class TransactionService: public ITransactionService{
private:
    virtual void doTransactionCardAccount(const TransactionsCardAccount&, const Card&, const Account&) override;
    virtual void doTransactionCash(const TransactionCash&, const Card&) override;
    virtual void doTransactionCards(const TransactionsCards&, const Card&, const Card&) override;
    TransactionService(const TransactionService& service) = delete;
public:
    TransactionService(IStorage* newStorage): ITransactionService(newStorage){ return; }
    ~TransactionService(){ return; }
};

#endif // TRANSACTIONSERVICE_H
