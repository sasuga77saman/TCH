#pragma once

#ifndef _TCS_H
#define _TCS_H
#define WIDTH 60
#define HEIGHT 50
int i = 0;
int score = 0;
int lastx = 0;
int lasty = 0;
int dirX = 1, dirY = 0;
//蛇的身体节点坐标结构体 
struct BODY
{
    int x;
    int y;
} body;
//定义的一条蛇，大小与长度 
struct SNAKE
{
    struct BODY body[WIDTH * HEIGHT];
    int size;
    int speed = 200;
} snake;
//食物模块，待完善



//场景，待完善


void initWall(void);
void initSnake(void);//初始化蛇 
void daw(void);//画蛇 
void input(void);//控制模块 
void move(void);//移动模块 
void bodydie(void);// 身体触碰死亡 
void walldie(void);//墙壁触碰死亡 
void speed_change(void);//速度改变
#endi
