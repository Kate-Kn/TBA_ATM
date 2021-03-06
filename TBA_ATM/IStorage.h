#ifndef ISTORAGE_H
#define ISTORAGE_H
#include "TransactionsCardAccount.h"
#include "TransactionCash.h"
#include "TransactionsCards.h"
#include "Card.h"
#include "Account.h"
#include "AuthCard.h"
#include "User.h"
#include <QMap>

class IStorage{
private:
    virtual void doAddTransactionCardAccount(const TransactionsCardAccount&, const Card&, const Account&) = 0;
    virtual void doAddTransactionCash(const TransactionCash&, const Card&) = 0;
    virtual void doAddTransactionCards(const TransactionsCards&, const Card&, const Card&) = 0;
    virtual bool doCheckAuthCard(const AuthCard&) const = 0;
    virtual Card doGetCard(const QString&) const = 0;
    virtual User doGetUser(const QString&) const = 0;
    virtual Account doGetAccount(const QString&) const = 0;
    virtual QMap<QString, QString> doGetAllCharitiyTitles() const = 0;
    virtual void doChangePassword(const Card& card, const QString& pin) =0;
public:
    class BadStorage;
    IStorage(){ return; }
    virtual ~IStorage() { return; }
    void addTransactionCardAccount(const TransactionsCardAccount& transaction, const Card& card, const Account& account) {
        doAddTransactionCardAccount(transaction, card, account); }
    void addTransactionCash(const TransactionCash& transaction, const Card& card) {
        doAddTransactionCash(transaction, card); }
    void addTransactionCards(const TransactionsCards& transaction, const Card& firstCard, const Card& secondCard) {
        doAddTransactionCards(transaction, firstCard, secondCard); }
    bool checkAuthCard(const AuthCard& authCard) const{
        return doCheckAuthCard(authCard); }
    Card getCard(const QString& cardNum) const{
        return doGetCard(cardNum);}
    User getUser(const QString& passportNum) const{
        return doGetUser(passportNum); }

    Account getAccount(const QString& iban) const{
        return doGetAccount(iban); }
    QMap<QString, QString> getAllCharitiyTitles() const { return doGetAllCharitiyTitles(); }
    void changePassword(const Card& card, const QString& pin)
    {
        doChangePassword(card, pin);
    }
};

class IStorage::BadStorage{
private:
    const QString _reason;
public:
    BadStorage(QString reason = "") :
        _reason(reason){};
    ~BadStorage() {};
    QString diagnose() const { return _reason; };
};

#endif
