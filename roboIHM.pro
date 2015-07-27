#-------------------------------------------------
#
# Project created by QtCreator 2015-07-23T09:52:28
#
#-------------------------------------------------

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
    INSTALLS += target \
        qml \
}

