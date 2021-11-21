QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_testtransactionservice.cpp \
            ../TBA_ATM/TransactionCash.cpp \
            ../TBA_ATM/TransactionsCardAccount.cpp \
            ../TBA_ATM/TransactionsCards.cpp \
            ../TBA_ATM/TransactionService.cpp \
            ../TBA_ATM/Account.cpp \
            ../TBA_ATM/Card.cpp \
            ../TBA_ATM/Currency.cpp \
            ../TBA_ATM/StringValidator.cpp \
            ../TBA_ATM/Cryptor.cpp

HEADERS += ../TBA_ATM/ITransaction.h \
           ../TBA_ATM/ITransactionService.h \
           ../TBA_ATM/TransactionCash.h \
           ../TBA_ATM/TransactionsCardAccount.h \
           ../TBA_ATM/TransactionsCards.h \
           ../TBA_ATM/TransactionService.h \
           ../TBA_ATM/Account.h \
           ../TBA_ATM/Card.h \
           ../TBA_ATM/IStorage.h \
           ../TBA_ATM/Currency.h \
           ../TBA_ATM/StringValidator.h \
           ../TBA_ATM/Cryptor.h \
           ../TBA_ATM/ICryptor.h

INCLUDEPATH += ../TBA_ATM
