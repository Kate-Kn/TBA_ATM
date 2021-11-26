#include <QtTest>
#include "ICryptor.h"
#include "Cryptor.h"
#include <iostream>
using namespace std;

class TestCryptor : public QObject
{
    Q_OBJECT

public:
    TestCryptor();
    ~TestCryptor();

private slots:
    void test_cryptor();

};

TestCryptor::TestCryptor()
{

}

TestCryptor::~TestCryptor()
{

}

void TestCryptor::test_cryptor()
{
    ICryptor* crypt = new Cryptor();
    QString password("1111");
    QString encryptPassword = crypt->cryptPassword(password);
    QString encryptPasswordCopy = crypt->cryptPassword(password);
    QVERIFY2(password != encryptPassword && encryptPassword == encryptPasswordCopy, "Encryption ewnt wrong.");
}

QTEST_APPLESS_MAIN(TestCryptor)

#include "tst_testcryptor.moc"
