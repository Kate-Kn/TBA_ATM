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
    Card.cpp \
    StringValidator.cpp \
    TransactionsCardAccount.cpp \
    TransactionsCards.cpp \
    TransactionsCash.cpp \
    db_config.cpp \
    db_connection.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Account.h \
    AccountType.h \
    Card.h \
    Company.h \
    ITransaction.h \
    StringValidator.h \
    TransactionCash.h \
    TransactionsCardAccount.h \
    TransactionsCards.h \
    db_connection.h \
    User.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
