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

OTHER_FILES += \
    resources/Numero1_blue_25.png \
    resources/Numero2_blue_25.png \
    resources/Numero3_blue_25.png \
    resources/Numero4_blue_25.png \
    resources/toradex-logo-white.png \
    resources/Toradex.png



# deployment on Linux
unix {
    target.path = /usr/bin/
    resources.path = /home/root/resources
    resources.files = resources/*
    other_files.path = /home/root/other_files
    INSTALLS += target \
             resources \
             other_files \
}

