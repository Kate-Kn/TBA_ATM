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
            query.bindValue(":id", id.toInt());
            query.bindValue(":sum", sum.toDouble());
            query.bindValue(":transaction_date", date);
            query.bindValue(":transaction_description", desc);
            query.bindValue(":card_card_num", card_num.toInt());
            query.bindValue(":card_currency_name", currency);
            query.bindValue(":card_user_passport_num", passport_num);
            query.bindValue(":account_iban", iban);
            query.bindValue(":account_company_id", comp_id.toInt());
            query.bindValue(":account_account_type_code", type.toInt());
            query.bindValue(":account_currency_name", acc_currency);
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
                 QString country = query.value(0).toString();
                 qDebug() << country;
             }
            query.finish();
    }
}

void SqlRunner::addTransactionCards(const QString id, const QString sum, const QString date,
                                          const QString desc, const QString card1_num, const QString card1_currency,
                                          const QString card1_passport_num, const QString card2_num, const QString card2_currency,
                                    const QString card2_passport_num) {
    QSqlQuery query;
    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/add_transaction_cards.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            query.prepare(queryTxt);
            query.bindValue(":id", id.toInt());
            query.bindValue(":transaction_sum", sum.toDouble());
            query.bindValue(":transaction_date", date);
            query.bindValue(":transaction_description", desc);
            query.bindValue(":card1_card_num", card1_num.toInt());
            query.bindValue(":card1_currency_name", card1_currency);
            query.bindValue(":card1_user_passport_num", card1_passport_num);
            query.bindValue(":card2_card_num", card2_num.toInt());
            query.bindValue(":card2_currency_name", card2_currency);
            query.bindValue(":card2_user_passport_num", card2_passport_num);
               if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
                 QString country = query.value(0).toString();
                 qDebug() << country;
             }
            query.finish();
    }
}


void SqlRunner::addTransactionCash(const QString id, const QString sum, const QString date,
                                   const QString desc, const QString card_num, const QString card_currency,
                                   const QString card_passport_num) {
    QSqlQuery query;
    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/add_transaction_cash.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            query.prepare(queryTxt);
            query.bindValue(":id", id.toInt());
            query.bindValue(":transaction_sum", sum.toDouble());
            query.bindValue(":transaction_date", date);
            query.bindValue(":transaction_description", desc);
            query.bindValue(":card_card_num", card_num.toInt());
            query.bindValue(":card_currency_name", card_currency);
            query.bindValue(":card_user_passport_num", card_passport_num);

               if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
                 QString country = query.value(0).toString();
                 qDebug() << country;
             }
            query.finish();
    }
}


Account SqlRunner::getAccount(const QString iban) {
    Account res;
    QString name;
    Company comp;
    AccountType type;
    Currency curr;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/getAccount.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":iban", iban);
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
                 name = query.value(1).toString();
                 comp = Company(query.value(2).toString(), "");
                 type = AccountType(query.value(3).toString(), "");
                 curr = Currency(query.value(4).toString(), 0.1);
             }
            query.finish();
    }
    return Account(iban, name, comp, type, curr);
}

Account SqlRunner::getAccountByName(const QString name) {
    Account res;
    QString iban;
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
            query.bindValue(":acc_name", name);
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
                 iban = query.value(0).toString();
                 comp = Company(query.value(2).toString(), "");
                 type = AccountType(query.value(3).toString(), "");
                 curr = Currency(query.value(4).toString(), 0.1);
             }
            query.finish();
    }
    return Account(iban, name, comp, type, curr);
}


User SqlRunner::getUser(const QString passport_num) {
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


Card SqlRunner::getCard(const int card_num) {
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

Card SqlRunner::pinValidaton(const int card_num, const QString pin) {
    QString cardNumber;
    double balance;
    User user;
    Currency currency;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/isValidPin.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":card_num", card_num);
            query.bindValue(":pincode", pin);
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

bool SqlRunner::checkCard(const QString card_num, const QString pin) {
    QSqlQuery query;
    bool flag = false;

    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/isValidPin.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":card_num", card_num.toInt());
            query.bindValue(":pincode", pin.toInt());
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
               return true;
            }
            query.finish();
    }
    return flag;
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
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
               res.append(query.value(0).toString());
            }
            query.finish();
    }
    return res;
}


QVector<QString> SqlRunner::fullnameByCard(const QString card_num) {
    QVector<QString> res;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/select_fullname_by_card.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":card_num", card_num.toInt());
            if (!query.exec())
                qFatal("Hello");
            res.append(query.value(0).toString());
            res.append(query.value(1).toString());
            query.finish();
    }
    return res;
}


QVector<TransactionsCards> SqlRunner::selectTransactionCards(const QString card_from_num, const QString card_to_num) {
    QVector<TransactionsCards> res;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/select_transaction_cards.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":card_card_from", card_from_num.toInt());
            query.bindValue(":card_card_to", card_to_num.toInt());
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
                TransactionsCards transaction = TransactionsCards(query.value(1).toDouble(), query.value(2).toDate(), query.value(3).toString());
                res.append(transaction);
            }
            query.finish();
    }
    return res;
}


QVector<TransactionsCardAccount> SqlRunner::selectTransactionsCardAccount(const QString card_num) {
    QVector<TransactionsCardAccount> res;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/select_transaction_card_account.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":card_card_num", card_num.toInt());
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
                TransactionsCardAccount transaction = TransactionsCardAccount(query.value(1).toDouble(), query.value(2).toDate(), query.value(3).toString());
                res.append(transaction);
            }
            query.finish();
    }
    return res;
}


QVector<TransactionCash> SqlRunner::selectTransactionCash(const QString card_num) {
    QVector<TransactionCash> res;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/select_transaction_cash.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":card_card_num", card_num.toInt());
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
                TransactionCash transaction = TransactionCash(query.value(1).toDouble(), query.value(2).toDate());
                res.append(transaction);
            }
            query.finish();
    }
    return res;
}


void SqlRunner::changePassword(const QString card_num, const QString pin) {
    QSqlQuery query;
    QStringList scriptQueries = file_to_list("C:/Users/aanos/TBA_ATM/sql/change_password.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            qDebug() << queryTxt;
            query.prepare(queryTxt);
            query.bindValue(":card_num", card_num.toInt());
            query.bindValue(":pincode", pin.toInt());
            if (!query.exec())
                qFatal("Hello");
            query.finish();
    }
    return;
}


const QStringList SqlRunner::file_to_list(const QString script_path) {
   QFile script(script_path);
   QStringList scriptQueries;
   if (script.open(QIODevice::ReadOnly)) {
       scriptQueries = QTextStream(&script).readAll().split(';');
   }
   return scriptQueries;
}
