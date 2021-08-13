#include<stdio.h>
//#define 定义标识符常量
#define MAX 100
//#define 定义宏-带参数
//宏的定义
#define NUM(x,y) (x > y ? x : y)
Num(int x,int y)
{
    if(x > y)
        return x;
    else
        return y;
}

int main()
{
    int a = MAX;
    printf("%d\n", a);
    printf("===========================================\n");
    int b = 20;
    //函数
    int num = Num(a, b);
    printf("num=%d\n", num);
    //宏的方式
    num = NUM(a, b);
    printf("num=%d\n", num);
    return 0;
}