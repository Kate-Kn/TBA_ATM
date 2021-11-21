#ifndef TRANSACTIONSCARDACCOUNT_H
#define TRANSACTIONSCARDACCOUNT_H
#include "ITransaction.h"

class TransactionsCardAccount: public ITransaction{
private:
    string _description;
    virtual string doDisplay() const override;
public:
    TransactionsCardAccount(double sum, QDate date, string description);
    TransactionsCardAccount(const TransactionsCardAccount&);
    ~TransactionsCardAccount(){return;}
    string description() const {return _description;}
};

#endif
