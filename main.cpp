#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
//#include "gpio.h"


#define ARM
//#define DESKTOP

int main(int argc, char *argv[])
{

    GpioOnOff gpio;
    gpio.start();

#ifdef ARM
    QApplication a(argc, argv , QApplication::GuiServer);
    MainWindow w;
    w.setCursor(Qt::BlankCursor);
    w.setWindowState(w.windowState() ^ Qt::WindowFullScreen);
    w.setExternGpio(&gpio);
    w.show();
#endif

#ifdef DESKTOP
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowState(w.windowState());
    w.setExternGpio(&gpio);
    w.show();
#endif




    return a.exec();
}
