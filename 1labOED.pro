#-------------------------------------------------
#
# Project created by QtCreator 2014-10-20T21:44:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = 1labOED
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    mainwindow.cpp \
    func_hyp.cpp

HEADERS  += dialog.h \
    mainwindow.h \
    func_hyp.h

FORMS    += dialog.ui
