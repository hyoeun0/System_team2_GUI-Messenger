QT += core gui network
QT += network
QT += uitools
QMAKEPATH += /path/to/qt

QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app

CONFIG += c++11

MOBILITY += multimedia

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui


