//字符串
#include <string.h>
#include <stdio.h>

int main()
{
    char arr[] = "abc";//数组
    //"abc"--{'a','b','c','\0'}--'\0'是字符串的结束标志,不算字符串内容 
    char arr1[] = {'a', 'b', 'c',0};
    char arr2[] = {'a', 'b', 'c'};
    printf("%s\n", arr);
    printf("%s\n", arr1);
    printf("%s\n", arr2);
    //strlen计算字符串长度
    printf("%d\n", strlen(arr));
    printf("%d\n", strlen(arr2));
    printf("===========================================\n");
    //转义字符--以'\'开头
    printf("c:\test\32\test.c\n");
    printf("c:\\test\\32\\test.c\n");
    printf("%c\n", '\'');
    printf("%d\n", strlen("c:\test\32\test.c"));
    printf("%c\n", '\x61');
    
}