#include<stdio.h>

void Add(int* p)
{
    (*p)++;     //p++的优先级比*p的高，所以要括起来
}

int main()
{
    int num = 0;
    Add(&num);
    printf("num=%d\n", num);
    Add(&num);
    printf("num=%d\n", num);
    Add(&num);
    printf("num=%d", num);
    printf("\n===========================================\n");
    int len = 0;
    len = strlen("a,b,c");
    //1.
    printf("%d\n", len);
    //2.
    printf("%d", strlen("a,b,c"));
    printf("\n===========================================\n");
    printf("%d", printf("%d", printf("%d", 43)));       //printf打印字符的个数
    return 0;
}


//嵌套调用：函数与函数之间的有机组合
//链式访问：把一个函数的返回值作为另外一个函数的参数