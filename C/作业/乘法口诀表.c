//乘法口诀表
#include<stdio.h>

int main()
{
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%dx%d=%-2d   ", i, j, i*j);  //%2d是限制2位，不够用空格补齐（%-2d是在原来的基础上向左对齐）
        }
        printf("\n");
    }
    //进阶乘法口诀表
    int n = 0;
    scanf("%d", &n);
    print_table(n);
    return 0;
}


void print_table(n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d*%d=%-3d ", j, i, i * j);
        }
        printf("\n");
    }
    
}