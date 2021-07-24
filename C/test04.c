//循环
#include<stdio.h>
#include<string.h>


int main()
{
    //if循环
    int input = 0;
    printf("你要好好学习吗？(1/0)>:");
    scanf("%d\n", &input);
    if (input == 1)
        printf("好offer\n");
    else
        printf("放牛去吧！\n");
    printf("===========================================\n");
    //while循环
    int line = 0;
    printf("加入比特\n");
    while (line<2000)
    {
        printf("敲一行代码:%d\n",line);
        line++;
    }if (line>=2000)
    {
       printf("好offer\n");
    }
    
    

    return 0;
}