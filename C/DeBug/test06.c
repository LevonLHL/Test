//模拟实现库函数(strcpy)
#include<stdio.h>
#include<string.h>
#include<assert.h>

void my_strcpy1(char* dest, char* src)
{
    while (*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = *src;       // '\0'
}

void my_strcpy2(char* dest, char* src)
{
    while (*dest++ = *src++)
    {
        ;
    }
}

void my_strcpy3(char* dest, const char* src)        //const  - 让src为常量(防止反向拷贝)
{
    assert(dest != NULL);        //断言
    assert(src != NULL);         //防止输入值为空值
    while (*dest++ = *src++)
    {
        ;
    }
}

//最优
char* my_strcpy4(char* dest, const char* src) 
{
    char *ret = dest;
    assert(dest != NULL);        
    assert(src != NULL);
    //把src指向的字符串拷贝到dest指向的空间，包含'\0'字符
    while (*dest++ = *src++)
    {
        ;
    }
    return ret;
}

int main()
{
    //strcpy
    //字符串拷贝
    char arr1[] = "############";
    char arr2[] = "bit";
    my_strcpy1(arr1, arr2);
    printf("%s\n", arr1);

    char arr3[] = "############";
    char arr4[] = "bit";
    my_strcpy2(arr3, arr4);
    printf("%s\n", arr3);

    char arr5[] = "############";
    char arr6[] = "bit";
    my_strcpy3(arr5, arr6);
    printf("%s\n", arr5);

    char arr7[] = "############";
    char arr8[] = "bit";
    printf("%s\n", my_strcpy4(arr7, arr8));
    return 0;
}