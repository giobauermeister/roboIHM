#include "mainwindow.h"
#include <QApplication>
#include <QWidget>
//#include "gpio.h"
#include <QWSServer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv, QApplication::GuiServer);
    QDeclarativeView view;

    GpioOnOff gpio;
    gpio.start();

    MainWindow w;

    //hide the cursor as we use touchscreen
    QWSServer *server = QWSServer::instance();
    if(server) {
        server->setCursorVisible(false);
    }

    w.setCursor(Qt::BlankCursor);
    w.setWindowState(w.windowState() ^ Qt::WindowFullScreen);
    w.setExternGpio(&gpio);
    w.show();

    gpio.terminate();

    return a.exec();
}
