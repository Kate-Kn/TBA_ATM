#ifndef TRANSACTIONCASH_H
#define TRANSACTIONCASH_H
#include "ITransaction.h"

class TransactionCash : public ITransaction{
private:
    virtual string doDisplay() const override;
public:
    TransactionCash(double sum, QDate date);
    ~TransactionCash(){return;}
};

#endif
