#include<stdio.h>

int main()
{
    //数组名是首元素地址
    //两个例外：
    //1.sizeof（数组名） --数组名表示整个数组，sizeof（数组名）计算的是整个数组的大小，单位是字节
    //2.&数组名，数组名代表整个数组，&数组名，取出的是整个数组的地址
    int arr[] = {1, 2, 3, 4, 5, 6};
    
    printf("%p\n", arr);
    printf("%p\n", arr + 1);

    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[0] + 1);

    printf("%p\n", &arr);       //数组的地址与数组首元素地址值一样，但意义不一样
    printf("%p\n", &arr + 1);   //相当于加了一个数组长度

    printf("%d\n", *arr);       //第1个元素
    return 0;
}