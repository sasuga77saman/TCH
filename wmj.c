#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include<graphics.h>//该文件库无法识别的，应该是没有安装eazy-X，删掉这一串就好了
#include "tcs.h"
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")


int main(int argc, char* argv[]) {
    mciSendString("open ./res/she.mp3 alias BGM", 0, 0, 0);
    mciSendString("play BGM repeat", 0, 0, 0);
    SetConsoleTitle("贪吃蛇大作战");

    system("color E0");


    //隐藏光标 
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    initSnake();
    initWall();
    food_sc();
    food1_sc();
    food2_sc();
    food3_sc();
    food5_sc();
    food4_sc();
    //snake.size += 10;//仅为测试bodydie使用
    while (1) {
        eat_food();
        bodydie();
        walldie();
 
        daw();
        input();
        move();
        Sleep(snake.speed);

    }
    system("pause");
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
                dirX = -1 * food5.fx;
                dirY = 0;
            }
            break;

        case 'd':
            if (abs(dirX) != 1 && dirY != 0) {
                dirX = 1 * food5.fx;
                dirY = 0;
            }
            break;
        case 'w':
            if (dirX != 0 && abs(dirY) != 1) {
                dirX = 0;
                dirY = -1 * food5.fx;
            }
            break;
        case 's':
            if (dirX != 0 && abs(dirY) != 1) {
                dirX = 0;
                dirY = 1 * food5.fx;
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

        if (snake.body[0].y >= HEIGHT-1)//超出边界
        {
         snake.body[0].y = 2;
        }

        if (snake.body[0].x >= WIDTH -1)//超出边界
        {
            snake.body[0].x = 2;
        }

    

}

void walldie(void) {
    COORD coord = { 0 };
    if (snake.body[0].x <= 0 || snake.body[0].x >= WIDTH || snake.body[0].y <= 0 || snake.body[0].y >= HEIGHT) {
        coord.X = WIDTH / 2 - 8;
        coord.Y = HEIGHT / 2 - 3;
        //这串长代码可以改变光标位置 
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        printf("YOU DIE!!!");
        coord.X = 0;
        coord.Y = 29;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        printf("Game Over\n");
        sp();
        exit(0);
    }
}

void bodydie(void) {
    COORD coord = { 0 };
    i = 1;
    for (i; i < snake.size; i++) {
        if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
            coord.X = WIDTH / 2 - 8;
            coord.Y = HEIGHT / 2 - 3;
            //这串长代码可以改变光标位置 
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            printf("YOU DIE!!!");
            coord.X = 0;
            coord.Y = 29;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            printf("Game Over\n");
            sp();
            exit(0);
        }
    }
}

void speed_change(void) {
    snake.speed -= 10 * snake.sz;
    snake.sz = abs(snake.sz);
}
void initWall(void)
{
    for (size_t i = 0; i <= HEIGHT - 1; i++)
    {
        for (size_t j = 0; j <= WIDTH; j++)
        {
            if (i == 1)
            {
                printf("-");
            }
            else if (j == WIDTH && i>=1 )
            {
                printf("|");
            }
            else if (i == HEIGHT - 1)
            {
                printf("_");
            }
            else if (j == 0)
            {
                printf("|");
            }
            else {
                printf(" ");

            }
        }
        printf("\n");
    }
}

void sp(void) {
    score = s * 10;
    printf("你的分数为：%d", score);
}



