#-------------------------------------------------
#
# Project created by QtCreator 2013-04-10T11:04:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QrveFever
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    preparewidget.cpp \
    userswidget.cpp \
    bonuseswidget.cpp \
    userwidget.cpp

HEADERS  += mainwindow.h \
    preparewidget.h \
    userswidget.h \
    bonuseswidget.h \
    userwidget.h \
    datatypes.h

FORMS    += mainwindow.ui \
    preparewidget.ui \
    userswidget.ui \
    bonuseswidget.ui \
    userwidget.ui
