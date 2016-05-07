#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T16:14:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = item-resize
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    resizer/graphicsitemresizer.cpp \
    resizer/resizehandleitem.cpp \
    resizer/handlerstrategies.cpp

HEADERS  += mainwindow.h \
    resizer/graphicsitemresizer.h \
    resizer/resizehandleitem.h \
    resizer/handlerstrategies.h

FORMS    += mainwindow.ui

DISTFILES +=
