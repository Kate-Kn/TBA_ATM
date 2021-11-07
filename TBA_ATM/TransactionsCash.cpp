#include "TransactionCash.h"

TransactionCash::TransactionCash(double newSum, QDate newDate): ITransaction(newSum, newDate){
    if (sum() <= 0)
        throw BadTransction("Sum must be grater than 0.");
    return;
}


TransactionCash::TransactionCash(const TransactionCash& transaction): ITransaction(transaction.sum(), transaction.date()){
    return;
}

string TransactionCash::doDisplay() const{
    string out = "";
    out += date().toString("ddMMyyyy").toStdString();
    out += "\nWithdraw " + to_string(sum());
    return out;
}

