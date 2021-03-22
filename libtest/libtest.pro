#-------------------------------------------------
#
# Project created by QtCreator 2020-12-24T21:17:33
#
#-------------------------------------------------

QT       += core gui
QT       += network xml xmlpatterns
QT += websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = libtest
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += ../RequestLib/
LIBS += -L../build-RequestLib-Desktop_Qt_5_6_3_MSVC2015_32bit-Debug/debug/
LIBS += -lRequestLib