void food_sc(void) {
    COORD coord = { 0 };

    food.x = rand() % WIDTH - 1;
    food.y = rand() % HEIGHT - 1;

    coord.X = food.x;
    coord.Y = food.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("#");
}
void eat_food(void)
{
    if (snake.body[0].x == food.x && snake.body[0].y == food.y) {
        if (food5.fx < 0)
            food5.fx = -food5.fx;
        snake.size++;
        speed_change();
        s++;
        food_sc();
        mciSendString(_T("open D:\\shujujiego\\she\\res\\y2329.mp3 alias bkmusic"), 0, 0, 0);
        mciSendString(_T("play bkmusic"), 0, 0, 0);
    }
    if (snake.body[0].x == food1.x && snake.body[0].y == food1.y) {
        if (food5.fx < 0)
            food5.fx = -food5.fx;
        snake.size++;
        speed_change();
        s++;
        food1_sc();
        mciSendString(_T("close 1music"), 0, 0, 0);
        mciSendString(_T("open D:\\shujujiego\\she\\res\\y2329.mp3 alias bkmusic"), 0, 0, 0);
        mciSendString(_T("play 1music"), 0, 0, 0);
    }

    if (snake.body[0].x == food2.x && snake.body[0].y == food2.y) {
        COORD coord = { 0 };
        if (food5.fx < 0)
            food5.fx = -food5.fx;
        if (snake.size != 1 && snake.size != 2) {
            i = snake.size - 2;
            for (i; i < snake.size; i++) {
                coord.X = snake.body[i].x;
                coord.Y = snake.body[i].y;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                printf(" ");

            }
            snake.size -= 2;
        }
        speed_change();
        s += 5;
        food2_sc();
        mciSendString(_T("close 2music"), 0, 0, 0);
        mciSendString(_T("open D:\\shujujiego\\she\\res\\y2329.mp3 alias bkmusic"), 0, 0, 0);
        mciSendString(_T("play 2music"), 0, 0, 0);
    }

    if (snake.body[0].x == food3.x && snake.body[0].y == food3.y) {
        if (food5.fx < 0)
            food5.fx = -food5.fx;
        COORD coord = { 0 };
        coord.X = snake.body[0].x;
        coord.Y = snake.body[0].y;
        snake.body[0].x -= 5;
        speed_change();
        s++;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        printf(" ");
        food3_sc();
        mciSendString(_T("close 3music"), 0, 0, 0);
        mciSendString(_T("open D:\\shujujiego\\she\\res\\y2329.mp3 alias bkmusic"), 0, 0, 0);
        mciSendString(_T("play 3music"), 0, 0, 0);
    }

    if (snake.body[0].x == food4.x && snake.body[0].y == food4.y) {
        if (food5.fx < 0)
            food5.fx = -food5.fx;
        COORD coord = { 0 };
        coord.X = snake.body[0].x;
        coord.Y = snake.body[0].y;
        snake.body[0].x += 10;
        speed_change();
        s++;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        printf(" ");
        food4_sc();
        mciSendString(_T("close 4music"), 0, 0, 0);
        mciSendString(_T("open D:\\shujujiego\\she\\res\\y2329.mp3 alias bkmusic"), 0, 0, 0);
        mciSendString(_T("play 4music"), 0, 0, 0);
    }
    if (snake.body[0].x == food5.x && snake.body[0].y == food5.y) {
        if (food5.fx < 0)
            snake.size++;
        food5.fx = -food5.fx;
        speed_change();
        s += 5;
        food5_sc();
        mciSendString(_T("close 5music"), 0, 0, 0);
        mciSendString(_T("open D:\\shujujiego\\she\\res\\y2329.mp3 alias bkmusic"), 0, 0, 0);
        mciSendString(_T("play 5music"), 0, 0, 0);
    }





}

void food1_sc(void) {
    COORD coord = { 0 };

    food1.x = rand() % WIDTH - 1;
    food1.y = rand() % HEIGHT - 1;

    coord.X = food1.x;
    coord.Y = food1.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("#");

}
void food2_sc(void) {
    COORD coord = { 0 };

    food2.x = rand() % WIDTH - 8;
    food2.y = rand() % HEIGHT - 8;

    coord.X = food2.x;
    coord.Y = food2.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("$");

}

void food3_sc(void) {
    COORD coord = { 0 };

    food3.x = rand() % WIDTH - 1;
    food3.y = rand() % HEIGHT - 1;

    coord.X = food3.x;
    coord.Y = food3.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("<");

}

void food4_sc(void) {
    COORD coord = { 0 };

    food4.x = rand() % WIDTH - 1;
    food4.y = rand() % HEIGHT - 1;

    coord.X = food4.x;
    coord.Y = food4.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf(">");

}

void food5_sc(void) {
    COORD coord = { 0 };

    food5.x = rand() % WIDTH - 6;
    food5.y = rand() % HEIGHT - 6;

    coord.X = food5.x;
    coord.Y = food5.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("s");

}
