#ifndef STORAGE_H
#define STORAGE_H
#include "IStorage.h"
#include "Cryptor.h"

class Storage: public IStorage{
private:
    ICryptor* _cryptor;
    virtual void doAddTransactionCardAccount(const TransactionsCardAccount&, const Card&, const Account&) override;
    virtual void doAddTransactionCash(const TransactionCash&, const Card&) override;
    virtual void doAddTransactionCards(const TransactionsCards&, const Card&, const Card&) override;
    virtual bool doCheckAuthCard(const AuthCard&) const override;
    virtual Card doGetCard(const QString&) const override;
    virtual User doGetUser(const QString&) const override;
    virtual Account doGetAccount(const QString&) const override;
    virtual QMap<QString, QString> doGetAllCharitiyTitles() const override;
    virtual void doChangePassword(const Card& card,const QString& pin) override;
public:
    Storage(ICryptor* ct): _cryptor(ct)
    {   return; }
    ~Storage(){ return; }
};

#endif
