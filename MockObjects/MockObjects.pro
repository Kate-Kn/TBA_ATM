QT -= gui

TEMPLATE = lib
DEFINES += MOCKOBJECTS_LIBRARY

CONFIG += c++11

TARGET = MockObjects

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    storagemock.cpp\
    ../TBA_ATM/TransactionCash.cpp \
    ../TBA_ATM/TransactionsCardAccount.cpp \
    ../TBA_ATM/TransactionsCards.cpp \
    ../TBA_ATM/TransactionService.cpp \
    ../TBA_ATM/Account.cpp \
    ../TBA_ATM/Card.cpp \
    ../TBA_ATM/Currency.cpp \
    ../TBA_ATM/StringValidator.cpp

HEADERS +=

HEADERS += \
    MockObjects_global.h \
    storagemock.h \
    ../TBA_ATM/ITransaction.h \
    ../TBA_ATM/ITransactionService.h \
    ../TBA_ATM/TransactionCash.h \
    ../TBA_ATM/TransactionsCardAccount.h \
    ../TBA_ATM/TransactionsCards.h \
    ../TBA_ATM/TransactionService.h \
    ../TBA_ATM/Account.h \
    ../TBA_ATM/Card.h \
    ../TBA_ATM/IStorage.h \
    ../TBA_ATM/Currency.h \
    ../TBA_ATM/StringValidator.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += ../TBA_ATM
