#ifndef STORAGE_H
#define STORAGE_H
#include "IStorage.h"

class Storage: public IStorage{
private:
    virtual void doAddTransactionCardAccount(const TransactionsCardAccount&, const Card&, const Account&) const override;
    virtual void doAddTransactionCash(const TransactionCash&, const Card&) const override;
    virtual void doAddTransactionCards(const TransactionsCards&, const Card&, const Card&) const override;
    virtual Card doCheckAuthCard(const AuthCard&) const override;
    virtual Card doGetCard(const string&) const override;
    virtual User doGetUser(const string&) const override;
    virtual Account doGetAccount(const string&) const override;
    virtual QString* doGetTransactionsList(const Card&) const override;
    virtual QString* doGetAllCharitiyTitles() const override;
    virtual QString* doGetAllTitles(const string&) const override;
public:
    Storage(){ return; }
    ~Storage(){ return; }
};

#endif
