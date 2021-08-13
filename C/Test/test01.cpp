//运算num1+num2
#include <stdio.h>

int main()
{
    //计算2个数的和
    int num1 = 0;
    int num2 = 0;
    int sum = 0;
    //输入数据-使用输入函数scanf
    scanf("%d%d", &num1, &num2);
    sum = num1 + num2;
    printf("sum = %d\n", sum);
    return 0;
}