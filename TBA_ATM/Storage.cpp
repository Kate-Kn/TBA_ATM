#include "Storage.h"

void Storage::doAddTransactionCardAccount(const TransactionsCardAccount&, const Card&, const Account&) {

}
void Storage::doAddTransactionCash(const TransactionCash&, const Card&) {

}
void Storage::doAddTransactionCards(const TransactionsCards&, const Card&, const Card&) {

}
bool Storage::doCheckAuthCard(const AuthCard&) const{
    return false;
}
Card Storage::doGetCard(const QString&) const{
    return  Card("1234", 0.00, User("", ""), Currency("", 0.1));
}
User Storage::doGetUser(const QString&) const{
    return User("", "");
}
Account Storage::doGetAccount(const QString&) const{
    return Account("1234", "", Company("", ""), AccountType("1234", ""), Currency("", 0.1));
}
vector<QString> Storage::doGetTransactionsList(const Card&) const{
    vector<QString> res;
    return res;
}
vector<QString> Storage::doGetAllCharitiyTitles() const{
    vector<QString> res;
    return res;
}
vector<QString> Storage::doGetAllTitles(const QString&) const{
    vector<QString> res;
    return res;
}
void Storage::doChangePassword(const Card& card,const QString& pin)
{
    return;
}
