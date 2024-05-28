#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#define SNAKE_NUM 500

enum DIR  //蛇的方向
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

struct Snake
{
	int size;//节数
	int dir;//方向
	int speed;//速度
	POINT coor[SNAKE_NUM];//坐标
}snake;

void GameInit()
{
	initgraph(640, 480);

	//初始化蛇
	snake.size = 3;
	snake.speed = 1;
	snake.dir = RIGHT;
	for (int i = 0; i <snake.size;i++)
	{

		snake.coor[i].x = 40-10*i;
		snake.coor[i].y = 10;
	}
}

void GameDraw()
{
	//双缓冲画图

	BeginBatchDraw();

	//设置背景板颜色
	setbkcolor(RGB(28, 115, 119));
	cleardevice();
	//画蛇
	setfillcolor(GREEN);
	for (int i = 0;i < snake.size;i++)
	{
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	EndBatchDraw();
}

//移动蛇
void snakeMove()
{
	for (int i = 0;i < snake.size;i++)
	{
		switch (snake.dir)
		{
		case UP:
			snake.coor[i].y--;
			break;
		case DOWN:
			snake.coor[i].y++;
			break;
		case LEFT:
			snake.coor[i].x--;
				break;
		case RIGHT:
			snake.coor[i].x++;
			break;
		}
	}

}

//改变方向
void keyControl()
{
	//72 80 75 77上下左右
	switch (_getch())
	{
	case'w':
	case'W':
	case 72:
		snake.dir = UP;
		break;
	case's':
	case'S':
	case 80:
		snake.dir = DOWN;
		break;
	case'a':
	case'A':
	case 75:
		snake.dir = LEFT;
		break;
	case'd':
	case'D':
	case 77:
		snake.dir = RIGHT;
		break;
	}
}

int main()
{
	GameInit();
	GameDraw();

	while (1)
	{
		GameDraw();
		snakeMove();
		keyControl();
		Sleep(50);
	}

	return 0;
}
