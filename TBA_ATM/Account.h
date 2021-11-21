#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Company.h"
#include "AccountType.h"
#include "StringValidator.h"
#include "Currency.h"

#include <QString>

class Account{
private:
    QString _iban;
    QString _name;
    Company _company;
    AccountType _type;
    Currency _currency;
public:
    class BadAccount;
    Account (QString iban, QString name, Company company, AccountType type, Currency currency);
    Account(){ return; };
    Account (const Account&);
    ~Account() {};
    const QString& iban() const { return _iban; }
    void iban(const QString& newIban);
    const QString& name() const { return _name; }
    void name(const QString& newName);
    const Company& company() const { return _company; }
    void company(const Company& newCompany);
    const AccountType& type() const { return _type; }
    void type(const AccountType& accType);
    const Currency& currency() const { return _currency; }
    void currency(const Currency& newCurrency);
    QString display() const;
};

class Account::BadAccount{
private:
    const QString _reason;
public:
    BadAccount(QString reason = "") :
        _reason(reason){};
    ~BadAccount() {};
    QString diagnose() const { return _reason; };
};

#endif
