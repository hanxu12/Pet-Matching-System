QT += sql
QT += core
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

LIBS += -pthread
SOURCES += ../../gtest/googletest/src/gtest-all.cc

INCLUDEPATH += ../../gtest \
 ../../gtest/googletest \
 ../../gtest/googletest/include \
 ../../gtest/googletest/include/gtest

HEADERS += ../cuddlySys/database.h \
../cuddlySys/usermanager.h
../cuddlySys/petmanager.h

SOURCES += main.cpp \
../cuddlySys/database.cpp \
../cuddlySys/usermanager.cpp \
../cuddlySys/petmanager.cpp
