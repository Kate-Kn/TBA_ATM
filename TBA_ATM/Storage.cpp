#include "Storage.h"
#include "sqlrunner.h"

void Storage::doAddTransactionCardAccount(const TransactionsCardAccount& transaction, const Card& card, const Account& account) {
    SqlRunner runner;

    runner.increaseBalance_card(QString::number(-transaction.sum()*card.currency().rateUAH()), card.cardNumber());
    runner.increaseBalance_account(QString::number(transaction.sum()*account.currency().rateUAH()), account.iban());
    return runner.addTransactionCardAccount(QString::number(transaction.sum()),transaction.date().toString("dd.MM.yyyy"),transaction.description(), card.cardNumber(),card.currency().name(), runner.getUserPassport_by_card(card.cardNumber()),
                                            account.iban(),runner.getAccountCompany_by_iban(account.iban()),account.type().name(),account.currency().name() );
}

void Storage::doAddTransactionCash(const TransactionCash& transaction, const Card& card) {
    SqlRunner runner;
    runner.increaseBalance_card(QString::number(-transaction.sum()*card.currency().rateUAH()), card.cardNumber());
    return runner.addTransactionCash(QString::number(transaction.sum()),transaction.date().toString("dd.MM.yyyy"), "", card.cardNumber(),card.currency().name(), runner.getUserPassport_by_card(card.cardNumber()));
}

void Storage::doAddTransactionCards(const TransactionsCards& transaction, const Card& card1, const Card& card2) {
    SqlRunner runner;
    runner.increaseBalance_card(QString::number(-transaction.sum()*card1.currency().rateUAH()), card1.cardNumber());
    runner.increaseBalance_card(QString::number( transaction.sum()*card2.currency().rateUAH()), card2.cardNumber());
    return runner.addTransactionCards(QString::number(transaction.sum()),transaction.date().toString("dd.MM.yyyy"),transaction.description(), card1.cardNumber(),card1.currency().name(), runner.getUserPassport_by_card(card1.cardNumber()),
                                            card2.cardNumber(),card2.currency().name(), runner.getUserPassport_by_card(card2.cardNumber()));
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
    return runner.getAccount(acc_name);
}

QMap<QString, QString> Storage::doGetAllCharitiyTitles() const{
    SqlRunner runner;
    return runner.getCharities();
}

void Storage::doChangePassword(const Card& card,const QString& pin)
{
    SqlRunner runner;
    return runner.changePassword(card.cardNumber(), _cryptor->cryptPassword(pin));
}



