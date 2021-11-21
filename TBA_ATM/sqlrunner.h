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
#include <QVector>
#include <AuthCard.h>

using namespace std;

class SqlRunner
{
public:
    SqlRunner() {}
    ~SqlRunner(){}
    const QStringList file_to_list(const QString script_path);
    void addTransactionCardAccount(const QString id, const QString sum,
                                   const QString date, const QString desc,
                                   const QString card_num, const QString currency,
                                   const QString passport_num, const QString iban,
                                   const QString comp_id, const QString type,
                                   const QString acc_currency);
    Card getCard(const int card_num);
    User getUser(const QString passport_num);
    Account getAccount(const QString acc_name);
    QVector<QString> getCharities();
    bool checkCard(const QString card_num, QString pin);
};

#endif // SQLRUNNER_H
