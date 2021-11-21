#include "Account.h"

Account::Account (string newIban, string newName, Company newCompany, AccountType newType):
_iban(newIban), _name(newName), _company(newCompany), _type(newType)
{
    if(isNumericalSequence(iban()))
        throw BadAccount("Iban must consist of numbers.");
    if(iban().length() != 4)
        throw BadAccount("Iban must consist of 4 numbers.");
    return;
}

Account::Account (const Account& acc):
_iban(acc.iban()), _name(acc.name()), _company(acc.company()), _type(acc.type())
{
    return;
}

string Account::display() const
{
    string out = "";
    out += iban();
    out += '\n' + name();
    out += '\n' + company().title() + '\n' + company().description();
    return out;
}
