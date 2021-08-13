//循环嵌套、n的阶乘
#include<stdio.h>

int main()
{
    //1n!+2n!+...+10n!
    int n = 0;
    int i = 0;
    int ret = 1;
    int sum = 0;
    for (n = 1; n <= 10; n++)
    {
        ret = 1;    //初始化ret的值
        for ( i = 1; i <= n; i++)  //n的阶乘
        {
            ret = ret * i;
        }
        sum = sum + ret;
    }
    printf("1~10的阶乘和为：%d\n", sum);
    printf("===========================================\n");
    //另一种方法
    n,i,sum = 0;
    ret = 1;
    for ( n = 1; n <= 3; n++)
    {
        ret = ret * n;  //无需初始化
        sum = sum + ret;
    }
    printf("1~3的阶乘和为：%d\n", sum);
    return 0;
}