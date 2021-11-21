#include "TransactionsCardAccount.h"

TransactionsCardAccount::TransactionsCardAccount(double sum, QDate date, QString description):
ITransaction(sum, date), _description(description){
    if (sum <= 0.0)
        throw BadTransction("Sum must be grater than 0.");
    return;
}

TransactionsCardAccount::TransactionsCardAccount(const TransactionsCardAccount& transaction):
    ITransaction(transaction.sum(), transaction.date()), _description(transaction.description()){
    return;
}


QString TransactionsCardAccount::doDisplay() const{
    QString out = "";
    out.append(date().toString("ddMMyyyy"));
    out.append('\n' + description());
    out.append('\n' + QString::number(sum()));
    return out;
}
