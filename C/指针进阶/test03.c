#include<stdio.h>

//指针数组  是数组，用来存放指针
int main()
{
    /*
    int arr[10] = {0};      //整形数组
    char ch[5] = {0};       //字符数组
    int *parr[4];           //存放整形指针的数组 - 指针数组
    char *pch[5];           //存放字符指针的数组 - 指针数组
    */
    int a = 10,
        b = 20,
        c = 30,
        d = 40;
    int *arr[4] = {&a, &b, &c, &d};
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", *(arr[i]));
    }
    printf("\n============================================\n");
    //指针数组的用法
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 4, 5, 6};
    int arr3[] = {3, 4, 5, 6, 7};
    int *parr[] = {arr1, arr2, arr3};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", *(parr[i] + j));      //打印指针数组
        }
        printf("\n");
    }
    
    return 0;
}