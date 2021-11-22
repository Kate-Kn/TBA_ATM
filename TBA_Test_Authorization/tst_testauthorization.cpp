#include <QtTest>
#include "IStorage.h"
#include "TransactionService.h"
#include <list>
#include <iterator>
#include <iostream>
#include "Cryptor.h"
#include "ICryptor.h"
#include <IAuthorization.h>
#include <Authorization.h>
using namespace std;


class DBUserMock{
private:
    QString _name;
    QString _passportNum;
    QString _surname;
public:
    DBUserMock(QString name, QString surname): _name(name), _surname(surname) { return; }
    DBUserMock(const User& user): _name(user.name()), _surname(user.surname()){ return; }
    DBUserMock() { return; }
    ~DBUserMock(){ return; }
    const QString& name() const { return _name; }
    const QString& surname() const { return _surname; }
    const QString& passportNum() const { return _passportNum; }
    void name(const QString& newName) { _name = newName; return; }
    void passportNum(const QString& newPasportNum ) { _passportNum = newPasportNum; return; }
    void surname(const QString& newSurname) { _surname = newSurname; return; }
};

class DBCardMock{
private:
    QString _cardNumber;
    QString _password;
    double _balance;
    DBUserMock _user;
    Currency _currency;
public:
    DBCardMock(QString newCardNumber, QString newPassword, double newBalance, User newUser, Currency newCurrency) :
    _cardNumber(newCardNumber), _password(newPassword), _balance(newBalance), _user(newUser), _currency(newCurrency){ return; }
    DBCardMock(const DBCardMock& card):
    _cardNumber(card.cardNumber()), _password(card.password()), _balance(card.balance()),
    _user(card.user()), _currency(card.currency()){ return; }
    DBCardMock(){ return; }
    ~DBCardMock(){ return; }
    const QString& cardNumber() const { return _cardNumber; }
    const double& balance() const { return _balance; }
    const DBUserMock& user() const { return _user; }
    const Currency& currency() const { return _currency; }
    const QString& password() const { return _password; }
    void cardNumber(const QString& newCardNumber) { _cardNumber = newCardNumber; return; }
    void balance(const double& newBalance) { _balance = newBalance; return; }
    void user(const User& newUser) { _user = newUser; return; }
    void currency(const Currency& newCurency) { _currency = newCurency; return; }
    void password(const QString& newPassword) { _password = newPassword; return; }
};


class StorageMock: public IStorage{
private:
    vector<DBCardMock> _storedCards;
    vector<Account> _storedAccs;
    vector<DBUserMock> _storedUsers;
    vector <ITransaction> _storedTransactions;
    virtual void doAddTransactionCardAccount(const TransactionsCardAccount&, const Card&, const Account&) override;
    virtual void doAddTransactionCash(const TransactionCash&, const Card&) override;
    virtual void doAddTransactionCards(const TransactionsCards&, const Card&, const Card&) override;
    virtual bool doCheckAuthCard(const AuthCard&) const override;
    virtual Card doGetCard(const QString&) const override;
    virtual User doGetUser(const QString&) const override;
    virtual Account doGetAccount(const QString&) const override;
    virtual QVector<QString> doGetAllCharitiyTitles() const override;
    virtual void doChangePassword(const Card& card,const QString& pin) override;
    StorageMock(const StorageMock&) = delete;
    const Account& getDBAccaunt(const QString&) const;
    const DBCardMock& getDBCard(const QString&) const;
    const DBUserMock& getDBUser(const QString&) const;
    void setAccaunt(const Account&);
    void setCard(const DBCardMock&);
    void setUser(const DBUserMock&);
public:
    int cardSize() const { return _storedCards.size(); }
    int accSize() const { return _storedAccs.size(); }
    int userSize() const { return _storedUsers.size(); }
    StorageMock(const vector<DBCardMock> cards, const vector<Account> accs,
                const vector<DBUserMock> users, const vector <ITransaction>& transactions);
    StorageMock(){ return; };
    ~StorageMock() { return; };
};

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
        if(authCard.cardNumber() == _storedCards[i].cardNumber() &&
           authCard.pincode() == _storedCards[i].password())
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

