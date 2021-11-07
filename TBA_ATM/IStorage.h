#ifndef ISTORAGE_H
#define ISTORAGE_H
#include "TransactionsCardAccount.h"
#include "TransactionCash.h"
#include "TransactionsCards.h"
#include "Card.h"
#include "Account.h"
#include "AuthCard.h"
#include "User.h"

class IStorage{
private:
    virtual void doAddTransactionCardAccount(const TransactionsCardAccount&, const Card&, const Account&) const { return; };
    virtual void doAddTransactionCash(const TransactionCash&, const Card&) const { return; }
    virtual void doAddTransactionCards(const TransactionsCards&, const Card&, const Card&) const { return; }
    virtual Card doCheckAuthCard(const AuthCard&) const { return Card("", 0.00, User("", ""));; }
    virtual Card doGetCard(const string&) const { return  Card("", 0.00, User("", "")); }
    virtual User doGetUser(const string&) const { return User("", ""); }
    virtual Account doGetAccount(const string&) const { return Account("", "", Company("", ""), AccountType("")); }
    virtual QString* doGetTransactionsList(const Card&) const {
        QString* res = new QString[1];
        return res;}
    virtual QString* doGetAllCharitiyTitles() const{
        QString* res = new QString[1];
        return res;}
    virtual QString* doGetAllTitles(const string&) const{
        QString* res = new QString[1];
        return res;}
public:
    class BadStorage;
    IStorage(){ return; }
    virtual ~IStorage() { return; }
    void addTransactionCardAccount(const TransactionsCardAccount& transaction, const Card& card, const Account& account) const{
        doAddTransactionCardAccount(transaction, card, account); }
    void addTransactionCash(const TransactionCash& transaction, const Card& card) const{
        doAddTransactionCash(transaction, card); }
    void addTransactionCards(const TransactionsCards& transaction, const Card& firstCard, const Card& secondCard) const{
        doAddTransactionCards(transaction, firstCard, secondCard); }
    Card checkAuthCard(const AuthCard& authCard) const{
        return doCheckAuthCard(authCard); }
    Card getCard(const string& cardNum) const{
        return doGetCard(cardNum);}
    User getUser(const string& passportNum) const{
        return doGetUser(passportNum); }
    Account getAccount(const string& iban) const{
        return doGetAccount(iban); }
    QString* getTransactionsList(const Card& card) const{
        return doGetTransactionsList(card);}
    QString* getAllCharitiyTitles() { return doGetAllCharitiyTitles(); }
    QString* getAllTitles(const string& type) {return doGetAllTitles(type);}
};

class IStorage::BadStorage{
private:
    const string _reason;
public:
    BadStorage(string reason = "") :
        _reason(reason){};
    ~BadStorage() {};
    string diagnose() const { return _reason; };
};

#endif
