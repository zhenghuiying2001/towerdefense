#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include "mybutton.h"
#include "mywindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(800,600);
    ui->setupUi(this);
    MyButton *btn=new MyButton(":/D:/BaiduNetdiskDownload/button.jpg");
    btn->setParent(this);
    btn->move(250,40);
    MyWindow* scene=new MyWindow;
    connect(btn,&QPushButton::clicked,this,[=](){
        btn->zoomdown();
        btn->zoomup();
        QTimer::singleShot(500,this,[=](){
            this->hide();
            scene->show();
        });
    });
    connect(scene,&MyWindow::chooseBack,this,[=](){
        scene->hide();
        this->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pixmap(":/D:/BaiduNetdiskDownload/img_bg_level_2.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
