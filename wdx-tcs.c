#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <graphics.h> 
#include "tcs.h"

// 全局变量定义
HANDLE hConsoleHandle;

// 函数声明
void initSnake(void);
void daw(void);
void input(void);
void move(void);
void walldie(void);
void bodydie(void);
void speed_change(void);
void clearConsole(void);
void startMenu(void); // 添加一个函数声明
void initWall(void);
int gameRunning = 0;
int main(int argc, char* argv[]) {
    // 初始化控制台句柄
    hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    startMenu(); // 调用开始菜单函数

    initSnake();
    initWall();
    while (gameRunning) 
       
    {
      
        clearConsole(); // 在每次循环开始前清空控制台
        walldie();
        bodydie();

        daw();
       
        input();
        move();
        Sleep(2); // 暂时替代速度调试
        speed_change();
        //system("cls");
    }

    return 0;
}
void initWall(void)
{
    for (size_t i = 0;i <= HEIGHT;i++)
    {
        for (size_t j = 0;j <= WIDTH;j++)
        {
            if (j == WIDTH)
            {
                printf("口");
            }
            else if (i == HEIGHT)
            {
                printf("口");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// 添加一个函数来清空控制台窗口
void clearConsole() {
    COORD screenSize = { 80, 25 }; // 设置控制台窗口的大小
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    DWORD written;
    WORD color = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE; // 将背景颜色设置为黑色

    GetConsoleScreenBufferInfo(hConsoleHandle, &screenBufferInfo); // 获取缓冲区信息
    FillConsoleOutputCharacter(hConsoleHandle, ' ', screenSize.X * screenSize.Y, COORD{ 0, 0 }, &written); // 清空缓冲区内容
    FillConsoleOutputAttribute(hConsoleHandle, color, screenSize.X * screenSize.Y, COORD{ SHRT_MIN, SHRT_MIN }, &written); // 将背景颜色设为黑色
}

// 添加一个函数来显示开始菜单界面
void startMenu(void) {
    // 隐藏光标
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

    // 显示开始菜单
    system("cls"); // 清屏
    printf("  ~欢迎来到贪吃蛇~  \n");
    printf("  w s a d键控制方向     空格键开始游戏  \n");

    // 等待用户输入
    while (!gameRunning) {
        if (_kbhit()) {
            switch (_getch()) {
            case ' ':
                gameRunning = 1; // 用户按下空格键，开始游戏
                break;
            }
        }
    }
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

void walldie(void) {
    if (snake.body[0].x <= 0 || snake.body[0].x >= WIDTH || snake.body[0].y <= 0 || snake.body[0].y >= HEIGHT) 
    {
     

        printf("YOU DIE!!!");
      
        exit(0);

    }
}
void bodydie(void) {
    i = 1;
    for (i; i < snake.size; i++) {
        if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
            printf("YOU DIE!!!");
            exit(0);
        }
    }
}
void speed_change(void) {
    if (1) {
        Sleep(snake.speed);
        snake.speed -= 3;
    }
}
