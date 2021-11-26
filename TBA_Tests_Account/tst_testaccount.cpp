#include <QtTest>
#include "Account.h"
#include "AccountType.h"
#include "Company.h"
#include <string>
#include "Currency.h"
using namespace std;

class TestAccount : public QObject
{
    Q_OBJECT

public:
    TestAccount();
    ~TestAccount();

private slots:
    void test_correct_account();
    void test_account_ibn_wrong_length();
    void test_account_ibn_contains_not_num();
};

TestAccount::TestAccount()
{

}

TestAccount::~TestAccount()
{

}

void TestAccount::test_correct_account()
{
    Currency grivna("UAH", 1);
    AccountType accType ("charity", "");
    Company accCompany ("Test", "description");
    try{
            Account correct("0345", "description", accCompany, accType, grivna);
    }catch (Account::BadAccount ba){
        QVERIFY2(false, ba.diagnose().toStdString().c_str());
    }
}

void TestAccount::test_account_ibn_wrong_length()
{
    Currency grivna("UAH", 1);
    bool catchErr = false;
    AccountType accType ("charity", "");
    Company accCompany ("Test", "description");
    try{
            Account correct("03454", "description", accCompany, accType, grivna);
    }catch (Account::BadAccount ba){
        catchErr = true;
    }
    if (!catchErr)
        QVERIFY2(false, "Can create account");
}

void TestAccount::test_account_ibn_contains_not_num()
{
    Currency grivna("UAH", 1);
    bool catchErr = false;
    AccountType accType ("charity", "");
    Company accCompany ("Test", "description");
    try{
            Account correct("0r54", "description", accCompany, accType, grivna);
    }catch (Account::BadAccount ba){
        catchErr = true;
    }
    if (!catchErr)
        QVERIFY2(false, "Can create account");
}

QTEST_APPLESS_MAIN(TestAccount)

#include "tst_testaccount.moc"
