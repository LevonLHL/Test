#include<stdio.h>

int main()
{
    char arr1[] = "abcdef";
    char arr2[] = "abcdef";
    char *p1 = "abcdef";        //常量字符串
    char *p2 = "abcdef";
    if (arr1 == arr2)           //比较的是首元素的地址
    {
        printf("hehe\n");
    }
    else
    {
        printf("haha\n");
    }
    
    if (p1 == p2)              //由于都是"abcdef\0",所以在内存中只会开辟一个存"abcdef\0"的空间，反正常量字符串不能更改
    {
        printf("hehe\n");
    }
    else
    {
        printf("haha\n");
    }
    
    return 0;
}