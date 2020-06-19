#include "mybutton.h"
#include <QPixmap>
#include <QPropertyAnimation>
MyButton::MyButton(QString pix):QPushButton(0){
    QPixmap pixmap(pix);
    this->setFixedSize(pixmap.width(),pixmap.height());
<<<<<<< HEAD
    this->setStyleSheet("QPushButton{border:Opx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}
//按钮向下跳
=======
    this->setStyleSheet("QPushButton{border::Opx;}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}
>>>>>>> 7522dc93025c53d4ed9281b941da872fbea9bb7f
void MyButton::zoomdown(){
    QPropertyAnimation* animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}
<<<<<<< HEAD
//按钮向上跳
=======
>>>>>>> 7522dc93025c53d4ed9281b941da872fbea9bb7f
void MyButton::zoomup(){
    QPropertyAnimation* animation=new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}
