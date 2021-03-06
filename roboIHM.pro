#-------------------------------------------------
#
# Project created by QtCreator 2015-07-23T09:52:28
#
#-------------------------------------------------

DEPENDPATH += .
MOC_DIR = .build
OBJECTS_DIR = .build
RCC_DIR = .build
UI_DIR = .build

QT = core \
    gui \
    svg \
    network \
    xml \
    declarative

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = roboIHM
TEMPLATE = app


nomcc {
} else {
    LIBS += -lmcc
}


SOURCES += main.cpp\
        mainwindow.cpp \
    gpio.cpp

HEADERS  += mainwindow.h \
    gpio.h

FORMS    += mainwindow.ui


RESOURCES += \
    resources.qrc



# deployment on Linux
unix {
    target.path = /usr/bin/
    images.path = /usr/bin/images/
    images.files = images/*
    INSTALLS += target \
             images \
}

DISTFILES += \
    images/Numero1_blue_25.png \
    images/Numero2_blue_25.png \
    images/Numero3_blue_25.png \
    images/Numero4_blue_25.png \
    images/Toradex.png \
    images/toradex-logo-white.png \
    images/Robo.bin

