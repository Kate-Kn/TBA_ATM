#ifndef ACCOUNTTYPE_H
#define ACCOUNTTYPE_H

#include <QString>

using namespace std;

class AccountType{
private:
    QString _description;
    QString _name;
public:
    AccountType(QString name, QString description): _description(description), _name(name) { return; }
    AccountType() { return; }
    AccountType(const AccountType& accT): _description(accT.description()), _name(accT.name()) { return; }
    ~AccountType() { return; }
    const QString& description() const { return _description; }
    const QString& name() const { return _name; }
    void description(const QString& newDescription) { _description = newDescription; return; }
};

#endif
