//计算器二版
#include<stdio.h>


void menu()
{
    printf("************************************\n");
    printf("*****     1.+         2.-       ****\n");
    printf("*****     3.*         4./       ****\n");
    printf("*****          0.exit           ****\n");
    printf("*****          5.^              ****\n");
    printf("************************************\n");
}

int Add(int x, int y)
{
    return x + y;
}

int Sub(int x, int y)
{
    return x - y;
}

int Mul(int x, int y)
{
    return x * y;
}

int Div(int x, int y)
{
    return x / y;
}

int Xor(int x, int y)
{
    return x ^ y;
}

int main()
{
    int input, x, y = 0;
    int (*pfArr[])(int, int) = {0, Add, Sub, Mul, Div, Xor};            //pfArr  是一个函数指针数组，通过下标找到元素找到函数
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        if (input >= 1 && input <= 5)
        {
            printf("请输入两个操作数:>");
            scanf("%d%d", &x, &y);
            printf("%d\n", pfArr[input](x, y));
        } 
        else if (input == 0)
        {
            printf("退出！\n");
        }
        else
        {
            printf("选择错误!\n");
        }
        
    } while (input);
    
    
    return 0;
}