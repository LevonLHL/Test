#include<stdio.h>

int main()
{
    
    //NULL -用来初始化指针的，给指针赋值
    int* p = NULL;
    p = 10;
    //int pa = NULL;
    //*pa = 20;             //指针不能访问空值

    //指针运算
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("------------------------------------------------------------\n");
    int sz = sizeof(arr) / sizeof(arr[0]);
    p = arr;
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", *p);
        p = p + 1;
    }
    printf("\n");
    int *pa = &arr[9];
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *pa);
        pa -= 2;
    }
    printf("\n------------------------------------------------------------\n");
    printf("%d\n", &arr[9] - &arr[0]);          //得到数组元素个数
    char ch[5] = {0};
    //printf("%d\n", &arr[9] - &ch[0]);     //err            //指针加减指针只能在同一个空间上进行
    return 0;
}