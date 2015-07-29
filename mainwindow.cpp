#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gpio.h"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QPixmap topBar("/usr/bin/images/Toradex.png");
    QPixmap downBar("/usr/bin/images/Toradex.png");
    QPixmap logo("/usr/bin/images/toradex-logo-white.png");
    QPixmap number1("/usr/bin/images/Numero1_blue_25.png");
    QPixmap number2("/usr/bin/images/Numero2_blue_25.png");
    QPixmap number3("/usr/bin/images/Numero3_blue_25.png");
    QPixmap number4("/usr/bin/images/Numero4_blue_25.png");


    ui->btn1->setIcon(number1);
    ui->btn2->setIcon(number2);
    ui->btn3->setIcon(number3);
    ui->btn4->setIcon(number4);

    ui->label->setPixmap(topBar);
    ui->label_2->setPixmap(downBar);
    ui->label_3->setPixmap(logo);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setExternGpio(GpioOnOff *value)
{
    externGpio = value;
}




void MainWindow::on_slider1_valueChanged(int value)
{
    externGpio->setData1(value);
}

void MainWindow::on_slider2_valueChanged(int value)
{
    externGpio->setData2(value);
}

void MainWindow::on_slider3_valueChanged(int value)
{
    externGpio->setData3(value);
}

void MainWindow::on_slider4_valueChanged(int value)
{
    externGpio->setData4(value);
}

void MainWindow::on_btn1_clicked()
{
    ui->slider1->setValue(100);
    ui->slider2->setValue(75);
    ui->slider3->setValue(45);
    ui->slider4->setValue(53);
    externGpio->setData1(100);
    externGpio->setData2(75);
    externGpio->setData3(45);
    externGpio->setData4(53);
}

void MainWindow::on_btn2_clicked()
{
    ui->slider1->setValue(100);
    ui->slider2->setValue(75);
    ui->slider3->setValue(50);
    ui->slider4->setValue(70);
    externGpio->setData1(100);
    externGpio->setData2(75);
    externGpio->setData3(50);
    externGpio->setData4(70);
}

void MainWindow::on_btn3_clicked()
{
    ui->slider1->setValue(5);
    ui->slider2->setValue(47);
    ui->slider3->setValue(100);
    ui->slider4->setValue(70);
    externGpio->setData1(5);
    externGpio->setData2(47);
    externGpio->setData3(100);
    externGpio->setData4(70);
}

void MainWindow::on_btn4_clicked()
{
    ui->slider1->setValue(5);
    ui->slider2->setValue(47);
    ui->slider3->setValue(100);
    ui->slider4->setValue(53);
    externGpio->setData1(5);
    externGpio->setData2(47);
    externGpio->setData3(100);
    externGpio->setData4(53);
}
