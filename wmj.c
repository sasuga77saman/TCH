#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#define SNAKE_NUM 500

enum DIR  //蛇的方向
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

//食物
struct Food
{
	int x;
	int y;
	int r;        //半径
	bool flag;    //是否吃了
	DWORD color;  //颜色
}food;


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

	srand(GetTickCount());

	//初始化蛇
	snake.size = 3;
	snake.speed = 10;
	snake.dir = RIGHT;
	for (int i = 0; i <snake.size;i++)
	{

		snake.coor[i].x = 40-10*i;
		snake.coor[i].y = 10;
	}

	food.x = rand() % 640;
	food.y = rand() % 480;
	food.color = RGB(rand()%256,rand()%256,rand()%256);
	food.r = rand() % 10 + 5;
	food.flag = true;
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
	//食物
	if (food.flag)
	{
		solidcircle(food.x, food.y, food.r);
	}

	EndBatchDraw();
}

//移动蛇
void snakeMove()
{
	for (int i = snake.size-1;i >0;i--)
	{
		snake.coor[i] = snake.coor[i - 1];
	}
	switch (snake.dir)
	{
	case UP:
		snake.coor[0].y-=snake.speed;
		if (snake.coor[0].y+10 <= 0)//超出边界
		{
			snake.coor[0].y = 480;
		}
		break;
	case DOWN:
		snake.coor[0].y+=snake.speed;
		if (snake.coor[0].y - 10 >= 480)//超出边界
		{
			snake.coor[0].y = 0;
		}
		break;
	case LEFT:
	    snake.coor[0].x-=snake.speed;
		if (snake.coor[0].x + 10 <= 0)//超出边界
		{
			snake.coor[0].x = 640;
		}
			break;
	case RIGHT:
		snake.coor[0].x+=snake.speed;
		if (snake.coor[0].x - 10 >= 640)//超出边界
		{
			snake.coor[0].x = 0;
		}
		break;
	}
}

//改变方向
void keyControl()

{
	//判断有没有按键
	if (_kbhit())
	{

		//72 80 75 77上下左右
		switch (_getch())
		{
		case'w':
		case'W':
		case 72:
			if (snake.dir != DOWN)
			{
				snake.dir = UP;
			}
			break;

		case's':
		case'S':
		case 80:
			if (snake.dir !=UP)
			{
				snake.dir = DOWN;
			}
			break;

		case'a':
		case'A':
		case 75:
			if (snake.dir != RIGHT)
			{
				snake.dir = LEFT;
			}
			break;
		case'd':
		case'D':
		case 77:
			if (snake.dir != LEFT)
			{
				snake.dir = RIGHT;
			}
			break;
		case ' '://暂停
			while (1)
			{
				if (_getch() == ' ')
					return;
			}
			break;
		}
	}
}

void EatFood()
{
	if (food.flag&&snake.coor[0].x >= food.x-food.r && snake.coor[0].x <= food.x+food.r &&
		snake.coor[0].y >= food.y-food.r && snake.coor[0].y <= food.y+food.r)
	{
		food.flag = false;
		snake.size++;
	}
	//吃了重新生成
	if (!food.flag)
	{
		food.x = rand() % 640;
		food.y = rand() % 480;
		food.color = RGB(rand() % 256, rand() % 256, rand() % 256);
		food.r = rand() % 10 + 5;
		food.flag = true;
	}


}

int main()
{
	GameInit();

	while (1)
	{
		snakeMove();
		GameDraw();
		keyControl();
		EatFood();
		Sleep(100);
	}

	return 0;
}
