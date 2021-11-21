#ifndef USER_H
#define USER_H

#include <QString>

using namespace std;

class User{
private:
    QString _name;
    QString _surname;
public:
    User(QString name, QString surname): _name(name), _surname(surname) { return; }
    User(const User& user): _name(user.name()), _surname(user.surname()){ return; }
    User() { return; }
    ~User(){ return; }
    const QString& name() const { return _name; }
    const QString& surname() const { return _surname; }
    void name(const QString& newName) { _name = newName; return; }
    void surname(const QString& newSurname) { _surname = newSurname; return; }
};

#endif
