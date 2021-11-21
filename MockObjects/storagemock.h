#ifndef STORAGEMOCK_H
#define STORAGEMOCK_H
#include "IStorage.h"
#include "TransactionService.h"
#include <list>
#include <iterator>
#include <iostream>
using namespace std;
#include "MockObjects_global.h"

class DBUserMock{
private:
    QString _name;
    QString _passportNum;
    QString _surname;
public:
    DBUserMock(QString name, QString surname): _name(name), _surname(surname) { return; }
    DBUserMock(const User& user): _name(user.name()), _surname(user.surname()){ return; }
    DBUserMock() { return; }
    ~DBUserMock(){ return; }
    const QString& name() const { return _name; }
    const QString& surname() const { return _surname; }
    const QString& passportNum() const { return _passportNum; }
    void name(const QString& newName) { _name = newName; return; }
    void passportNum(const QString& newPasportNum ) { _passportNum = newPasportNum; return; }
    void surname(const QString& newSurname) { _surname = newSurname; return; }
};

class DBCardMock{
private:
    QString _cardNumber;
    QString _password;
    double _balance;
    DBUserMock _user;
    Currency _currency;
public:
    DBCardMock(QString newCardNumber, QString newPassword, double newBalance, User newUser, Currency newCurrency) :
    _cardNumber(newCardNumber), _password(newPassword), _balance(newBalance), _user(newUser), _currency(newCurrency){ return; }
    DBCardMock(const DBCardMock& card):
    _cardNumber(card.cardNumber()), _password(card.password()), _balance(card.balance()),
    _user(card.user()), _currency(card.currency()){ return; }
    DBCardMock(){ return; }
    ~DBCardMock(){ return; }
    const QString& cardNumber() const { return _cardNumber; }
    const double& balance() const { return _balance; }
    const DBUserMock& user() const { return _user; }
    const Currency& currency() const { return _currency; }
    const QString& password() const { return _password; }
    void cardNumber(const QString& newCardNumber) { _cardNumber = newCardNumber; return; }
    void balance(const double& newBalance) { _balance = newBalance; return; }
    void user(const User& newUser) { _user = newUser; return; }
    void currency(const Currency& newCurency) { _currency = newCurency; return; }
    void password(const QString& newPassword) { _password = newPassword; return; }
};


class StorageMock: public IStorage{
private:
    vector<DBCardMock> _storedCards;
    vector<Account> _storedAccs;
    vector<DBUserMock> _storedUsers;
    vector <ITransaction> _storedTransactions;
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
    StorageMock(const StorageMock&) = delete;
    const Account& getDBAccaunt(const QString&) const;
    const DBCardMock& getDBCard(const QString&) const;
    const DBUserMock& getDBUser(const QString&) const;
    void setAccaunt(const Account&);
    void setCard(const DBCardMock&);
    void setUser(const DBUserMock&);
public:
    int cardSize() const { return _storedCards.size(); }
    int accSize() const { return _storedAccs.size(); }
    int userSize() const { return _storedUsers.size(); }
    StorageMock(const vector<DBCardMock> cards, const vector<Account> accs,
                const vector<DBUserMock> users, const vector <ITransaction>& transactions);
    StorageMock(){ return; };
    ~StorageMock() { return; };
};

#endif // STORAGEMOCK_H
