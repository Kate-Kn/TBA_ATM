#include "Storage.h"
#include "sqlrunner.h"

void Storage::doAddTransactionCardAccount(const TransactionsCardAccount&, const Card&, const Account&) {
    SqlRunner runner;
}
void Storage::doAddTransactionCash(const TransactionCash&, const Card&) {
    SqlRunner runner;
}
void Storage::doAddTransactionCards(const TransactionsCards&, const Card&, const Card&) {
    SqlRunner runner;
}
bool Storage::doCheckAuthCard(const AuthCard& card) const{
    SqlRunner runner;
    return runner.checkCard(card.cardNumber(), card.pincode());
}
Card Storage::doGetCard(const QString& card_num) const{
    SqlRunner runner;
    return runner.getCard(card_num.toInt());
}
User Storage::doGetUser(const QString& passport_num) const{
    SqlRunner runner;
    return runner.getUser(passport_num);
}
Account Storage::doGetAccount(const QString& acc_name) const{
    SqlRunner runner;
    return runner.getAccount(acc_name);;
}
QVector<QString> Storage::doGetTransactionsList(const Card&) const{
    QVector<QString> res;
    return res;
}
QVector<QString> Storage::doGetAllCharitiyTitles() const{
    SqlRunner runner;
    return runner.getCharities();
}

void Storage::doChangePassword(const Card& card,const QString& pin)
{
    return;
}
