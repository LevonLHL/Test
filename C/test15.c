//缓冲区、‘\n’、‘;’
#include<stdio.h>

int main()
{
    printf("%d\n", '\n');//回车值为10
    printf("===========================================\n");
    int ret = 0;
    char password[20] = {0};
    printf("请输入密码：>");
    scanf("%s", password);//输入密码并存放在password数组中
    //缓冲区还剩余一‘\n’
    //把‘\n’读走
    int ch = 0;
    while ((ch = getchar()) != '\n')
    {
        ;//表示不做任何事
    }
    printf("请确认(Y/N):>");
    ret = getchar();
    if (ret == 'Y')
    {
        printf("确认成功\n");
    }else
    {
        printf("放弃确认\n");
    }
    printf("===========================================\n");
    while ((ch = getchar()) != EOF)
    {
        if (ch < '0' || ch > '9')
        {
            continue;
        }
        putchar(ch);
    }
    
    return 0;
}