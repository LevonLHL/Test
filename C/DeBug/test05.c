#include<stdio.h>

int main()
{
    int i = 0;
    int sum = 0;        //保存最终结果
    int n = 0;
    int ret = 1;        //保存n的阶层
    scanf("%d", &n);        //3    1!+2!+3!
    for ( i = 1; i <= n; i++)
    {
        int j = 0;
        //ret = 1;
        for ( j = 1; j <= i; j++)
        {
            ret *= j;
        }
        sum += ret;
    }
    printf("%d\n", sum);
    return 0;
}