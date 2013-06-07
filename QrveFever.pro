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
    Widgets/preparewidget.cpp \
    Widgets/userswidget.cpp \
    Widgets/userwidget.cpp

HEADERS  += mainwindow.h \
    Widgets/preparewidget.h \
    Widgets/userswidget.h \
    Widgets/userwidget.h \
    datatypes.h \
    Libs/utils.h \
    settings.h

FORMS    += mainwindow.ui \
    Widgets/preparewidget.ui \
    Widgets/userswidget.ui \
    Widgets/userwidget.ui
