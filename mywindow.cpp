#include "mywindow.h"
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
}
