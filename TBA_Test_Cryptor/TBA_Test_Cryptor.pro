QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_testcryptor.cpp \
            ../TBA_ATM/Cryptor.cpp

HEADERS += ../TBA_ATM/Cryptor.h \
           ../TBA_ATM/ICryptor.h

INCLUDEPATH += ../TBA_ATM
