#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Company.h"
#include "AccountType.h"
#include "StringValidator.h"

class Account{
private:
    string _iban;
    string _name;
    Company _company;
    AccountType _type;
public:
    class BadAccount;
    Account (string iban, string name, Company company, AccountType type);
    ~Account() {};
    string iban() const { return _iban; }
    string name() const { return _name; }
    Company company() const { return _company; }
    AccountType type() const { return _type; }
    string display() const;
};

class Account::BadAccount{
private:
    const string _reason;
public:
    BadAccount(string reason = "") :
        _reason(reason){};
    ~BadAccount() {};
    string diagnose() const { return _reason; };
};

#endif
