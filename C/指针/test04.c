#include<stdio.h>

#define N_VALUES 5

int my_strlen(char* str)
{
    char *start = str;
    char *end = str;
    while (*end != '\0')
    {
        end++;
    }
    return end - start;
}


int  main()
{
    //strlen  - 求字符串长度
    char arr[] = "bit";
    int len = my_strlen(arr);
    printf("%d\n", len);
    printf("------------------------------------------------------------\n");
    float values[N_VALUES];
    float *vp;
    for ( vp = &values[N_VALUES]; vp > &values[0]; )        // C语言语法规定：允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较
    {                                                       //               但是不允许与指向第一个元素之前的那个内存位置的指针进行比较
        *--vp = 0;
    }
    
    return 0;
}