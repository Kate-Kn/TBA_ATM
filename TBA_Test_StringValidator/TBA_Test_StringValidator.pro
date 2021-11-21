QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_teststringvalidator.cpp\
            ../TBA_ATM/StringValidator.cpp
HEADERS += ../TBA_ATM/StringValidator.h

INCLUDEPATH += ../TBA_ATM

