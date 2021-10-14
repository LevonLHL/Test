#include<stdio.h>

void print1(int arr[3][5],int x,int y)
{
    int i = 0;
    int j = 0;
    for ( i = 0; i < x; i++)
    {
        for ( j = 0; j < y; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
}


void print2(int (*p)[5],int x,int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
    
}


int main()
{
    int arr[3][5] = {
        {1, 2, 3, 4, 5},
        {2, 3, 4, 5, 6},
        {3, 4, 5, 6, 7},
    };
    print1(arr, 3, 5);      //arr    - 数组名    - 数组名就是首元素地址
    printf("=================================================\n");
    print2(arr, 3, 5);
    return 0;
}

/*
int arr[5];                         arr是一个5个元素的整形数组
int *parr1[10];                     parr1是一个数组，数组有10个元素，每个元素的类型是int*，parr1是指针数组
inr (*parr2)[10];                   parr2是一个指针，改指针指向了一个数组，数组有10个元素，每个元素的类型是int，parr2是数组指针
int (*parr3[10])[5];                paee3是一个数组，该数组有10个元素，每个元素是一个数组指针，该数组指针指向的数组有5个元素，每个元素是int（存放数组指针的数组）
*/