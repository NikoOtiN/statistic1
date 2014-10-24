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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../Qwt-6.1.1/lib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../Qwt-6.1.1/lib/ -lqwtd
else:unix: LIBS += -L$$PWD/../../../../../Qwt-6.1.1/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../../../Qwt-6.1.1/include
DEPENDPATH += $$PWD/../../../../../Qwt-6.1.1/include
