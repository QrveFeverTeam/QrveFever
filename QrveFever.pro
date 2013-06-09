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
    Widgets/userwidget.cpp \
    Widgets/gamewidget.cpp \
    Widgets/resultswidget.cpp \
    Widgets/resultwidget.cpp \
    utils.cpp \
    Widgets/boardwidget.cpp \
    Game/player.cpp \
    Game/game.cpp

HEADERS  += mainwindow.h \
    Widgets/preparewidget.h \
    Widgets/userswidget.h \
    Widgets/userwidget.h \
    datatypes.h \
    settings.h \
    Widgets/gamewidget.h \
    Widgets/resultswidget.h \
    Widgets/resultwidget.h \
    utils.h \
    Widgets/boardwidget.h \
    Game/player.h \
    Game/game.h

FORMS    += mainwindow.ui \
    Widgets/preparewidget.ui \
    Widgets/userswidget.ui \
    Widgets/userwidget.ui \
    Widgets/gamewidget.ui \
    Widgets/resultswidget.ui \
    Widgets/resultwidget.ui \
    Widgets/boardwidget.ui
