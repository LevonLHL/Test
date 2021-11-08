//Debug  -能调试代码，占用空间大
//Release  -不能调试代码，占用空间小
#include<stdio.h>
#include<stdlib.h>

int main()
{
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", i);
    }
    system("pause");
    printf("\n===============================================\n");
    //栈区的默认使用：先使用高地址处空间，再使用低地址处空间
    //数组随下标的增长，地址由低到高发生变化
    //在不同编译器下，内存布局会有所差异
    int i = 0;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //for循环外部定义i才是C的写法，for循环表达式里定义的i是C++的写法
    for (i = 0; i <= 12; i++)        //数组越界           &i == &arr[10]
    {
        printf("hehe\n");
        arr[i] = 0;
    }
    system("pause");
    //release版本会将内存优化，让i的地址小于arr地址，从而不进入死循环
    //DeBug下i的内存大于arr内存，被放在上面    

    return 0;
}