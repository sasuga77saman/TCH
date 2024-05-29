#如果定义_TCS_H
#定义_TCS_H
#定义宽度40
#定义高度30
#define FOOD 2 //标记食物
#define KONG 0 //标记空（什么也没有）
int i = 0 ;
int 分数 = 0；
int lastx = 0；
int lasty = 0 ;
int dirX = 1 , dirY = 0 ;
//蛇体节点坐标结构
結構
{
    int x；
    int y；
身体；
//定义的一条蛇，大小与长度
結構蛇形
{
    结构主体[宽度*高度]；

}蛇;
int 面[宽度] [高度] ; //标记游戏各个位置状态
//食物模块，待完善



//场景，待完善


无效隐藏光标（） ; //隐藏光标
空值颜色（ int c ）；//颜色设置
void CursorJump ( int x, int y )；// 光标跳转
无效随机食物（） ; //随机生成食物
void initSnake （ void ）；//初始化蛇
void daw ( void ) ; //画蛇
无效输入（无效）；//控制模块
无效移动（无效）；//移动模块
无效bodydie  (无效) ; //身体碰撞失败
无效walldie (无效) ; //华尔街日报失败
void lenplus  ( void ) ; //主席
＃万一 #pragma once
