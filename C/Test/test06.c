//计算数组元素个数、强制类型转换、逻辑运算

#include<stdio.h>
#include<string.h>

int main()
{
    int a = 10;
    printf("%d\n", a);
    printf("%d\n", !a);//0-假,非0-真
    //sizeof计算的是变量/类型所占空间的大小，单位是字节
    printf("%d\n", sizeof(a));
    printf("%d\n", sizeof(int));
    int arr[10] = {0};
    printf("%d\n", sizeof(arr));//10 * sizeof(int) = 40
    //数组元素个数 = 数组总大小 / 每个元素大小
    int b = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", b);
    printf("===========================================\n");
    //强制类型转换
    int c = (int)3.14;
    //真 -非0
    //假 -0
    //&& -逻辑与(两个位真，则为真，否者为假)
    int d = 3;
    int e = 5;
    int f = 0;
    int g = d && e;
    int h = d && f;
    printf("%d\n", g);
    printf("%d\n", h);
    //|| -逻辑或（一个为真，就为真，都不为真则为假）
    int i = d || e;
    int j = d || f;
    printf("%d\n", i);
    printf("%d\n", j);
    return 0;
}