#include<stdio.h>

//数组指针   - 指向数组的指针       - 存放数组的地址
int main()
{
    /*
    int *p = NULL;      //p是整形指针  - 指向整形的指针     - 可以存放整形的地址
    char *pc = NULL;    //pc是字符指针   - 指向字符的指针   - 可以存放字符的地址

    int arr[10] = {0};
    //arr - 首元素地址
    //&arr[0] - 首元素地址
    //&arr - 数组的地址
    */
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int (*p)[10] = &arr;        //数组的地址要存起来
    //上面的p就是数组指针,加（）是因为[]的优先级比*高

    char *arr1[5];
    char *(*pa)[5] = &arr1;
    //pa指向的数组的类型是char*
    //（）里的*说明pa是指针
    //pa是指针变量的名字
    //[5]是pa指向的数组是5个元素

    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int(*pa2)[10] = &arr2;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", (*pa2)[i]);       //*pa2 == arr2
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", *(*pa2 + i));
    }
    printf("\n");
    
    int *p2 = arr2;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", *(p2 + i));
    }

    printf("\n=================================================\n");
    int arr3[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i = 0;
    int *p3 = arr3;
    for ( i = 0; i < 10; i++)
    {
        printf("%d ", p3[i]);
        printf("%d ", *(p3 + i));
        printf("%d ", *(arr3 + i));
        printf("%d ", arr[i]);          //arr3[i] == *(arr3+i) == *(p3+i) == p3[i]
    }
    
    return 0;
}