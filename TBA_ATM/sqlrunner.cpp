#include "sqlrunner.h"

void SqlRunner::addTransactionCardAccount(const QString sum, const QString date,
                                          const QString desc, const QString card_num, const QString currency,
                                          const QString passport_num, const QString iban, const QString comp_id,
                                          const QString type, const QString acc_currency) {
    QSqlQuery query;
    QStringList scriptQueries = file_to_list("../sql/add_transaction_card_account.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":transaction_sum", sum.toDouble());
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

void SqlRunner::addTransactionCards(const QString sum, const QString date,
                                          const QString desc, const QString card1_num, const QString card1_currency,
                                          const QString card1_passport_num, const QString card2_num, const QString card2_currency,
                                    const QString card2_passport_num) {
    QSqlQuery query;
    QStringList scriptQueries = file_to_list("../sql/add_transaction_cards.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
             queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":transaction_sum", sum.toDouble());
            query.bindValue(":transaction_date", date);
            query.bindValue(":transaction_description", desc);
            query.bindValue(":card_card_from", card1_num.toInt());
            query.bindValue(":card_currency_from", card1_currency);
            query.bindValue(":card_user_passport_from", card1_passport_num);
            query.bindValue(":card_card_to", card2_num.toInt());
            query.bindValue(":card_currency_to", card2_currency);
            query.bindValue(":card_user_passport_to", card2_passport_num);
               if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
                 QString country = query.value(0).toString();
                 qDebug() << country;
             }
            query.finish();
    }
}


void SqlRunner::addTransactionCash(const QString sum, const QString date,
                                   const QString desc, const QString card_num, const QString card_currency,
                                   const QString card_passport_num) {
    QSqlQuery query;
    QStringList scriptQueries = file_to_list("../sql/add_transaction_cash.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
             queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
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
    QStringList scriptQueries = file_to_list("../sql/getAccount.sql");
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
                 curr = Currency(query.value(4).toString(), getCurrencyRate(query.value(4).toString()));
             }
            query.finish();
    }
    return Account(iban, name, comp, type, curr);
}

Account SqlRunner::getAccountByCompanyName(const QString title) {
    Account res;
    QString iban;
    QString name;
    Company comp;
    AccountType type;
    Currency curr;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("../sql/getAccount_by_company_name.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":title",title);
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
                 iban = query.value(0).toString();
                 name= query.value(1).toString();
                 comp = Company(query.value(2).toString(), "");
                 type = AccountType(query.value(3).toString(), "");
                 curr = Currency(query.value(4).toString(), getCurrencyRate(query.value(4).toString()));
             }
            query.finish();
    }
    return Account(iban, name, comp, type, curr);
}

QString SqlRunner::getAccountCompany_by_iban(const QString iban) {
    QString company_id;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("../sql/getAccountCompany_by_iban.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":iban",iban);
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
                 company_id = query.value(0).toString();
             }
            query.finish();
    }
    return company_id;
}





User SqlRunner::getUser(const QString passport_num) {
    QString name, surname;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("../sql/getUser.sql");
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

QString SqlRunner::getUserPassport_by_card(const QString card_num) {
    QString passport_num;
    QSqlQuery query;
    QStringList scriptQueries = file_to_list("../sql/getUserPassport_by_card.sql");
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
                 passport_num = query.value(0).toString();
             }
            query.finish();
    }
    return passport_num;
}


Card SqlRunner::getCard(const int card_num) {
    QString cardNumber;
    double balance;
    User user;
    Currency currency;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("../sql/isValidCard.sql");
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
               currency = Currency(query.value(4).toString(), getCurrencyRate(query.value(4).toString()));
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
    QStringList scriptQueries = file_to_list("../sql/isValidPin.sql");
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
               currency = Currency(query.value(4).toString(), getCurrencyRate(query.value(4).toString()));
               qDebug() << cardNumber << balance;
             }
            query.finish();
    }
    return Card(cardNumber, balance, user, currency);
}

bool SqlRunner::checkCard(const QString card_num, const QString pin) {
    QSqlQuery query;
    bool flag = false;

    QStringList scriptQueries = file_to_list("../sql/isValidPin.sql");
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



QMap<QString, QString> SqlRunner::getCharities() {
    QMap<QString,QString> res;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("../sql/select_charity_accounts.sql");
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
                res.insert(query.value(0).toString(),query.value(1).toString());

            }
            query.finish();
    }
    return res;
}


QVector<QString> SqlRunner::fullnameByCard(const QString card_num) {
    QVector<QString> res;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("../sql/select_fullname_by_card.sql");
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
    QStringList scriptQueries = file_to_list("../sql/select_transaction_cards.sql");
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
    QStringList scriptQueries = file_to_list("../sql/select_transaction_card_account.sql");
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
    QStringList scriptQueries = file_to_list("../sql/select_transaction_cash.sql");
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
    QStringList scriptQueries = file_to_list("../sql/change_password.sql");
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


void SqlRunner::increaseBalance_card(const QString balance, const QString card_num) {
    QSqlQuery query;
    QStringList scriptQueries = file_to_list("../sql/increaseBalance_card.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            qDebug() << queryTxt;
            query.prepare(queryTxt);
            query.bindValue(":balance", balance.toDouble());
            query.bindValue(":card_num", card_num.toInt());
            if (!query.exec())
                qFatal("Hello");
            query.finish();
    }
    return;
}

void SqlRunner::increaseBalance_account(const QString balance, const QString iban) {
    QSqlQuery query;
    QStringList scriptQueries = file_to_list("../sql/increaseBalance_account.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            qDebug() << queryTxt;
            query.prepare(queryTxt);
            query.bindValue(":balance", balance.toDouble());
            query.bindValue(":iban", iban);
            if (!query.exec())
                qFatal("Hello");
            query.finish();
    }
    return;
}

double SqlRunner::getCurrencyRate(const QString name){
    double rate;

    QSqlQuery query;
    QStringList scriptQueries = file_to_list("../sql/getCurrencyRate.sql");
    foreach (QString queryTxt, scriptQueries)
    {
            queryTxt = queryTxt.trimmed();
            if (queryTxt.isEmpty())
                continue;
            queryTxt.replace('\n', ' ');
            queryTxt.replace('\r', ' ');
            query.prepare(queryTxt);
            query.bindValue(":name", name);
            if (!query.exec())
                qFatal("Hello");
            while (query.next()) {
               rate = query.value(0).toDouble();
             }
            query.finish();
    }
    return rate;
}



const QStringList SqlRunner::file_to_list(const QString script_path) {
   QFile script(script_path);
   QStringList scriptQueries;
   if (script.open(QIODevice::ReadOnly)) {
       scriptQueries = QTextStream(&script).readAll().split(';');
   }
   return scriptQueries;
}
