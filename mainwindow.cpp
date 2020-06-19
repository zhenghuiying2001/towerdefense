#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
<<<<<<< HEAD
#include "mybutton.h"
#include "mywindow.h"
#include <QTimer>
#include "config.h"

=======
#include <QTimer>
#include "mybutton.h"
#include "mywindow.h"
>>>>>>> 7522dc93025c53d4ed9281b941da872fbea9bb7f
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(800,600);
    ui->setupUi(this);
<<<<<<< HEAD


    //在开始界面添加开始游戏按钮
    MyButton* btn=new MyButton(":/D:/BaiduNetdiskDownload/button.jpg");
    btn->setParent(this);
    btn->move(250,50);
=======
    MyButton *btn=new MyButton(":/D:/BaiduNetdiskDownload/button.jpg");
    btn->setParent(this);
    btn->move(250,40);
>>>>>>> 7522dc93025c53d4ed9281b941da872fbea9bb7f
    MyWindow* scene=new MyWindow;
    connect(btn,&QPushButton::clicked,this,[=](){
        btn->zoomdown();
        btn->zoomup();
        QTimer::singleShot(500,this,[=](){
<<<<<<< HEAD
            this->close();
            scene->show();
        });

    });
    connect(scene,&MyWindow::chooseBack,this,[=](){
        scene->close();
        this->show();
    });
    MyButton* exit=new MyButton(":/D:/BaiduNetdiskDownload/exit.jpg");
    exit->setParent(this);
    exit->move(250,200);
    connect(exit,&QPushButton::clicked,this,[=](){
        exit->zoomdown();
        exit->zoomup();
        QTimer::singleShot(500,this,[=](){
            this->close();
        });
    });

=======
            this->hide();
            scene->show();
        });
    });
    connect(scene,&MyWindow::chooseBack,this,[=](){
        scene->hide();
        this->show();
    });
>>>>>>> 7522dc93025c53d4ed9281b941da872fbea9bb7f
}

MainWindow::~MainWindow()
{
    delete ui;
}
<<<<<<< HEAD



//创建开始界面
void MainWindow::paintEvent(QPaintEvent *){
=======
void MainWindow::paintEvent(QPaintEvent*){
>>>>>>> 7522dc93025c53d4ed9281b941da872fbea9bb7f
    QPainter painter(this);
    QPixmap pixmap(":/D:/BaiduNetdiskDownload/img_bg_level_2.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
<<<<<<< HEAD

=======
>>>>>>> 7522dc93025c53d4ed9281b941da872fbea9bb7f
