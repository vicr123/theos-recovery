#-------------------------------------------------
#
# Project created by QtCreator 2016-11-11T16:34:40
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = theos-recovery
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    rootpassword.cpp

HEADERS  += mainwindow.h \
    rootpassword.h

FORMS    += mainwindow.ui \
    rootpassword.ui
