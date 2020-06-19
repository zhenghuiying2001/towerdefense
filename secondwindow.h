#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H
#include <mywindow.h>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QMainWindow>
#include <QList>
#include "heroplane.h"
#include "bullet.h"
#include <QTimer>
#include "map.h"

class secondwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit secondwindow(QWidget *parent = nullptr);

    //初始化场景
    void initScene();

    //飞机对象
    HeroPlane m_hero;

    //重写鼠标移动事件
    void mouseMoveEvent(QMouseEvent*);
    
    //子弹对象
    bullet temp_bullet;

    //定时器
    QTimer m_Timer;

    //启动游戏
    void playGame();

    //更新所有游戏中元素坐标
    void updatePosition();

    //绘制到屏幕中
    void paintEvent(QPaintEvent *);

    //地图对象
    Map m_map;

private:


signals:
    void chooseBack();

};

#endif // SECONDWINDOW_H

