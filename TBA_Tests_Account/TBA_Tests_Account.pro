QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_testaccount.cpp \
            ../TBA_ATM/Account.cpp \
            ../TBA_ATM/StringValidator.cpp \
            ../TBA_ATM/Currency.cpp
HEADERS += ../TBA_ATM/Account.h \
           ../TBA_ATM/StringValidator.h \
           ../TBA_ATM/Currency.h

INCLUDEPATH += ../TBA_ATM
