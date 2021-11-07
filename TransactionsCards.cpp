#include "TransactionsCards.h"

TransactionsCards::TransactionsCards(double sum, QDate date, string description):
ITransaction(sum, date), _description(description){
    if (sum <= 0)
        throw BadTransction("Sum must be grater than 0.");
    return;
}

string TransactionsCards::doDisplay() const{
    string out = "";
    out += date().toString("ddMMyyyy").toStdString();
    out += '\n' + description();
    out += '\n' + to_string(sum());
    return out;
}