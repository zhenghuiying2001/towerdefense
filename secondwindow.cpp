#include "secondwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include <QTimer>
#include "mybutton.h"
#include "mywindow.h"
#include <QPropertyAnimation>
#include <QMouseEvent>
#include "config.h"
#include "bullet.h"

secondwindow::secondwindow(QWidget *parent) : QMainWindow(parent)
{
    //调用初始化场景
    initScene();

    //启动游戏
    playGame();

    this->setFixedSize(800,600);
    //在第一关界面添加返回按钮
    MyButton* back_btn=new MyButton(":/D:/BaiduNetdiskDownload/backbutton-2.jpg");
    back_btn->setParent(this);
    back_btn->move(650,40);
    connect(back_btn,&MyButton::clicked,this,[=](){
        emit chooseBack();
    });
}

void secondwindow::mouseMoveEvent(QMouseEvent * event)
{
    int x =  event->x()-m_hero.m_Rect.width()*0.5;
    int y =  event->y()-m_hero.m_Rect.height()*0.5;

    m_hero.setPosition(x,y);
}

void secondwindow::initScene()
{
    //设置标题
    setWindowTitle(GAME_TITLE);

    //定时器设置
    m_Timer.setInterval(GAME_RATE);
}

void secondwindow::playGame()
{
    //启动定时器
    m_Timer.start();

    //监听计时器发送的信号
    connect(&m_Timer,&QTimer::timeout,[=](){

    //更新游戏中元素的坐标
    updatePosition();

    //绘制到屏幕中
    update();
    });
}

void secondwindow::updatePosition()
{
    //更新地图的坐标
    m_map.mapPosition();
    
    //发射子弹
    m_hero.shoot();

    //计算所有非空闲子弹的当前坐标
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果非空闲，计算发射位置
        if(m_hero.m_bullets[i].m_Free==false)
        {
            m_hero.m_bullets[i].updatePosition();
        }
    }

    //测试子弹
//    temp_bullet.m_Free=false;
//    temp_bullet.updatePosition();
}

void secondwindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);

    //绘制英雄飞机
    painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Plane);

    //绘制子弹
    for(int i=0;i<BULLET_NUM;i++)
    {
        //如果非空闲，绘制
        if(m_hero.m_bullets[i].m_Free==false)
        {
            painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,m_hero.m_bullets[i].m_bullet);
        }

    }

    //测试子弹
//    painter.drawPixmap(temp_bullet.m_X,temp_bullet.m_Y,temp_bullet.m_bullet);

}
