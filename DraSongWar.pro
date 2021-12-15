#-------------------------------------------------
#
# Project created by QtCreator 2020-04-28T18:07:08
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += resources_big
TARGET = DraSongWar
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
           main.cpp  \
    soldier.cpp \
    game.cpp \
    button.cpp \
    gy.cpp \
    chapter.cpp \
    bullet.cpp \
    tower.cpp \
    c1toc8.cpp

HEADERS += \
    soldier.h \
    game.h \
    button.h \
    tower.h \
    bullet.h \
    bullet.h \
    tower.h

RESOURCES += \
    test.qrc

FORMS +=
