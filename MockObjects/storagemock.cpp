#include "storagemock.h"

StorageMock::StorageMock(const vector<DBCardMock> cards, const vector<Account> accs,
                         const vector<DBUserMock> users, const vector <ITransaction>& transactions):
 _storedCards(cards), _storedAccs(accs), _storedUsers(users), _storedTransactions(transactions)
{
    return;
}

void StorageMock::doAddTransactionCardAccount(const TransactionsCardAccount& transaction, const Card& card, const Account&){
   DBCardMock tempCard = getDBCard(card.cardNumber());
   double newBalance = tempCard.balance() - transaction.sum()*tempCard.currency().rateUAH();
   tempCard.balance(newBalance);
   setCard(tempCard);
   _storedTransactions.push_back(transaction);
}

void StorageMock::doAddTransactionCash(const TransactionCash& transaction, const Card& card) {
    DBCardMock tempCard = getDBCard(card.cardNumber());
    double newBalance = tempCard.balance() + transaction.sum()*tempCard.currency().rateUAH();
    tempCard.balance(newBalance);
    setCard(tempCard);
    _storedTransactions.push_back(transaction);
}
void StorageMock::doAddTransactionCards(const TransactionsCards& transaction, const Card& cardFrom, const Card& cardTo) {
    DBCardMock tempCardFrom = getDBCard(cardFrom.cardNumber());
    DBCardMock tempCardTo = getDBCard(cardTo.cardNumber());
    double newBalanceFrom = tempCardFrom.balance() - transaction.sum()*tempCardFrom.currency().rateUAH();
    double newBalanceTo = tempCardTo.balance() + transaction.sum()*tempCardTo.currency().rateUAH();
    tempCardFrom.balance(newBalanceFrom);
    tempCardTo.balance(newBalanceTo);
    setCard(tempCardFrom);
    setCard(tempCardTo);
    _storedTransactions.push_back(transaction);
}

bool StorageMock::doCheckAuthCard(const AuthCard& authCard) const {
    for(int i = 0; i< cardSize(); i++){
        if(authCard.cardNumber() == _storedCards[i].cardNumber())
            return true;
    }
    return false;
}

Card StorageMock::doGetCard(const QString& number) const {
    for(int i = 0; i< cardSize(); i++){
        try {
            if(_storedCards[i].cardNumber() == number)
                return Card(_storedCards[i].cardNumber(), _storedCards[i].balance(),
                            User(_storedCards[i].user().name(),
                                 _storedCards[i].user().surname()),
                            _storedCards[i].currency());
        }  catch (Card::BadCard bc) {
            throw BadStorage(bc.diagnose());
        }
    }
    throw BadStorage("No such card stored");
}

User StorageMock::doGetUser(const QString& number) const {
    for(int i = 0; i< userSize(); i++){
        if(_storedUsers[i].passportNum() == number)
            return User(_storedUsers[i].name(), _storedUsers[i].surname());
    }
    throw BadStorage("No such user stored");
}

Account StorageMock::doGetAccount(const QString& searchedIban) const {
    for(int i = 0; i< accSize(); i++){
        try {
            if(_storedAccs[i].iban() == searchedIban)
                return _storedAccs[i];
        }  catch (Account::BadAccount ba) {
            throw BadStorage(ba.diagnose());
        }
    }
    throw BadStorage("No such accaunt stored");
}

vector<QString> StorageMock::doGetTransactionsList(const Card&) const {
    vector<QString> res;
    //No action here
    return res;
}

vector<QString> StorageMock::doGetAllCharitiyTitles() const {
    vector<QString> res;
    for(int i = 0; i<accSize(); i++){
        if(_storedAccs[i].type().name().toStdString() == "charity")
            res.push_back(_storedAccs[i].company().title());
    }
    return res;
}

vector<QString> StorageMock::doGetAllTitles(const QString&) const {
    vector<QString> res;
    for(int i = 0; i<accSize(); i++){
       res.push_back(_storedAccs[i].company().title());
    }
    return res;
}

const Account& StorageMock::getDBAccaunt(const QString& searchedIban) const {
    for(int i = 0; i<accSize(); i++){
        if(_storedAccs[i].iban() == searchedIban)
            return _storedAccs[i];
    }
    throw BadStorage("No such Account stored.");
}

const DBCardMock& StorageMock::getDBCard(const QString& srchedCardNumber) const {
    for(int i = 0; i<cardSize(); i++){
        if(_storedCards[i].cardNumber() == srchedCardNumber)
            return _storedCards[i];
    }
    throw BadStorage("No such Card stored.");
}

const DBUserMock& StorageMock::getDBUser(const QString& passNum) const
{
    for(int i = 0; i<userSize(); i++){
        if(_storedUsers[i].passportNum() == passNum)
            return _storedUsers[i];
    }
    throw BadStorage("No such User stored.");
}

void StorageMock::setAccaunt(const Account& acc) {
    for(int i = 0; i<accSize(); i++){
        if(_storedAccs[i].iban() == acc.iban()){
            _storedAccs[i] = acc;
            return;
        }
    }
    throw BadStorage("No such Account stored.");
}

void StorageMock::setCard(const DBCardMock& cardMock) {
    for(int i = 0; i<cardSize(); i++){
        if(_storedCards[i].cardNumber() == cardMock.cardNumber()){
            _storedCards[i] = cardMock;
            return;
        }

    }
    throw BadStorage("No such tgrtg stored.");
}

void StorageMock::setUser(const DBUserMock& userMock)
{
    for(int i = 0; i<userSize(); i++){
        if(_storedUsers[i].passportNum() == userMock.passportNum()){
            _storedUsers[i] = userMock;
            return;
        }

    }
    throw BadStorage("No such User stored.");
}
