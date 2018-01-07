#-------------------------------------------------
#
# Project created by QtCreator 2017-04-09T18:03:53
#
#-------------------------------------------------

QT += core gui
QT += network
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myserver
TEMPLATE = app
INCLUDEPATH += /home/brusentsov/progbase3/src/network/
LIBS += /home/brusentsov/progbase3/src/network/lib/libnetwork.a

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp \
    myserver.cpp \
    database.cpp \

HEADERS  += \
    myserver.h \
    database.h \

#RESOURCES += \
#    database.sqlite3
