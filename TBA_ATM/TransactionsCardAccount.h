#ifndef TRANSACTIONSCARDACCOUNT_H
#define TRANSACTIONSCARDACCOUNT_H
#include "ITransaction.h"

class TransactionsCardAccount: public ITransaction{
private:
    QString _description;
    virtual QString doDisplay() const override;
public:
    TransactionsCardAccount(double sum, QDate date, QString description);
    TransactionsCardAccount(const TransactionsCardAccount&);
    TransactionsCardAccount() { return; }
    ~TransactionsCardAccount(){return;}
    const QString& description() const {return _description;}
    void description(const QString& newDescription) {_description = newDescription; return; }
};

#endif
