#ifndef _TCS_H
#define _TCS_H
#define WIDTH 40
#define HEIGHT 30
int i = 0;
int score = 0;
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
} snake;
//食物模块，待完善



//场景，待完善


 
void initSnake(void);//初始化蛇 
void daw(void);//画蛇 
void input(void);//控制模块 
void move(void);//移动模块 
void bodydie(void);// 身体触碰死亡 
void walldie(void);//墙壁触碰死亡 
void lenplus(void);//身长增加 
#endif
