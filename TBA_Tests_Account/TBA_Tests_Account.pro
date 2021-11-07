QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_testaccount.cpp \
            ../TBA_ATM/Account.cpp \
            ../TBA_ATM/StringValidator.cpp
HEADERS += ../TBA_ATM/Account.h \
           ../TBA_ATM/StringValidator.h

INCLUDEPATH += ../TBA_ATM
