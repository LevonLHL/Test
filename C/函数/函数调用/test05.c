#include<stdio.h>

#include "add.h"

int main()
{
    int a = 10;
    int b = 20;
    int sum = 0;
    //函数调用
    sum = Add(a, b);
    printf("%d\n", sum);
    return 0;
}
