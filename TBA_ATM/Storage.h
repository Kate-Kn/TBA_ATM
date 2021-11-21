#ifndef STORAGE_H
#define STORAGE_H
#include "IStorage.h"

class Storage: public IStorage{
private:
    virtual void doAddTransactionCardAccount(const TransactionsCardAccount&, const Card&, const Account&) override;
    virtual void doAddTransactionCash(const TransactionCash&, const Card&) override;
    virtual void doAddTransactionCards(const TransactionsCards&, const Card&, const Card&) override;
    virtual bool doCheckAuthCard(const AuthCard&) const override;
    virtual Card doGetCard(const QString&) const override;
    virtual User doGetUser(const QString&) const override;
    virtual Account doGetAccount(const QString&) const override;
    virtual vector<QString> doGetTransactionsList(const Card&) const override;
    virtual vector<QString> doGetAllCharitiyTitles() const override;
    virtual vector<QString> doGetAllTitles(const QString&) const override;
public:
    Storage(){ return; }
    ~Storage(){ return; }
};

#endif
