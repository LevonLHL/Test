//函数、数组、二进制位操作
#include<stdio.h>

int Add(int x,int y)
{
    int z = x + y;
    return z;
}
int main()
{
    //函数
    int num1 = 10;
    int num2 = 20;
    int sum = 0;
    int a = 100;
    int b = 200;
    //sum = num1 + num2
    sum = Add(num1, num2);
    printf("sum=%d\n", sum);
    //sum = a + b
    sum = Add(a, b);
    printf("sum=%d\n", sum);
    //sum = 2 + 3
    sum = Add(2, 3);
    printf("sum=%d\n", sum);
    printf("===========================================\n");
    //数组
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};//定义一个存放10个整数数字的数组
    printf("%d\n", arr[1]);//arr[下标]
    char arr2[20];//定义一个存放20个字符的数组
    float arr3[5];//定义一个存放5个浮点数字的数组
    int i = 0;
    //打印 arr 这个数组
    while (i < 10)
    {
        printf("%d", arr[i]);
        i++;
    }
    printf("\n");
    printf("===========================================\n");
    int c = 5 % 2;//取模（余数）
    printf("%d\n", c);
    int d = 1;
    int e = d << 1;//按二进制位左移1位
    printf("%d\n", e);
    //(二进制)位操作
    //& 按位与
    //| 按位或
    //^ 按位异或==>相同位0，相异为1
    int f = 3;//011
    int g = 5;//101
    int h = f & g;//001(1)
    int j = f | g;//111(7)
    int k = f ^ g;//110（6）
    printf("%d\n", h);
    printf("%d\n", j);
    printf("%d\n", k);
    printf("===========================================\n");
    //~ 按位取反
    int x = 0;
    int y = ~x;
    printf("%d\n", y);
    return 0;
}