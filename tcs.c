#包括 <stdio.h>
#包括 <conio.h>
#包括 <windows.h>
#包括 “tcs.h”
#包括<时间.h>
int main（ int argc，char* argv [ ] ） {
    //隐藏光标
    控制台光标信息 cursor_info = {  1 ， 0  } ;
    设置控制台光标信息（获取StdHandle （ STD_OUTPUT_HANDLE ），&cursor_info ）；
    初始化蛇形线（）；
    虽然 （1 ） {
        道( )；
        输入（） ;
        移动（） ;
        //系统（“cls”）；
        //daw（）；
        睡眠（100 ）；
    }
    srand（（无符号整数）时间（NULL ））；//设置随机生成起点
    随机食物（）；//随机生成食物
    返回 0；
}

//蛇模型的初始化，出生位置为场景中心
void initSnake（ void ） {
    蛇。尺寸= 3；
    //snake.body[0]为蛇的头部
    蛇.身体[ 0 ] 。 x = 宽度 / 2 ;
    蛇.身体[ 0 ] .y =高度/ 2 ;

蛇    。身体[ 1 ] .x =宽度/ 2-1 ;
    蛇.身体[ 1 ] .y =高度/ 2 ;

    蛇.身体[ 2 ] 。 x = 宽度 / 2 - 2 ;
    蛇.身体[ 2 ] .y =高度/ 2 ;
}
//画出初始的蛇
虚空daw (虚空)  {
    //COORD为conin库中结构体
    坐标 coord = {  0  } ;
    我 = 0；
    对于 （ i；i<snake.size ； i++ ）
    {
        坐标.X =蛇。身体[ i ] .x ;
        坐标.Y =蛇。身体[ i ] .y ;
        //这串长代码可以改变光标位置
        设置控制台光标位置（获取StdHandle （ STD_OUTPUT_HANDLE ，坐标）；
        如果 （ i == 0 ）
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
            如果 （abs （ dirX ）！= 1 && dirY！= 0 ） {
                目录X = -1 ;
                dirY = 0；
            }
            休息;

        案例 ‘d’：
            如果 （abs （ dirX ）！= 1 && dirY！= 0 ） {
                目录X = 1 ;
                dirY = 0；
            }
            休息;
        案例 ‘w’：
            如果 （ dirX！= 0 && abs （ dirY ）！= 1 ） {
                目录X = 0 ;
                dirY = -1；
            }
            休息;
        案例 's'：
            如果 （ dirX！= 0 && abs （ dirY ）！= 1 ） {
                目录X = 0 ;
                dirY = 1；
            }
            休息;
        }
    }
}
无效移动（无效） {

    //从尾部开始，将前一个位置赋值给后一个，以达到移动目的
    lastx = 蛇.身体[蛇.大小- 1 ] 。 x ;
    lasty = 蛇. body [蛇. size - 1 ] 。 y ;
    i = 蛇。尺寸-1 ；
    对于 （ i；i > 0；i-- ）
    {
        蛇.身体[ i ] 。 x =蛇。身体[ i- 1  ] 。 X ;
        蛇.身体[ i ] .y = 蛇。身体[ i - 1  ] 。 ；​
    }
    蛇.身体[  0  ] 。 x + =dirX;
    蛇.身体[  0  ] 。 y + =方向Y；

}
//未完成的失败机制，
无效walldie (无效)   {
    如果 （蛇。身体[  0  ]。x < = 0 || 蛇。身体[  0  ]。x > = 宽度 || 蛇。身体[  0  ]。y < = 0 || 蛇。身体[  0  ]。x > = 高度）
        printf ( "你死定了！！！" )；
    返回;
}
无效 bodydie （无效）{
    我 = 1；
    对于（ i；i < snake. 大小； i++ ）{
        如果 （蛇。身体[  0  ]。x ==蛇。身体[ i ] 。 x &&蛇。身体[  0  ] 。 y ==蛇。身体[ i ] 。 （​
            printf  (  "你死定了！！！"  )；
        返回;
    }
}
// 光标跳过
void CursorJump  ( int x, int y )
{
    坐标正向；//定义光标位置结构体变量
    正。X =x；//横坐标
    正。Y =y；//纵坐标
    句柄句柄 = GetStdHandle  ( STD_OUTPUT_HANDLE ) ; //获取控制台句柄
    设置光标位置（光标，位置）；//设置光标位置
}
//颜色设置
空颜色（ int c ）
{
    设置控制台文本属性（获取StdHandle （ STD_OUTPUT_HANDLE ），c ）；//颜色设置  
}
//随机生成食物
无效随机食物（）
{
    int i，j；
    做
    {
        // 示例生成食物的横纵坐标
        i = rand （）％宽度；
        j = rand （）％高度；
    }   while   ( face [ i ]  [ j ] != KONG ) ; //确保生成食物的位置为空，若不为空则重新生成
    面[ i ]  [ j ] = 食物；//将食物位置进行标记
    颜色（12）；//颜色设置为红色
    光标跳转（ 2 *j，i ）；//转到储蓄的最佳地点处
    printf  ( “●” )；//打印食物
}
