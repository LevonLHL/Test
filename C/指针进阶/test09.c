//函数指针数组
#include<stdio.h>

int Add(int x,int y)
{
    return x + y;
}
int Sub(int x,int y)
{
    return x - y;
}
int Mul(int x,int y)
{
    return x * y;
}
int Div(int x,int y)
{
    return x / y;
}


char* my_strcpy(char* dest, const char* src)
{}



int main()
{
    //指定数组
    int *arr[5];
    //需要一个数组，这个数组可以存放4个函数的地址       - 函数指针数组
    int (*pa)(int, int) = Add;//Sub/Mul/Div
    int (*parr[4])(int, int) = {Add, Sub, Mul, Div};    //函数指针的数组
    int i = 0;
    for ( i = 0; i < 4; i++)
    {
        printf("%d ", parr[i](2, 3));           //5 -1 6 0
    }
    
    //写一个函数指针pf，能够指向my_strcpy
    char *(*pf)(char *, const char *) = my_strcpy;
    //写一个函数指针数组，能够存放4个my_strcpy函数的地址
    char *(*pfArr[4])(char *, const char *);
    return 0;
}