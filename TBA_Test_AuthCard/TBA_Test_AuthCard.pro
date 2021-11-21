QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_testauthcard.cpp\
            ../TBA_ATM/AuthCard.cpp \
            ../TBA_ATM/StringValidator.cpp
HEADERS += ../TBA_ATM/AuthCard.h \
            ../TBA_ATM/StringValidator.h

INCLUDEPATH += ../TBA_ATM