void StorageMock::doChangePassword(const Card& card,const QString& pin){
    DBCardMock cardb = getDBCard(card.cardNumber());
    cardb.password(pin);
    setCard(cardb);
    return;
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

QVector<QString> StorageMock::doGetAllCharitiyTitles() const {
    QVector<QString> res;
    for(int i = 0; i<accSize(); i++){
        if(_storedAccs[i].type().name().toStdString() == "charity")
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


struct MockBuilder{
    MockBuilder();
    ~MockBuilder() { return; }
    IStorage* storage;
    ITransactionService* service;
    vector<DBCardMock> cards;
    vector<DBUserMock> users;
    vector<Account> accs;
};

MockBuilder::MockBuilder(){
    vector <ITransaction> transactions;
    User user1("Victor", "Iliane");
    User user2("Geo", "Lovorin");
    User user3("Voldemar", "Winnik");
    User user4("Alex", "Kilen");
    Currency grivna("UAH", 1.0);
    Currency dollar("USD", 0.038);
    Currency euro("EUO", 0.033);
    ICryptor* crypt = new Cryptor();
    cards.push_back(DBCardMock("6890", crypt->cryptPassword("3211"), 34.34, user1,  grivna)); //0
    cards.push_back(DBCardMock("3557", crypt->cryptPassword("8921"), 100.0, user1,  dollar)); //1
    cards.push_back(DBCardMock("0977", crypt->cryptPassword("3531"), 78.34, user1,  euro));   //2
    cards.push_back(DBCardMock("9876", crypt->cryptPassword("0953"), 0.0, user2,  grivna));   //3
    cards.push_back(DBCardMock("6547", crypt->cryptPassword("6732"), 42.0, user2,  dollar));  //4
    cards.push_back(DBCardMock("0743", crypt->cryptPassword("8730"), 744.74, user2,  euro));  //5
    cards.push_back(DBCardMock("0132", crypt->cryptPassword("7805"), 903.98, user3,  grivna));//6
    cards.push_back(DBCardMock("6421", crypt->cryptPassword("5241"), 1.0, user3,  dollar));   //7
    cards.push_back(DBCardMock("9832", crypt->cryptPassword("7021"), 352.33, user3,  euro));  //8
    cards.push_back(DBCardMock("9375", crypt->cryptPassword("3425"), 9.32, user4,  grivna));  //9

    users.push_back(user1);
    users.push_back(user2);
    users.push_back(user3);
    users.push_back(user4);

    Company vet("VetPlus", "Vet clinic");
    Company tel("Vodafone", "phone compony");
    AccountType charity("charity", "acc for charity");
    AccountType tellProvider ("charity", "acc for charity");
    Account acc1("7911", "charity cats", vet, charity, grivna);
    Account acc2("4321", "charity dogs", vet, charity, dollar);
    Account acc3("8931", "telephons in Ukrain", tel, tellProvider, grivna);
    Account acc4("8201", "telephons in Spain", tel, tellProvider, dollar);

    accs.push_back(acc1);
    accs.push_back(acc2);
    accs.push_back(acc3);
    accs.push_back(acc4);

    storage = new StorageMock(cards, accs, users, transactions);
    service = new TransactionService(storage);
}

class TestAuthorization : public QObject
{
    MockBuilder mockBuilder;
    Q_OBJECT

public:
    TestAuthorization();
    ~TestAuthorization();

private slots:
    void test_authorization_valid();
    void test_authorization_invalid();
};

TestAuthorization::TestAuthorization()
{

}

TestAuthorization::~TestAuthorization()
{

}

void TestAuthorization::test_authorization_valid()
{
    bool check = false;
    AuthCard card("3557", "8921");
    ICryptor* crypt = new Cryptor;
    IAuthorization* auth = new Authorization(mockBuilder.storage, crypt);
    try {
            check = auth->checkAuthorizationData(card);
    }  catch (IAuthorization::BadAuthorization ba) {
        cout<<ba.diagnose().toStdString()<<endl;
    }
    QVERIFY2(check, "Authorization must be valid");
}

void TestAuthorization::test_authorization_invalid()
{
    bool check = false;
    AuthCard card("3557", "9921");
    ICryptor* crypt = new Cryptor;
    IAuthorization* auth = new Authorization(mockBuilder.storage, crypt);
    try {
            check = auth->checkAuthorizationData(card);
    }  catch (IAuthorization::BadAuthorization ba) {
        cout<<ba.diagnose().toStdString()<<endl;
    }
    QVERIFY2(!check, "Authorization must be invalid");
}

QTEST_APPLESS_MAIN(TestAuthorization)

#include "tst_testauthorization.moc"
