#-------------------------------------------------
#
# Project created by QtCreator 2020-12-24T20:16:32
#
#-------------------------------------------------

QT       += network xml xmlpatterns
QT += websockets
QT       -= gui

TARGET = RequestLib
TEMPLATE = lib

DEFINES += REQUESTLIB_LIBRARY

SOURCES += requestlib.cpp \
        getprice.cpp \
        y_algorithm.cpp

HEADERS += requestlib.h\
        requestlib_global.h \
        date.h \
        ReqCmd.h \
        getprice.h \
        y_algorithm.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
