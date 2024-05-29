#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "tcs.h"
#include<time.h>
int main(int argc, char* argv[]) {
    //隐藏光标 
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    initSnake();
    while (1) {
        daw();
        input();
        move();
        //system("cls");
        //daw();
        Sleep(100);
    }
    srand((unsigned int)time(NULL)); //设置随机数生成起点
    RandFood(); //随机生成食物
    return 0;
}

//蛇模型的初始化，出生位置为场景中心 
void initSnake(void) {
    snake.size = 3;
    //snake.body[0]为蛇的头部 
    snake.body[0].x = WIDTH / 2;
    snake.body[0].y = HEIGHT / 2;

    snake.body[1].x = WIDTH / 2 - 1;
    snake.body[1].y = HEIGHT / 2;

    snake.body[2].x = WIDTH / 2 - 2;
    snake.body[2].y = HEIGHT / 2;
}
//画出初始的蛇 
void daw(void) {
    //COORD为conin库中结构体 
    COORD coord = { 0 };
    i = 0;
    for (i; i < snake.size; i++)
    {
        coord.X = snake.body[i].x;
        coord.Y = snake.body[i].y;
        //这串长代码可以改变光标位置 
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        if (i == 0)
            printf("@");//蛇头部 
        else
            printf("*");//蛇身体 
    }
    coord.X = lastx;
    coord.Y = lasty;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf(" ");
}
void input(void) {
    //_kbhit函数确认是否从键盘获取值，获得输出真；反之亦然 
    if (_kbhit())
    {
        switch (_getch())//从键盘获得值 
        {
        case 'a':
            if (abs(dirX) != 1 && dirY != 0) {
                dirX = -1;
                dirY = 0;
            }
            break;

        case 'd':
            if (abs(dirX) != 1 && dirY != 0) {
                dirX = 1;
                dirY = 0;
            }
            break;
        case 'w':
            if (dirX != 0 && abs(dirY) != 1) {
                dirX = 0;
                dirY = -1;
            }
            break;
        case 's':
            if (dirX != 0 && abs(dirY) != 1) {
                dirX = 0;
                dirY = 1;
            }
            break;
        }
    }
}
void move(void) {

    //从尾部开始，将前一个位置赋值给后一个 ，以达到移动的目的 
    lastx = snake.body[snake.size - 1].x;
    lasty = snake.body[snake.size - 1].y;
    i = snake.size - 1;
    for (i; i > 0; i--)
    {
        snake.body[i].x = snake.body[i - 1].x;
        snake.body[i].y = snake.body[i - 1].y;
    }
    snake.body[0].x += dirX;
    snake.body[0].y += dirY;

}
//尚未完成的死亡机制 ,后续完善 
void walldie(void) {
    if (snake.body[0].x <= 0 || snake.body[0].x >= WIDTH || snake.body[0].y <= 0 || snake.body[0].x >= HEIGHT)
        printf("YOU DIE!!!");
    return;
}
void bodydie(void) {
    i = 1;
    for (i; i < snake.size; i++) {
        if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y)
            printf("YOU DIE!!!");
        return;
    }
}
//光标跳转
void CursorJump(int x, int y)
{
    COORD pos; //定义光标位置的结构体变量
    pos.X = x; //横坐标
    pos.Y = y; //纵坐标
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //获取控制台句柄
    SetConsoleCursorPosition(handle, pos); //设置光标位置
}
//颜色设置
void color(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); //颜色设置  
}
//随机生成食物
void RandFood()
{
    int i, j;
    do
    {
        //随机生成食物的横纵坐标
        i = rand() % WIDTH;
        j = rand() % HEIGHT;
    } while (face[i][j] != KONG); //确保生成食物的位置为空，若不为空则重新生成
    face[i][j] = FOOD; //将食物位置进行标记
    color(12); //颜色设置为红色
    CursorJump(2 * j, i); //光标跳转到生成的随机位置处
    printf("●"); //打印食物
}
