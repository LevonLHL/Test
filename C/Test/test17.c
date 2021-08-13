//do while、n!
#include<stdio.h>


int main()
{
    //do while 语句至少执行一次
    int i = 1;
    do
    {
        printf("%d", i);
        i++;
    } while (i<=10);
    printf("\n");
    printf("===========================================\n");
    //n!
    int n = 0;
    int j = 1;
    int ret = 1;
    scanf("%d", &n);
    printf("%d的阶乘：", n);
    do
    {
        ret = ret * j;
        j++;

    } while (j <= n);
    printf("%d\n", ret);
    return 0;
}