#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gpio.h"

#include <QtGui/QMainWindow>
#include <QtGui>
#include <QDeclarativeView>
#include <QDeclarativeContext>
#include <QWidget>
#include <QLayout>
#include <QObject>

#define ARM
//#define DESKTOP

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    GpioOnOff *externGpio;


    void setExternGpio(GpioOnOff *value);

private slots:
    void on_slider1_valueChanged(int value);

    void on_slider2_valueChanged(int value);

    void on_slider3_valueChanged(int value);

    void on_slider4_valueChanged(int value);

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();


private:
    Ui::MainWindow *ui;

    QPixmap logo;
    QPixmap topBar;
    QPixmap downBar;

    QPixmap number1;
    QPixmap number2;
    QPixmap number3;
    QPixmap number4;


};

#endif // MAINWINDOW_H
