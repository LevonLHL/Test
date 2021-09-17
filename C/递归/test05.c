//求第n个斐波那契数（不考虑溢出）

//斐波那契数列（前两个数之和等于下一个数）
//1 1 2 3 5 8 13 21 34 55 ...

#include<stdio.h>

//递归方法（可能出现栈溢出）
int count1 = 0;
int Fib1(int n)
{
    if (n == 3)
    {
        count1++;        //count测试第3个斐波那契数的计算次数
    }
    
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return Fib1(n - 1) + Fib1(n - 2);
    }
    
    
}

//循环方法(反而更快)
int Fib2(int n)
{
    int a = 1;
    int b = 1;
    int c = 1;
    while (n > 2)
    {
        c = a + b;
        a = b;
        b = c;
        n--;
    }
    return c;
}

int main()
{
    int n = 0;
    scanf("%d\n", &n);
    int ret1 = Fib1(n);
    int ret2 = Fib2(n);
    printf("ret1 = %d\n", ret1);
    printf("count1 = %d\n", count1);
    printf("ret2 = %d\n", ret2);
    return 0;
}