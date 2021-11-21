#include "TransactionCash.h"

TransactionCash::TransactionCash(double newSum, QDate newDate): ITransaction(newSum, newDate){
    if (sum() <= 0)
        throw BadTransction("Sum must be grater than 0.");
    return;
}


TransactionCash::TransactionCash(const TransactionCash& transaction): ITransaction(transaction.sum(), transaction.date()){
    return;
}

QString TransactionCash::doDisplay() const{
    QString out = "";
    out.append(date().toString("ddMMyyyy"));
    out.append('\n' + QString::number(sum()));
    return out;
}

