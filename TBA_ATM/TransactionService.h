#ifndef TRANSACTIONSERVICE_H
#define TRANSACTIONSERVICE_H
#include "ITransactionService.h"

class TransactionService: public ITransactionService{
private:
    virtual void doTransactionCardAccount(const TransactionsCardAccount&, const Card&, const Account&) const override;
    virtual void doTransactionCash(const TransactionCash&, const Card&) const override;
    virtual void doTransactionCards(const TransactionsCards&, const Card&, const Card&) const override;
public:
    TransactionService(IStorage newStorage): ITransactionService(newStorage){ return; }
    TransactionService(const TransactionService& service): ITransactionService(service.storage()){ return; }
    ~TransactionService(){ return; }
};

#endif // TRANSACTIONSERVICE_H
