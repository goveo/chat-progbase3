#-------------------------------------------------
#
# Project created by QtCreator 2017-04-09T18:18:21
#
#-------------------------------------------------

QT += core gui
QT += network
QT += sql


CONFIG += release

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myclient
TEMPLATE = app

INCLUDEPATH += /home/brusentsov/progbase3/src/network/
LIBS += /home/brusentsov/progbase3/src/network/lib/libnetwork.a

SOURCES += main.cpp\
        mainwindow.cpp\
    dialog.cpp \
#    network.cpp \
    settings.cpp \
    profile.cpp \
    contacts.cpp \
    privatechat.cpp \
    changeip.cpp

HEADERS  += \
    mainwindow.h\
    dialog.h \
#    network.h \
    settings.h \
    profile.h \
    contacts.h \
    privatechat.h \
    changeip.h

FORMS    += mainwindow.ui \
    dialog.ui \
    settings.ui \
    profile.ui \
    contacts.ui \
    privatechat.ui \
    changeip.ui
