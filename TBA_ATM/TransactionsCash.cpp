#include "TransactionCash.h"

TransactionCash::TransactionCash(double sum, QDate date): ITransaction(sum, date){
    if (sum <= 0)
        throw BadTransction("Sum must be grater than 0.");
    return;
}

string TransactionCash::doDisplay() const{
    string out = "";
    out += date().toString("ddMMyyyy").toStdString();
    out += "\nWithdraw " + to_string(sum());
    return out;
}
