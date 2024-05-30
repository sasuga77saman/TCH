#ifndef _TCS_H
#define _TCS_H
#define WIDTH 65
#define HEIGHT 28
int i = 0;
int s = 0;
int score = 0;
int lastx = 0;
int lasty = 0;
int dirX = 1, dirY = 0;
struct FOOD
{
	int x;
	int y;
}food;
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
	int sz = 1;
	int speed = 100;
} snake;
struct FOOD1
{
	int x;
	int y;
}food1;

struct FOOD2
{
	int x;
	int y;
}food2;

struct FOOD3
{
	int x;
	int y;
}food3;

struct FOOD4
{
	int x;
	int y;
}food4;

struct FOOD5
{
	int x;
	int y;
	int fx = 1;
}food5;

//声明：
void initSnake(void);//初始化蛇 
void initWall(void);
void daw(void);//画蛇 
void input(void);//控制模块 
void move(void);//移动模块 
void bodydie(void);// 身体触碰死亡 
void walldie(void);//墙壁触碰死亡 
void speed_change(void);//速度改变
void sp(void);
void eat_food(void);//统计分数
void food_sc(void);//食物生成
void food1_sc(void);
void food2_sc(void);
void food3_sc(void);
void food4_sc(void);
void food5_sc(void);
#endif
