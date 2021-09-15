//不允许创建临时变量求字符串长度
#include<stdio.h>
#include<string.h>

int my_strlen(char* str)
{  
    if (*str != '\0')
    {
        return 1 + my_strlen(str + 1);
    }
    else
    {
        return 0;
    }
    
    
    //计数器法：
    // int count = 0;
    // while (*str != '\0')
    // {
    //     count++;
    //     str++;
    // }
    // return count;

}

int main()
{
    char arr[] = "bit";
    int len = my_strlen(arr);//arr是数组，数组传参，传过去的不是整个数组，而是第一个元素的地址
    printf("len = %d\n", len);
    return 0;
}