#include "Storage.h"
#include "sqlrunner.h"

void Storage::doAddTransactionCardAccount(const TransactionsCardAccount& transaction, const Card& card, const Account& account) {
    SqlRunner runner;
    return runner.addTransactionCardAccount(0,QString::number(transaction.sum()),transaction.date().toString(),transaction.description(), card.cardNumber(),card.currency().name(),card.user().surname(),
                                            account.iban(),account.company().title(),account.type().name(),account.currency().name() );
}//id transaction, card.user, account.company
void Storage::doAddTransactionCash(const TransactionCash& transaction, const Card& card) {
    SqlRunner runner;
    return runner.addTransactionCash(0,QString::number(transaction.sum()),transaction.date().toString(), "", card.cardNumber(),card.currency().name(),card.user().surname());
}//id transaction, card.user, account.company

void Storage::doAddTransactionCards(const TransactionsCards& transaction, const Card& card1, const Card& card2) {
    SqlRunner runner;
    return runner.addTransactionCards(0,QString::number(transaction.sum()),transaction.date().toString(),transaction.description(), card1.cardNumber(),card1.currency().name(),card1.user().surname(),
                                            card2.cardNumber(),card2.currency().name(),card2.user().surname());
}//id transaction, card1.user, card2.user

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
    return runner.getAccountByName(acc_name);
}

QVector<QString> Storage::doGetAllCharitiyTitles() const{
    SqlRunner runner;
    return runner.getCharities();
}

void Storage::doChangePassword(const Card& card,const QString& pin)
{
    SqlRunner runner;
    return runner.changePassword(card.cardNumber(), _cryptor->cryptPassword(pin));
}



