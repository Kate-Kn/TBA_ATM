#include "sqlrunner.h"

void SqlRunner::addTransactionCardAccount(const QString id, const QString sum, const QString date,
                                          const QString desc, const QString card_num, const QString currency,
                                          const QString passport_num, const QString iban, const QString comp_id,
                                          const QString type, const QString acc_currency) {
    QSqlQuery query;
    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/add_transaction_card_account.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            query.prepare(queryTxt);
            query.bindValue(":id", 1);
            query.bindValue(":sum", 2.5);
            query.bindValue(":transaction_date", "1234");
            query.bindValue(":transaction_description", "test");
            query.bindValue(":card_card_num", 1234567);
            query.bindValue(":card_currency_name", "hrivna");
            query.bindValue(":card_user_passport_num", "123456");
            query.bindValue(":account_iban", "12345");
            query.bindValue(":account_company_id", 123);
            query.bindValue(":account_account_type_code", 123);
            query.bindValue(":account_currency_name", "Hrivna");
            qDebug() << queryTxt;
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
                 QString country = query.value(0).toString();
                 qDebug() << country;
             }
            query.finish();
    }
}

Card SqlRunner::getCard(const int card_num) {
    Card res;
    QString cardNumber;
    double balance;
    User user;
    Currency currency;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/isValidCard.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":card_num", card_num);
            qDebug() << queryTxt;
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
               cardNumber = query.value(0).toString();
               balance = query.value(3).toDouble();
               user = getUser(query.value(5).toString());
               currency = Currency(query.value(4).toString(), 0.1);
               qDebug() << cardNumber << balance;
             }
            query.finish();
    }
    return Card(cardNumber, balance, user, currency);
}

User SqlRunner::getUser(const QString passport_num) {
    User res;
    QString name, surname;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/getUser.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":passport_num", passport_num);
            qDebug() << queryTxt;
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
                 name = query.value(0).toString();
                 surname = query.value(1).toString();
             }
            query.finish();
    }
    return User(name, surname);
}

Account SqlRunner::getAccount(const QString acc_name) {
    Account res;
    QString iban, name;
    Company comp;
    AccountType type;
    Currency curr;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/getAccount_by_name.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":passport_num", acc_name);
            qDebug() << queryTxt;
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
                 iban = query.value(0).toString();
                 name = query.value(1).toString();
                 comp = Company(query.value(2).toString(), "");
                 type = AccountType(query.value(3).toString(), "");
                 curr = Currency(query.value(4).toString(), 0.1);
             }
            query.finish();
    }
    return Account(iban, name, comp, type, curr);
}

QVector<QString> SqlRunner::getCharities() {
    QVector<QString> res;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/select_charity_accounts.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            qDebug() << queryTxt;
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
               res.append(query.value(0).toString());
            }
            query.finish();
    }
    return res;
}

bool SqlRunner::checkCard(const QString card_num, const QString pin) {
    QSqlQuery query;
    bool flag = false;

    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/select_charity_accounts.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":card_num", card_num);
            query.bindValue(":pin", pin);
            qDebug() << queryTxt;
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
               return true;
            }
            query.finish();
    }
    return flag;
}

const QStringList SqlRunner::file_to_list(const QString script_path) {
   QFile script(script_path);
   QStringList scriptQueries;
   if (script.open(QIODevice::ReadOnly)) {
       scriptQueries = QTextStream(&script).readAll().split(';');
   }
   return scriptQueries;
}
