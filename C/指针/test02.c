#include<stdio.h>

int main()
{
    int arr1[10] = {0};
    char arr2[10] = {0};
    int *pa = arr1;       //数组名-首元素地址
    for (int i = 0; i < 10; i++)
    {
        *(pa + i) = 1;       //更改的是地址，能更改40位二进制数
    }
    char *pb = arr2;      
    for (int i = 0; i < 10; i++)
    {
        *(pb + i) = 1;       //只能更改10位二进制数
    }
    //野指针
    //指针指向的位置是不可知的
    //1.指针未初始化
    /*
    int a;                  //局部变量不初始化，默认是随机值
    int *p;
    *p = 20;                //同样非法
    */
    //2.指针越界
    /*
    for (int i = 0; i < 12; i++)
    {
        *(p++) = i;         //指针指向范围超出数组范围
    }
    */
    //3.指针指向的空间释放
    /*
    int *p = test();
    *p = 20;
    */
    return 0;
}
/*
int* test()
{
    int a = 10;             //局部变量进大括号创建，出大括号销毁
    return &a;
}
*/