//while循环
#include<stdio.h>


int main()
{
    int i = 0;
    while (i < 10)
    {
        i++;
        printf("%d ", i);
        if (i == 5)
        {
            break;//终止循环
            continue;//终止本次循环
        }
        
    }
    printf("\n");
    printf("===========================================\n");
    //接收字符
    int ch = getchar();
    putchar(ch);
    printf("%c\n", ch);
    printf("===========================================\n");
    int ch1 = 0;
    while (ch1 = getchar() != EOF)//EOF --end of file文件结束标志(Ctrl+Z)
    {
        putchar(ch1);
    }
    
    return 0;

}