#include<stdio.h>

int main()
{
    int a = 1;      //初始化
    int b = a;      //赋值
    int c = a;      //a的值还在说明赋过去的只是个副本
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("------------------------------------------------------------\n");
    a = 10;
    int x = 0;
    int y = 20;
    a = x = y + 1;      //连续赋值
    printf("a = %d\n", a);
    printf("x = %d\n", x);
    printf("------------------------------------------------------------\n");
    /*复合赋值符
    a = a + 2;
    a += 2;
    
    a = a >> 1;
    a >>= 1;

    a = a & 1;
    a &= 1;
    */
    //单目操作符
    a = 0;
    printf("a = %d\n", !a);
    if (a)
    {
        printf("呵呵\n");
    }
    if (!a)
    {
        printf("呵呵\n");
    }
    b = -5;
    b = -b;
    printf("b = %d\n", b);
    printf("------------------------------------------------------------\n");
    a = 10;
    int* p = &a;         //取地址操作符
    *p = 20;             //解引用操作符
    a = 10;
    char d = 'r';
    char *p1 = &d;
    int arr[10] = {0};
    //sizeof 计算的变量所占内存空间的大小，单位是字节
    printf("%d\n", sizeof a);          //4
    printf("%d\n", sizeof(int));          //4

    printf("%d\n", sizeof d);          //1
    printf("%d\n", sizeof(char));          //1

    printf("%d\n", sizeof p1);         //8
    printf("%d\n", sizeof(char*));         //8

    printf("%d\n", sizeof arr);        //40
    printf("%d\n", sizeof(int [10]));    //40
    printf("------------------------------------------------------------\n");
    short s = 1;
    a = 10;
    printf("%d\n", sizeof(s = a + 5));      //sizeof里的表达式不会参与运算
    printf("%d\n", s);
    return 0;
}