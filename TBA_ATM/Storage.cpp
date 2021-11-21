#include "Storage.h"
#include <QSqlQuery>

void Storage::doAddTransactionCardAccount(const TransactionsCardAccount&, const Card&, const Account&) const{

}
void Storage::doAddTransactionCash(const TransactionCash&, const Card&) const{

}
void Storage::doAddTransactionCards(const TransactionsCards&, const Card&, const Card&) const{

}
Card Storage::doCheckAuthCard(const AuthCard&) const{
    return Card("", 0.00, User("", ""));
}
Card Storage::doGetCard(const string&) const{
    return  Card("", 0.00, User("", ""));
}
User Storage::doGetUser(const string&) const{
    return User("", "");
}
Account Storage::doGetAccount(const string&) const{
    return Account("", "", Company("", ""), AccountType(""));
}
QString* Storage::doGetTransactionsList(const Card&) const{
    QString* res = new QString[1];
    return res;
}
QString* Storage::doGetAllCharitiyTitles() const{
    QString* res = new QString[1];
    return res;
}
QString* Storage::doGetAllTitles(const string&) const{
    QString* res = new QString[1];
    return res;
}
