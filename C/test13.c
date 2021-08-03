//switch语句
#include<stdio.h>

int main()
{
    int day = 0;
    scanf("%d\n", &day);
    switch (day)//必须整形
    {
    case 1:         //必须整形常量
        printf("星期一\n");
        break;
    case 2:
        printf("星期二\n");
        break;
    case 3:
        printf("星期三\n");
        break;
    case 4:
        printf("星期四\n");  
        break; 
    case 5:
        printf("星期五\n");   
        break;
    case 6:
        printf("星期六\n");   
        break;
    case 7:
        printf("星期天\n");              
        break;
    default:
        printf("输入错误\n");
        break;
    }
    printf("===========================================\n");
    int day1 = 0;
    scanf("%d\n", &day1);
    int n = 1;
    switch (day1)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        printf("工作日\n");   
        break;
    case 6:
    case 7:
        printf("休息日\n");              
        break;
    case 8:
        if (n == 1)
        {
            printf("haha\n");
        }
        break;
    default:
        break;

    }
    return 0;
}