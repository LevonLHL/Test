#include<stdio.h>
#include<string.h>      //strcpy所需的库函数

int Add(int x,int y)
{
    int z;
    z = x + y;
    return z;
}

int main()
{
    //自定义函数
    int a = 10;
    int b = 20;
    int sum = Add(a, b);
    printf("%d\n", sum);
    printf("=============================================\n");
    //strcpy -->拷贝字符串
    char arr1[] = "bit";
    char arr2[20] = "##########";
    char arr3[20];
    strcpy(arr2, arr1);     //会连同'\0'一起拷贝，所以第五个#开始不打印
    strcpy(arr3, "haohaoxuexi");
    printf("arr1:%s\narr2:%s\narr3:%s\n", arr1, arr2, arr3);
    printf("=============================================\n");
    //memset -->将字符串前面几个元素用其他字符串替代
    char arr[] = "hello word";
    memset(arr, '*', 5);    //'*'也可以是ASCII码值,5为替换的个数
    printf("%s\n", arr);
    return 0;
}