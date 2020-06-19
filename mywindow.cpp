#include "mywindow.h"
<<<<<<< HEAD
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include "mybutton.h"
#include "secondwindow.h"
#include "thirdwindow.h"
#include <QTimer>
MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent)
{

    this->setFixedSize(800,600);
    //在选关界面添加返回按钮
    MyButton* back_btn=new MyButton(":/D:/BaiduNetdiskDownload/backbutton-2.jpg");
    back_btn->setParent(this);
    back_btn->move(650,40);
    connect(back_btn,&MyButton::clicked,this,[=](){
        back_btn->zoomdown();
        back_btn->zoomup();
        QTimer::singleShot(500,this,[=](){
           emit chooseBack();
        });

    });

    //在选关界面添加选择第一关按钮
    MyButton* btn=new MyButton(":/D:/BaiduNetdiskDownload/number-1.jpg");
    btn->setParent(this);
    btn->move(50,50);
    secondwindow* swindow=new secondwindow;
    connect(btn,&QPushButton::clicked,this,[=](){
        btn->zoomdown();
        btn->zoomup();
        QTimer::singleShot(500,this,[=](){
            this->close();
            swindow->show();
        });
     });
    connect(swindow,&secondwindow::chooseBack,this,[=](){
       swindow->hide();
        this->show();
    });

    //在选关界面添加选择第二关按钮
    MyButton* btn2=new MyButton(":/D:/BaiduNetdiskDownload/number-2.jpg");
    btn2->setParent(this);
    btn2->move(450,200);
    thirdwindow* twindow=new thirdwindow;
    connect(btn2,&QPushButton::clicked,this,[=](){
       btn2->zoomdown();
       btn2->zoomup();
       QTimer::singleShot(500,this,[=](){
           this->close();
           twindow->show();
        });
     });
    connect(twindow,&thirdwindow::chooseBack,this,[=](){
         twindow->hide();
         this->show();
     });
}


//绘制选关界面
void MyWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap(":/D:/BaiduNetdiskDownload/background-1");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
=======
#include "mybutton.h"
#include <QPainter>
MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(800,600);
    MyButton* back_btn=new MyButton(":/D:/BaiduNetdiskDownload/button-6.jpg");
    back_btn->setParent(this);
    back_btn->move(40,40);
    MyButton* setTower=new MyButton(":/D:/BaiduNetdiskDownload/button-8.jpg");
    setTower->setParent(this);
    setTower->move(40,200);
    connect(setTower,&MyButton::clicked,this,&MyWindow::set_tower);
    connect(back_btn,&MyButton::clicked,this,[=](){
        emit chooseBack();
    });
}
void MyWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    foreach(Tower* tower,tower_list)
        tower->draw(&painter);
}
void MyWindow::set_tower(){
    Tower* a_new_tower=new Tower(QPoint(200,200),":/D:/BaiduNetdiskDownload/tower-1.jpg");
    tower_list.push_back(a_new_tower);
    update();
>>>>>>> 7522dc93025c53d4ed9281b941da872fbea9bb7f
}
