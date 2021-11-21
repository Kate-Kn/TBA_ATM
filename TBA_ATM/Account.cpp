#include "Account.h"

Account::Account (QString newIban, QString newName, Company newCompany, AccountType newType, Currency newCurrency):
_iban(newIban), _name(newName), _company(newCompany), _type(newType), _currency(newCurrency)
{
    if(!isNumericalSequence(iban()))
        throw BadAccount("Iban must consist of numbers.");
    if(iban().length() != 4)
        throw BadAccount("Iban must consist of 4 numbers.");
    return;
}

Account::Account (const Account& acc):
_iban(acc.iban()), _name(acc.name()), _company(acc.company()), _type(acc.type()), _currency(acc.currency())
{
    return;
}

void Account::iban(const QString& newIban){
    if(!isNumericalSequence(newIban))
        throw BadAccount("Iban must consist of numbers.");
    if(newIban.length() != 4)
        throw BadAccount("Iban must consist of 4 numbers.");
    _iban = newIban;
    return;
}

void Account::name(const QString& newName){
    _name = newName;
    return;
}

void Account::company(const Company& newCompany){
    _company = newCompany;
    return;
}

void Account::type(const AccountType& accType){
    _type = accType;
    return;
}

void Account::currency(const Currency& newCurrency){
    _currency = newCurrency;
    return;
}


QString Account::display() const
{
    QString out = "";
    out += iban();
    out += '\n' + name();
    out += '\n' + company().title() + '\n' + company().description();
    return out;
}
