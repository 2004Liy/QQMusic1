QT       += core gui
QT+=network
QT += multimedia multimediawidgets
QT+=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    audittion.cpp \
    home.cpp \
    homeitem1.cpp \
    homeitem2.cpp \
    hostwidget.cpp \
    hotitem.cpp \
    itemmusic.cpp \
    lately.cpp \
    linkqsl.cpp \
    lyrics.cpp \
    main.cpp \
    mainwindow.cpp \
    musci.cpp \
    musicsound.cpp \
    mybtn.cpp \
    mylove.cpp \
    myqpushbutton.cpp \
    mysearchwidget.cpp \
    themewidget.cpp

HEADERS += \
    audittion.h \
    curmusic.h \
    home.h \
    homeitem1.h \
    homeitem2.h \
    hostwidget.h \
    hotitem.h \
    itemmusic.h \
    lately.h \
    linkqsl.h \
    lyrics.h \
    mainwindow.h \
    musci.h \
    musicsound.h \
    mybtn.h \
    mylove.h \
    myqpushbutton.h \
    mysearchwidget.h \
    themewidget.h

FORMS += \
    audittion.ui \
    home.ui \
    homeitem1.ui \
    homeitem2.ui \
    hotitem.ui \
    itemmusic.ui \
    lyrics.ui \
    mainwindow.ui \
    musicsound.ui \
    mysearchwidget.ui \
    themewidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    111.qrc

DISTFILES += \
    icon/7.png \
    icon/8.png
