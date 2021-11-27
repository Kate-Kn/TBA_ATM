#ifndef SQLRUNNER_H
#define SQLRUNNER_H
#include <QSqlQuery>
#include <QFile>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <QString>
#include "User.h"
#include "Card.h"
#include "Account.h"
#include "Company.h"
#include "Currency.h"
#include "AccountType.h"
#include "TransactionCash.h"
#include "TransactionsCards.h"
#include "TransactionsCardAccount.h"

#include <QVector>
#include <AuthCard.h>

using namespace std;

class SqlRunner
{
public:
    SqlRunner() {}
    ~SqlRunner(){}
    const QStringList file_to_list(const QString script_path);
    void addTransactionCardAccount(const QString sum,
                                   const QString date, const QString desc,
                                   const QString card_num, const QString currency,
                                   const QString passport_num, const QString iban,
                                   const QString comp_id, const QString type,
                                   const QString acc_currency);
    void addTransactionCards      (const QString sum, const QString date,
                                   const QString desc, const QString card1_num, const QString card1_currency,
                                   const QString card1_passport_num, const QString card2_num, const QString card2_currency,
                                   const QString card2_passport_num);
    void addTransactionCash       (const QString sum, const QString date,
                                   const QString desc, const QString card_num, const QString card_currency,
                                   const QString card_passport_num);

    Account getAccount(const QString iban);
    Account getAccountByCompanyName(const QString acc_name);
    QString getAccountCompany_by_iban(const QString iban);

    User getUser(const QString passport_num);
    QString getUserPassport_by_card(const QString card_num);

    bool checkCard(const QString card_num, QString pin);
    Card getCard(const int card_num);
    Card pinValidaton(const int card_num, const QString pin);

    QVector<QString> getCharities();
    QVector<QString> fullnameByCard(const QString card_num);

    void increaseBalance_card(const QString balance, const QString card_num);
    void increaseBalance_account(const QString balance, const QString iban);


    QVector<TransactionCash> selectTransactionCash(const QString card_num);
    QVector<TransactionsCards> selectTransactionCards(const QString card_from_num, const QString card_to_num);
    QVector<TransactionsCardAccount> selectTransactionsCardAccount(const QString card_num);

    void changePassword(const QString card_num, const QString pin);
};

#endif // SQLRUNNER_H
