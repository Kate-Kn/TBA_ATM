#include <QtTest>
#include "Account.h"
#include "AccountType.h"
#include "Company.h"

class TestAccount : public QObject
{
    Q_OBJECT

public:
    TestAccount();
    ~TestAccount();

private slots:
    void test_correct_account();

};

TestAccount::TestAccount()
{

}

TestAccount::~TestAccount()
{

}

void TestAccount::test_correct_account()
{
    AccountType accType ("chatuty");
    Company accCompany ("Test", "description");
    try{
            Account correct("0345", "description", accCompany, accType);
    }catch (Account::BadAccount ba){
        QVERIFY2(false, "Can not create account");
    }
}

QTEST_APPLESS_MAIN(TestAccount)

#include "tst_testaccount.moc"
