#include "Account.h"

Account::Account (string iban, string name, Company company, AccountType type):
_iban(iban), _name(name), _company(company), _type(type)
{
    if(isNumericalSequence(iban))
        throw BadAccount("Iban must consist of numbers.");
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
