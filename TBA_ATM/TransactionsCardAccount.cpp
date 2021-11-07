#include "TransactionsCardAccount.h"

TransactionsCardAccount::TransactionsCardAccount(double sum, QDate date, string description):
ITransaction(sum, date), _description(description){
    if (sum <= 0)
        throw BadTransction("Sum must be grater than 0.");
    return;
}

string TransactionsCardAccount::doDisplay() const{
    string out = "";
    out += date().toString("ddMMyyyy").toStdString();
    out += '\n' + description();
    out += '\n' + to_string(sum());
    return out;
}
