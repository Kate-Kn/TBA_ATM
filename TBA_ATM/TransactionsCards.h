#ifndef TRANSACTIONSCARDS_H
#define TRANSACTIONSCARDS_H
#include "ITransaction.h"

class TransactionsCards: public ITransaction{
private:
    QString _description;
    virtual QString doDisplay() const override;
public:
    TransactionsCards(double sum, QDate date, QString description);
    TransactionsCards(const TransactionsCards&);
    TransactionsCards() { return; }
    ~TransactionsCards(){return;}
    const QString& description() const {return _description;}
    void description(const QString& newDescription) {_description = newDescription; return; }
};

#endif
