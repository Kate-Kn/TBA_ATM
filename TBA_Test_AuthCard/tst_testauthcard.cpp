#include <QtTest>
#include "AuthCard.h"
#include <string>
using namespace std;

class TestAuthCard : public QObject
{
    Q_OBJECT

public:
    TestAuthCard();
    ~TestAuthCard();

private slots:
    void test_correct_authCard();
    void test_authCard_card_wrong_length();
    void test_authCard_card_contains_not_num();
};

TestAuthCard::TestAuthCard()
{

}

TestAuthCard::~TestAuthCard()
{

}

void TestAuthCard::test_correct_authCard()
{
    try{

            AuthCard correct("0345", "4321");
    }catch (AuthCard::BadAuthCard ba){
        QVERIFY2(false, ba.diagnose().toStdString().c_str());
    }
}

void TestAuthCard::test_authCard_card_wrong_length()
{
    bool catchErr = false;
    try{
        AuthCard correct("035", "4321");
    }catch (AuthCard::BadAuthCard ba){
        catchErr = true;
    }
    if (!catchErr)
        QVERIFY2(false, "Can create authCard");
}

void TestAuthCard::test_authCard_card_contains_not_num()
{
    bool catchErr = false;
    try{
        AuthCard correct("0r45", "4421");
    }catch (AuthCard::BadAuthCard ba){
        catchErr = true;
    }
    if (!catchErr)
        QVERIFY2(false, "Can create authCard");
}

QTEST_APPLESS_MAIN(TestAuthCard)

#include "tst_testauthcard.moc"
