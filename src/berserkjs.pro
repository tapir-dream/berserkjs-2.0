#-------------------------------------------------
#
# Project created by QtCreator 2015-04-15T15:10:29
#
#-------------------------------------------------

QT  +=  core
        gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets network printsupport script

CONFIG += testlib console

TARGET = berserkJS
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    networkaccessmanager.cpp \
    monitordata.cpp \
    monitordatamap.cpp \
    customdownload.cpp \
    selector.cpp \
    scriptbinding.cpp \
    mywebview.cpp \
    pageextension.cpp \
    commandparameters.cpp \
    mywebpage.cpp \
    filesystemwatcher.cpp \
    firstscreen.cpp \
    scriptsignalfactory.cpp \
    appinfo.cpp \
    cookiejar.cpp \
    networkresources.cpp

HEADERS  += mainwindow.h \
    networkaccessmanager.h \
    monitordata.h \
    monitordatamap.h \
    customdownload.h \
    selector.h \
    scriptbinding.h \
    mywebview.h \
    pageextension.h \
    commandparameters.h \
    mywebpage.h \
    filesystemwatcher.h \
    firstscreen.h \
    scriptsignalfactory.h \
    appinfo.h \
    consts.h \
    cookiejar.h \
    networkresources.h

FORMS    += mainwindow.ui

win32 {
    LIBS += -lpsapi
}

