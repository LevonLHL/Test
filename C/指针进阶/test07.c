//函数指针          - 是指向函数的指针
#include<stdio.h>

int Add(int x,int y)
{
    int z = 0;
    z = x + y;
    return z;
}

void Print(char* str)
{
    printf("%s\n", str);
}

int main()
{
    int a = 10;
    int b = 20;
    printf("%d\n", Add(a, b));
    //&函数名 和 函数名 都是函数的地址
    printf("%p\n", &Add);
    printf("%p\n", Add);

    int(*pa)(int, int) = Add;       //要标明类型，可以不用参数
    printf("%d\n", (*pa)(2, 3));    //5

    void (*p)(char *) = Print;
    (*p)("Hello bit");
    printf("==================================================\n");

    printf("%d\n", (pa)(2, 3));                      // '*' 可以省略
    printf("%d\n", (*pa)(2, 3));
    printf("%d\n", (**pa)(2, 3));
    printf("%d\n", (***pa)(2, 3));
    //printf("%d\n", *pa(2, 3));      //err          // ()的优先级比*高
    return 0;
}