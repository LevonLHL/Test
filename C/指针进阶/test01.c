#include<stdio.h>

//%c打印字符，%s打印字符串
void test(int arr[])
{
    int sz = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", sz);         //  1/2      32位/64位
}

int main()
{
    int arr[10] = {0};
    test(arr);

    char arr1[] = "abcdef";
    char *pc = arr1;
    printf("%s\n", arr1);
    printf("%s\n", pc);

    const char *p = "abcdef";     //常量字符串放指针里存首元素地址
    printf("%c\n", *p);     //所以*p == a
    printf("%s\n", p);

    char *pa = "abcdef";                
    *pa = 'W';              //非法更改，有些比较拉的编译器发现不了
    printf("%c\n", *pa); 
    printf("%s\n", pa);
    return 0;
}