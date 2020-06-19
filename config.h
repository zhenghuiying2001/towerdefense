#ifndef CONFIG_H
#define CONFIG_H

/********************* 游戏配置数据 ***********************/
#define GAME_TITLE "塔防游戏 v1.0" //标题
#define GAME_RATE 10 //定时器刷新时间间隔

/*********************地图配置数据 ************************/
#define MAP_PATH ":/D:/BaiduNetdiskDownload/background-4.jpg" //地图路径
#define MAP_SCROLL_SPEED 2 //地图滚动的速度

/*********************飞机配置数据 ************************/
#define HERO_PATH ":/D:/BaiduNetdiskDownload/enemy.png"

/*********************子弹配置数据 ************************/
#define BULLET_PATH ":/D:/BaiduNetdiskDownload/bullet_13.png" //子弹图片路径
#define BULLET_SPEED 5 //子弹移动速度
#define BULLET_NUM 30 //弹匣中子弹总数
#define BULLET_INTERVAL 20 //发射子弹时间间隔

#endif // CONFIG_H
