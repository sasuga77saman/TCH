#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>		
#include <conio.h>

#define SNAKE_NUM  500
enum DIR
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
struct Snacke
{
	int size;
	int dir;
	int speed;
	POINT coor[SNAKE_NUM]; 
}snake;
void GameInit()
{
	initgraph(640, 480, SHOWCONSOLE);
	snake.size = 3;
	snake.speed = 10;
	snake.dir=RIGHT;
	for (int i = 0; i < snake.size; i++)
	{
		snake.coor[i].x = 40-10*i;
		snake.coor[i].y = 10;
		printf("%d%d", snake.coor[i].x, snake.coor[i].y);
	}

}
void GameDraw()
{
	BeginBatchDraw();
	setbkcolor(RGB(28, 115, 119));
	cleardevice();
	setfillcolor(RED);
	for (int i = 0; i < snake.size; i++)
	{
		solidcircle(snake.coor[i].x, snake.coor[i].y, 5);
	}
	EndBatchDraw();
}

void snakemove()
{
	for (int i = 0; i < snake.size; i++)
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

void keyControl()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case'w':
		case'W':
		case 72:
			snake.dir = UP;
			break;
		case'a':
		case'A':
		case 80:
			snake.dir = DOWN;
			break;
		case's':
		case'S':
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
}


int main()
{
	GameInit();
	GameDraw();
	
	while (1)
	{
		GameDraw();
		snakemove();
		keyControl();
		Sleep(20);
	}
	return 0;
}
