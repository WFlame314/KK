QT       += core gui network websockets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addwindow.cpp \
    base.cpp \
    chatshow.cpp \
    dealwindow.cpp \
    main.cpp \
    logwindow.cpp \
    mainwindow.cpp \
    mylabel.cpp \
    mytools.cpp \
    personlist.cpp \
    personlistbuddy.cpp \
    chatspace.cpp \
    words.cpp \
    personfindlist.cpp \
    personfindlistbuddy.cpp \
    addmessagelist.cpp \
    addmessagelistbuddy.cpp \
    Loading.cpp

HEADERS += \
    addwindow.h \
    base.h \
    chatshow.h \
    dealwindow.h \
    logwindow.h \
    mainwindow.h \
    mylabel.h \
    mytools.h \
    personlist.h \
    personlistbuddy.h \
    chatspace.h \
    words.h \
    personfindlist.h \
    personfindlistbuddy.h \
    addmessagelist.h \
    addmessagelistbuddy.h \
    Loading.h

FORMS += \
    addwindow.ui \
    dealwindow.ui \
    logwindow.ui \
    mainwindow.ui \
    chatspace.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    stylesfile.qrc
