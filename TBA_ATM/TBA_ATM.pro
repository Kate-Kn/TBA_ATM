QT       += core sql

QT       += core gui

TARGET = TBA_ATM

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Account.cpp \
    AuthCard.cpp \
    Authorization.cpp \
    Card.cpp \
    Cryptor.cpp \
    Currency.cpp \
    Storage.cpp \
    StringValidator.cpp \
    TransactionCash.cpp \
    TransactionService.cpp \
    TransactionsCardAccount.cpp \
    TransactionsCards.cpp \
    db_connection.cpp \
    main.cpp \
    mainwindow.cpp \
    sqlrunner.cpp

HEADERS += \
    Account.h \
    AccountType.h \
    AuthCard.h \
    Authorization.h \
    Card.h \
    Company.h \
    Cryptor.h \
    Currency.h \
    IAuthorization.h \
    ICryptor.h \
    IStorage.h \
    ITransaction.h \
    ITransactionService.h \
    Storage.h \
    StringValidator.h \
    TransactionCash.h \
    TransactionService.h \
    TransactionsCardAccount.h \
    TransactionsCards.h \
    db_connection.h \
    User.h \
    mainwindow.h \
    sqlrunner.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
