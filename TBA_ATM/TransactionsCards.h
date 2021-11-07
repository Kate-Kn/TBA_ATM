#ifndef TRANSACTIONSCARDS_H
#define TRANSACTIONSCARDS_H
#include "ITransaction.h"

class TransactionsCards: public ITransaction{
private:
    string _description;
    virtual string doDisplay() const override;
public:
    TransactionsCards(double sum, QDate date, string description);
    TransactionsCards(const TransactionsCards&);
    ~TransactionsCards(){return;}
    string description() const {return _description;}
};

#endif
