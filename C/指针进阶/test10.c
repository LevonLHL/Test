//指针
#include<stdio.h>

int main()
{
    int a = 10;//4个字节
    double d = 3.14;
    printf("%p\n", &a);
    int* p = &a;//取地址
    double *pd = &d;
    printf("%p\n", p);
    printf("%d\n", pd);
    *p = 20;//* --解引用操作符
    printf("a=%d\n", a);
    printf("===========================================\n");
    char ch = 'w';
    char *pc = &ch;
    *pc = 'a';
    printf("%c\n", ch);
    //计算指针大小(32位的系统4字节，64位的系统8字节)
    printf("%d\n", sizeof(pc));
    printf("===========================================\n");
    printf("%d\n", sizeof(char *));
    printf("%d\n", sizeof(short *));
    printf("%d\n", sizeof(int *));
    printf("%d\n", sizeof(double *));
    return 0;
}