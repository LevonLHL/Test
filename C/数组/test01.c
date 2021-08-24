#include<stdio.h>
#include<string.h>
int main()
{
    // 创建一个数组
    // []里只能放常量
    int arr[10] = {1, 2, 3};    //不完全初始化，剩下的元素默认初始化为0
    char arr2[] = {'a', 98, 'c'};   //98为ASCII码值'b'
    char arr3[] = "abc";        //后有隐藏的\0
    printf("===========================================\n");
    char arr4[] = "abcdef";
    //sizeof 计算arr4所占空间的大小
    printf("%d\n", sizeof(arr4));
    //strlen 求字符串长度-->'\0'之前的字符个数
    printf("%d\n", strlen(arr4));
    printf("===========================================\n");
    printf("%d\n", sizeof(arr2));
    printf("%d\n", sizeof(arr3));
    printf("%d\n", strlen(arr2));   //由于没有'\0'，所以是一个随机值
    printf("%d\n", strlen(arr3));
    return 0;
}