QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dllswindow.cpp \
    docwindow.cpp \
    getpath.cpp \
    inifile.cpp \
    main.cpp \
    mainwindow.cpp \
    softwarewindow.cpp \
    techdocwindow.cpp \
    transferwindow.cpp

HEADERS += \
    dllswindow.h \
    docwindow.h \
    getpath.h \
    inifile.h \
    mainwindow.h \
    softwarewindow.h \
    techdocwindow.h \
    transferwindow.h

FORMS += \
    dllswindow.ui \
    docwindow.ui \
    mainwindow.ui \
    softwarewindow.ui \
    techdocwindow.ui \
    transferwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
