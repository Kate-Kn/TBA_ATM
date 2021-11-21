#include <QtTest>
#include "StringValidator.h"
// add necessary includes here

class TestStringValidator : public QObject
{
    Q_OBJECT

public:
    TestStringValidator();
    ~TestStringValidator();

private slots:
    void test_normal();
    void test_containsChars();
};

TestStringValidator::TestStringValidator()
{

}

TestStringValidator::~TestStringValidator()
{

}

void TestStringValidator::test_normal()
{
    QVERIFY2(isNumericalSequence("2"), "It is nummerical sequens");
    QVERIFY2(isNumericalSequence("234435"), "It is nummerical sequens");
    QVERIFY2(isNumericalSequence("111"), "It is nummerical sequens");
}

void TestStringValidator::test_containsChars()
{
    QVERIFY2(!isNumericalSequence("2344d35"), "It is not nummerical sequens");
    QVERIFY2(!isNumericalSequence("d111"), "It is not nummerical sequens");
    QVERIFY2(!isNumericalSequence("112w"), "It is not nummerical sequens");
    QVERIFY2(!isNumericalSequence("98csc80"), "It is not nummerical sequens");
     QVERIFY2(!isNumericalSequence("98c80"), "It is not nummerical sequens");
}

QTEST_APPLESS_MAIN(TestStringValidator)

#include "tst_teststringvalidator.moc"
